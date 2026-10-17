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

        // A single slice of check node messages is updated in place.
        // Each row's old messages are read into LNM before they are
        // overwritten, so no per-iteration history is needed.
        m_LMN = (float*)volk_malloc(sizeof(float) * m_row_size * m_col_size, m_alignment);

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
    }

    ldpc_decoder::~ldpc_decoder()
    {
        volk_free(m_LMN);
        free(m_row_lens);
    }

    unsigned int ldpc_decoder::compute_syndrome(int8_t* rx_codeword, bool early_exit)
    {
        unsigned int num_errors = 0;
        const unsigned int row_size = m_row_size;
        const unsigned int col_size = m_col_size;
        const unsigned int* row_lens = m_row_lens;
        const int16_t* checknode_array = m_checknode_array;

        for (unsigned int i = 0; i < row_size; i++)
        {
            int8_t xorsum = 0;
            const int16_t* cn_row = &checknode_array[i*col_size];
            unsigned int row_len = row_lens[i];

            for (unsigned int k = 0; k < row_len; k++)
            {
                xorsum ^= rx_codeword[cn_row[k]];
            }

            if (xorsum != 0)
            {
                if (early_exit)
                    return 1;
                num_errors++;
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
        const unsigned int row_size = m_row_size;
        const unsigned int N = m_N;
        const unsigned int max_iter = m_max_iter;
        const unsigned int* row_lens = m_row_lens;
        const int16_t* checknode_array = m_checknode_array;
        float* LMN = m_LMN;
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
        std::memset(LMN, 0, sizeof(float) * row_size * col_size);

        for (unsigned int i = 0; i < max_iter; i++)
        {
            for (unsigned int m = 0; m < row_size; m++)
            {
                // declaring this local to the loop helps
                unsigned int row_len = row_lens[m];
                float LNM[row_len];

                bool sign = true;

                float first_minimum = 10000.0f;
                float second_minimum = 10000.0f;
                float minimum;
                float iter_sign;
                float lnm_abs;

                unsigned int m_col = m * col_size;
                const int16_t* cn_row = &checknode_array[m_col];
                float* lmn_row = &LMN[m_col];

                unsigned int first_min_index = 0;

                // Compute LNM Message

                for (unsigned int n = 0; n < row_len; n++)
                {

                    LNM[n] = rx_codeword[cn_row[n]]
                            - lmn_row[n];

                    // calculate the sign bit here so that
                    // the operation in the next loop is simpler
                    sign ^= !std::signbit(LNM[n]);

                    // track the two smallest magnitudes in one pass so
                    // the row never has to be rescanned
                    // branchless: magnitudes are unpredictable after
                    // the first iteration, so avoid mispredictions
                    lnm_abs = fabsf(LNM[n]);
                    second_minimum = fminf(second_minimum, fmaxf(first_minimum, lnm_abs));
                    first_min_index = (lnm_abs < first_minimum) ? n : first_min_index;
                    first_minimum = fminf(first_minimum, lnm_abs);
                }

                // compute and apply LNM message for starting indices

                for (unsigned int n = 0; n < row_len; n++)
                {

                    iter_sign = (sign ^ !std::signbit(LNM[n])) * -2 + 1;

                    // the min index excludes itself, so it gets the second minimum
                    minimum = (n == first_min_index) ? second_minimum : first_minimum;

                    // The option to perform NMS (Normalized Min Sum)
                    // OMS(Offset Min Sum) or just Min Sum is given below.
                    #if defined(NMS) || defined(OMS)
                    #ifdef NMS

                    float scaled = iter_sign * (minimum*nms_offset);

                    #else

                    float scaled = iter_sign * std::max(minimum-(float)OMS_OFFSET, 0.0f);

                    #endif

                    #else

                    float scaled = iter_sign * minimum;

                    #endif

                    lmn_row[n] = scaled;
                    rx_codeword[cn_row[n]] = LNM[n] + scaled;
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
