#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <volk/volk.h>
#include <volk/volk_malloc.h>

#include "ldpc_decoder.h"

//#define PRINT_ERRORS

// Right now the flags and values
// for the min sum algorithm modifications
// are here.  These values were found experimentally.
// Only select one at a time or comment both out.
#define NMS
//#define NMS_OFFSET 0.815f

//#define OMS
#define OMS_OFFSET .10

// lanes per layer are padded to a multiple of the SIMD width (8 floats
// for AVX2) so the vectorized loops never fall back to scalar cleanup
#define LANE_MULTIPLE 8

// same idea for the syndrome, which works on bytes (32 per AVX2 vector)
#define SYN_LANE_MULTIPLE 32

namespace wimax_ldpc_lib{
    
    ldpc_decoder::ldpc_decoder() {}
    
    ldpc_decoder::ldpc_decoder(coderate rate,
                            unsigned int z_factor,
                            unsigned int max_iter,
                            unsigned int num_threads,
                            float nms_offset) : ldpc(rate, z_factor, num_threads)
    {
        m_max_iter = max_iter;
        m_nms_offset = nms_offset;

        m_alignment = volk_get_alignment();

        m_row_lens = (unsigned int*)malloc(sizeof(int) * m_row_size);

        unsigned int current_row_len = 0;

        // measure the length of each row in the checknode array
        // doing this ahead of time is better than doing it during 
        // decoding.
        for (unsigned int m = 0; m < m_row_size; m++)
        {
            current_row_len = 0;
            for (unsigned int n = 0; n < m_col_size; n++)
            {
                if (m_checknode_array[m*m_col_size + n] != -1)
                {
                    current_row_len += 1;
                }
            }
            m_row_lens[m] = current_row_len;
        }

        // Describe each layer of z rows by its column blocks and the
        // circulant shift of each block.  Row r of a layer connects to
        // variable node base + (shift + r) % z, so rows in a layer never
        // share a variable node and can be processed together.
        m_num_layers = m_row_size / m_z;
        m_lanes = ((m_z + LANE_MULTIPLE - 1) / LANE_MULTIPLE) * LANE_MULTIPLE;
        m_layer_degs = (unsigned int*)malloc(sizeof(unsigned int) * m_num_layers);
        m_layer_base = (unsigned int*)malloc(sizeof(unsigned int) * m_num_layers * m_col_size);
        m_layer_shift = (unsigned int*)malloc(sizeof(unsigned int) * m_num_layers * m_col_size);

        for (unsigned int b = 0; b < m_num_layers; b++)
        {
            unsigned int first_row = b * m_z;
            m_layer_degs[b] = m_row_lens[first_row];

            for (unsigned int n = 0; n < m_layer_degs[b]; n++)
            {
                unsigned int v = m_checknode_array[first_row*m_col_size + n];
                m_layer_base[b*m_col_size + n] = (v / m_z) * m_z;
                m_layer_shift[b*m_col_size + n] = v % m_z;
            }

            // the layered decode relies on this structure, so verify it
            for (unsigned int r = 0; r < m_z; r++)
            {
                unsigned int m = first_row + r;
                bool ok = (m_row_lens[m] == m_layer_degs[b]);
                for (unsigned int n = 0; ok && n < m_layer_degs[b]; n++)
                {
                    unsigned int expected = m_layer_base[b*m_col_size + n]
                        + (m_layer_shift[b*m_col_size + n] + r) % m_z;
                    ok = ((unsigned int)m_checknode_array[m*m_col_size + n] == expected);
                }
                if (!ok)
                {
                    printf("[!]ldpc_decoder - row %u is not quasi-cyclic\n", m);
                    throw std::exception();
                }
            }
        }

        // A single slice of check node messages is updated in place.
        // Each row's old messages are read into LNM before they are
        // overwritten, so no per-iteration history is needed.
        m_LMN = (float*)volk_malloc(sizeof(float) * m_num_layers * m_col_size * m_lanes, m_alignment);

        // Padding lanes (z..m_lanes) are never copied to or from the
        // codeword. Zeroing them once keeps them at zero for good.
        m_LNM = (float*)volk_malloc(sizeof(float) * m_col_size * m_lanes, m_alignment);
        std::memset(m_LNM, 0, sizeof(float) * m_col_size * m_lanes);
        m_min1 = (float*)volk_malloc(sizeof(float) * m_lanes, m_alignment);
        m_min2 = (float*)volk_malloc(sizeof(float) * m_lanes, m_alignment);
        m_min_idx = (int32_t*)volk_malloc(sizeof(int32_t) * m_lanes, m_alignment);
        m_sign = (int32_t*)volk_malloc(sizeof(int32_t) * m_lanes, m_alignment);

        m_syn_lanes = ((m_z + SYN_LANE_MULTIPLE - 1) / SYN_LANE_MULTIPLE) * SYN_LANE_MULTIPLE;
        m_parity = (int8_t*)volk_malloc(m_syn_lanes, m_alignment);
        m_lane_mask = (int8_t*)volk_malloc(m_syn_lanes, m_alignment);
        for (unsigned int r = 0; r < m_syn_lanes; r++)
            m_lane_mask[r] = (r < m_z) ? -1 : 0;

        // a padded read can run up to m_syn_lanes bytes past the last
        // block; zero it once so those padding lanes never read garbage
        m_doubled = (int8_t*)volk_malloc(2 * m_N + m_syn_lanes, m_alignment);
        std::memset(m_doubled, 0, 2 * m_N + m_syn_lanes);
    }

    ldpc_decoder::~ldpc_decoder()
    {
        volk_free(m_LMN);
        free(m_row_lens);
        free(m_layer_degs);
        free(m_layer_base);
        free(m_layer_shift);
        volk_free(m_LNM);
        volk_free(m_min1);
        volk_free(m_min2);
        volk_free(m_min_idx);
        volk_free(m_sign);
        volk_free(m_parity);
        volk_free(m_lane_mask);
        volk_free(m_doubled);
    }

    // 1 if x is positive (sign bit clear), matching !std::signbit(x),
    // written with integer ops so the compiler can vectorize it
    static inline int32_t is_positive(float x)
    {
        uint32_t bits;
        std::memcpy(&bits, &x, sizeof(bits));
        return (int32_t)((bits >> 31) ^ 1);
    }

    unsigned int ldpc_decoder::compute_syndrome(int8_t* rx_codeword, bool early_exit)
    {
        unsigned int num_errors = 0;
        const unsigned int col_size = m_col_size;
        const unsigned int z = m_z;
        const unsigned int N = m_N;
        const unsigned int syn_lanes = m_syn_lanes;
        const unsigned int num_layers = m_num_layers;
        const unsigned int* layer_degs = m_layer_degs;
        const unsigned int* layer_base = m_layer_base;
        const unsigned int* layer_shift = m_layer_shift;
        int8_t* __restrict parity = m_parity;
        const int8_t* __restrict lane_mask = m_lane_mask;
        int8_t* __restrict doubled = m_doubled;

        // Store each column block twice in a row so the rotated read
        // (s + r) % z for lane r becomes one contiguous span at offset s.
        for (unsigned int c = 0; c < N; c += z)
        {
            std::memcpy(&doubled[2*c], &rx_codeword[c], z);
            std::memcpy(&doubled[2*c + z], &rx_codeword[c], z);
        }

        // Check all z rows of a layer at once, one lane per row.  Padding
        // lanes (z..syn_lanes) are masked out of the count.
        for (unsigned int b = 0; b < num_layers; b++)
        {
            const unsigned int deg = layer_degs[b];
            const unsigned int* base = &layer_base[b*col_size];
            const unsigned int* shift = &layer_shift[b*col_size];

            for (unsigned int r = 0; r < syn_lanes; r++)
                parity[r] = 0;

            for (unsigned int n = 0; n < deg; n++)
            {
                const int8_t* __restrict cw = &doubled[2*base[n] + shift[n]];

                for (unsigned int r = 0; r < syn_lanes; r++)
                    parity[r] ^= cw[r];
            }

            unsigned int layer_errors = 0;
            for (unsigned int r = 0; r < syn_lanes; r++)
                layer_errors += ((parity[r] & lane_mask[r]) != 0);

            if (layer_errors != 0)
            {
                if (early_exit)
                    return 1;
                num_errors += layer_errors;
            }
        }

        return num_errors;
    }

    // this is function takes a bit array and converts it
    // to the input required by the decoder.
    unsigned int ldpc_decoder::decode(int8_t* rx_codeword, int8_t* decoded)
    {
        float soft_codeword[m_N] __attribute__((aligned(32)));

        // convert to soft demod
        for(unsigned int i = 0; i < m_N; i++)
        {
            soft_codeword[i] = rx_codeword[i] * 2.0 - 1.0;
        }
        return this->decode(soft_codeword, decoded);
    }

    // TDMP Decoder for LDPC
    // takes soft demodulated input
    unsigned int ldpc_decoder::decode(float* rx_codeword, int8_t* decoded)
    {
        unsigned int num_errors = 0;
        unsigned int initial_errors = 0;

        const unsigned int col_size = m_col_size;
        const unsigned int z = m_z;
        const unsigned int lanes = m_lanes;
        const unsigned int N = m_N;
        const unsigned int max_iter = m_max_iter;
        const unsigned int num_layers = m_num_layers;
        const unsigned int* layer_degs = m_layer_degs;
        const unsigned int* layer_base = m_layer_base;
        const unsigned int* layer_shift = m_layer_shift;
        float* __restrict LMN = m_LMN;
        float* __restrict LNM = m_LNM;
        float* __restrict min1 = m_min1;
        float* __restrict min2 = m_min2;
        int32_t* __restrict min_idx = m_min_idx;
        int32_t* __restrict sign = m_sign;
        const float nms_offset = m_nms_offset;

        // Check for errors initially, if there are none
        // then exit.
        // Perform hard decision decode
        volk_32f_binary_slicer_8i(decoded, rx_codeword, N);

        // compute the symdrome
        initial_errors = this->compute_syndrome(decoded, true);

        // Exit if there are no inital errors
        if(initial_errors == 0)
        {
            return initial_errors;
        }

        // check node messages start at zero for every codeword
        std::memset(LMN, 0, sizeof(float) * num_layers * col_size * lanes);

        for (unsigned int i = 0; i < max_iter; i++)
        {
            // Each layer is z check node rows that touch disjoint variable
            // nodes, so the rows are processed together with one SIMD lane
            // per row.  This gives the same result as row-by-row TDMP.
            for (unsigned int b = 0; b < num_layers; b++)
            {
                const unsigned int deg = layer_degs[b];
                const unsigned int* base = &layer_base[b*col_size];
                const unsigned int* shift = &layer_shift[b*col_size];
                float* __restrict lmn_layer = &LMN[b*col_size*lanes];

                for (unsigned int r = 0; r < lanes; r++)
                {
                    min1[r] = 10000.0f;
                    min2[r] = 10000.0f;
                    min_idx[r] = 0;
                    sign[r] = 1;
                }

                // Compute LNM messages, the sign, and both minimums
                for (unsigned int n = 0; n < deg; n++)
                {
                    float* __restrict lnm = &LNM[n*lanes];
                    const float* __restrict lmn = &lmn_layer[n*lanes];
                    const float* __restrict rx = &rx_codeword[base[n]];
                    const size_t s = shift[n];
                    const size_t head = z - s;
                    const int32_t n_idx = (int32_t)n;

                    // lane r reads variable node (s + r) % z of the
                    // column block, which is a rotation of contiguous data
                    for (size_t r = 0; r < head; r++)
                        lnm[r] = rx[s + r] - lmn[r];
                    for (size_t r = 0; r < s; r++)
                        lnm[head + r] = rx[r] - lmn[head + r];

                    // branchless: magnitudes are unpredictable after
                    // the first iteration, so avoid mispredictions
                    for (unsigned int r = 0; r < lanes; r++)
                    {
                        float lnm_abs = fabsf(lnm[r]);
                        sign[r] ^= is_positive(lnm[r]);
                        min2[r] = fminf(min2[r], fmaxf(min1[r], lnm_abs));
                        min_idx[r] = (lnm_abs < min1[r]) ? n_idx : min_idx[r];
                        min1[r] = fminf(min1[r], lnm_abs);
                    }
                }

                // compute and apply LMN messages
                for (unsigned int n = 0; n < deg; n++)
                {
                    float* __restrict lnm = &LNM[n*lanes];
                    float* __restrict lmn = &lmn_layer[n*lanes];
                    float* __restrict rx = &rx_codeword[base[n]];
                    const size_t s = shift[n];
                    const size_t head = z - s;
                    const int32_t n_idx = (int32_t)n;

                    for (unsigned int r = 0; r < lanes; r++)
                    {
                        // the min index excludes itself, so it gets the second minimum
                        float minimum = (min_idx[r] == n_idx) ? min2[r] : min1[r];

                        // The option to perform NMS (Normalized Min Sum)
                        // OMS(Offset Min Sum) or just Min Sum is given below.
                        #if defined(NMS) || defined(OMS)
                        #ifdef NMS

                        float scaled = minimum*nms_offset;

                        #else

                        float scaled = std::max(minimum-(float)OMS_OFFSET, 0.0f);

                        #endif

                        #else

                        float scaled = minimum;

                        #endif

                        scaled = (sign[r] ^ is_positive(lnm[r])) ? -scaled : scaled;

                        lmn[r] = scaled;
                        lnm[r] += scaled;
                    }

                    for (size_t r = 0; r < head; r++)
                        rx[s + r] = lnm[r];
                    for (size_t r = 0; r < s; r++)
                        rx[r] = lnm[head + r];
                }
            }

            volk_32f_binary_slicer_8i(decoded, rx_codeword, N);

            // compute the symdrome
            num_errors = this->compute_syndrome(decoded, true);

            // Exit if there are no more errors
            if(num_errors == 0)
            {
                return num_errors;
            }
        }

        #ifdef PRINT_ERRORS
        printf("Initial Errors: %d\n", initial_errors);
        printf("Final Errors: %d\n", num_errors);
        #endif

        // return the number of errors remaining after
        // the maximum number of iterations is performed.
        return num_errors;
    }
} // end namespace wimax_ldpc_lib
