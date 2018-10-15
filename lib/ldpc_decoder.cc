#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <cstring>

#include <volk/volk.h>
#include <volk/volk_malloc.h>

#include "ldpc_decoder.h"

//#define PRINT_ERRORS

namespace wimax_ldpc_lib{
    
    ldpc_decoder::ldpc_decoder() {}
    
    ldpc_decoder::ldpc_decoder(coderate rate,
                            unsigned int z_factor,
                            unsigned int max_iter,
                            unsigned int num_threads) : ldpc(rate, z_factor, num_threads)
    {
        m_max_iter = max_iter;
        
        m_alignment = volk_get_alignment();
        
        m_LMN = (float*)volk_malloc(sizeof(float) * (m_max_iter+1) * m_row_size * m_col_size, m_alignment);
        
        std::memset(m_LMN, 0, sizeof(float) * m_max_iter * m_row_size * m_col_size); 
        
        m_row_lens = (unsigned int*)malloc(sizeof(int) * m_row_size);
        
        
        unsigned int current_row_len = 0;
        
        for (unsigned int m = 0; m < m_row_size; m++)
        {
            current_row_len = 0;
            for (unsigned int n = 0; n < m_col_size; n++)
            {
                if (m_checknode_array[m*m_col_size + n] != -1){
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
        
        for (unsigned int i = 0; i < m_row_size; i++)
        {
            int8_t xorsum = 0;
            int16_t temp_index;
            unsigned int offset = i*m_col_size;
            
            for (unsigned int k = 0; k < m_col_size; k++)
            {
                temp_index = m_checknode_array[offset + k];
                if (temp_index != -1)
                    xorsum ^= rx_codeword[temp_index];
            }
           
            // if we just want to know if there are errors or
            // not, then return when the first error is found
            if (xorsum != 0){
                if (early_exit){
                    num_errors = 1;
                    i = m_row_size;
                }
                    
                else
                    num_errors += 1;
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
        
        // Check for errors initially, if there are none
        // then exit.
        // Perform hard decision decode
        volk_32f_binary_slicer_8i(decoded, rx_codeword, m_N);
        
        // compute the symdrome
        initial_errors = this->compute_syndrome(decoded, true);
        
        // Exit if there are no inital errors
        if(initial_errors == 0)
            return initial_errors;
        
        for (unsigned int i = 1; i < m_max_iter+1; i++)
        {
            for (unsigned int m = 0; m < m_row_size; m++)
            {
                
                float LNM[m_row_lens[m]];
                    
                bool sign = true;
                
                float first_minimum = 10000.0;
                float minimum;
                float iter_sign;
                float lnm_abs;
                
                unsigned int cn_offset = m*m_col_size;
                unsigned int lmn_offset;
                
                unsigned int first_min_index = 0;
                
                // Compute LNM Message
               
                lmn_offset = m_col_size*(m + (i-1)*m_row_size);
                
                for (unsigned int n = 0; n < m_row_lens[m]; n++)
                {
                    
                    LNM[n] = rx_codeword[m_checknode_array[cn_offset + n]] 
                            - m_LMN[n + lmn_offset];
                    
                    sign ^= !std::signbit(LNM[n]);
                            
                    lnm_abs = fabs(LNM[n]);
                    if (lnm_abs < first_minimum){
                        first_minimum = lnm_abs;
                        first_min_index = n;
                    }
                    
                }
                
                lmn_offset = m_col_size*(m + i*m_row_size);
                
                // compute and apply LNM message for starting indices
                
                for (unsigned int n = 0; n < m_row_lens[m]; n++)
                {
                    
                    iter_sign = (sign ^ !std::signbit(LNM[n])) * -2 + 1;
                    
                    if (n == first_min_index)
                    {
                        // Compute and apply LNM message for min index
                        minimum = 10000.0;

                        for (unsigned int d = 0; d < m_row_lens[m]; d++)
                        {
                            if (d != first_min_index)
                            {
                                lnm_abs = fabs(LNM[d]);
                                if (lnm_abs < minimum)
                                    minimum = lnm_abs;
                            }
                        }
                    }
                    else
                    {
                        minimum = first_minimum;
                    }
                    
                    m_LMN[n + lmn_offset] = iter_sign * minimum;
                    
                    rx_codeword[m_checknode_array[cn_offset + n]] = LNM[n] + iter_sign * minimum ;
                    
                }
                
            }
            
            volk_32f_binary_slicer_8i(decoded, rx_codeword, m_N);

            // compute the symdrome
            num_errors = this->compute_syndrome(decoded, true);
            
            // Exit if there are no more errors
            if(num_errors == 0)
                return num_errors;
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