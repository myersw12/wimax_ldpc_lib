#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <cstring>

#include "ldpc_decoder.h"

//#define PRINT_ERRORS

namespace wimax_ldpc_lib{

    ldpc_decoder::ldpc_decoder(coderate rate,
                            unsigned int z_factor,
                            unsigned int max_iter,
                            unsigned int num_threads) : ldpc(rate, z_factor, num_threads)
    {
        m_max_iter = max_iter;
        
        m_LMN = (float*)aligned_alloc(sizeof(float), 
                                      sizeof(float) * m_max_iter * m_row_size * m_col_size);
        
        std::memset(m_LMN, 0, sizeof(float) * m_max_iter * m_row_size * m_col_size); 
        
    }

    ldpc_decoder::~ldpc_decoder()
    {
        free(m_LMN);
    }

    unsigned int ldpc_decoder::compute_syndrome(uint8_t* rx_codeword, bool early_exit)
    {
        unsigned int num_errors = 0;
        
        for (unsigned int i = 0; i < m_row_size; i++)
        {
            uint8_t xorsum = 0;
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
    unsigned int ldpc_decoder::decode(uint8_t* rx_codeword, uint8_t* decoded)
    {
        
        float soft_codeword[m_N];
        
        // convert to soft demod
        for(unsigned int i = 0; i < m_N; i++)
        {
            soft_codeword[i] = rx_codeword[i] * -2.0 + 1.0;
        }
        return this->decode(soft_codeword, decoded);
        
    }
    
    // TDMP Decoder for LDPC
    // takes soft demodulated input
    unsigned int ldpc_decoder::decode(float* rx_codeword, uint8_t* decoded)
    {
        unsigned int num_errors = 0;
        unsigned int initial_errors = 0;
        
        float LNM[m_col_size];
        
        // Check for errors initially, if there are none
        // then exit.
        // Perform hard decision decode
        #pragma omp parallel for num_threads(m_num_threads)
        for (unsigned int n = 0; n < m_N; n++)
        {
            if(rx_codeword[n] <= 0)
                decoded[n] = 1;
            else
                decoded[n] = 0;
        }
        
        // compute the symdrome
        initial_errors = this->compute_syndrome(decoded, true);
        
        // Exit if there are no inital errors
        if(initial_errors == 0)
            return initial_errors;
        
        for (unsigned int i = 0; i < m_max_iter; i++)
        {
            #pragma omp parallel for private(LNM) num_threads(m_num_threads)
            for (unsigned int m = 0; m < m_row_size; m++)
            {
                unsigned int current_row_len = 0;
                int16_t temp_index;
            
                float minimum = 10000.0;
                float sign = 1.0;
                
                unsigned int cn_offset = m*m_col_size;
                unsigned int lmn_offset;
                
                // Compute LNM Message
                if (i == 0){
                    for (unsigned int n = 0; n < m_col_size; n++)
                    {
                        temp_index = m_checknode_array[cn_offset + n];
                        if (temp_index != -1){
                            LNM[n] = rx_codeword[temp_index];
                            current_row_len += 1;
                        }
                    }
                } else
                {
                    lmn_offset = m_col_size*(m + (i-1)*m_row_size);
                    
                    for (unsigned int n = 0; n < m_col_size; n++)
                    {
                        temp_index = m_checknode_array[cn_offset + n];
                        if (temp_index != -1){
                            LNM[n] = 
                                rx_codeword[temp_index] 
                                - m_LMN[n + lmn_offset];
                            current_row_len += 1;
                        }
                    }
                }
                
                lmn_offset = m_col_size*(m + i*m_row_size);
                // Compute LMN Message
                for (unsigned int n = 0; n < current_row_len; n++)
                {
                    temp_index = m_checknode_array[cn_offset + n];
                    
                    minimum = 10000.0;
                    sign = 1.0;
                    
                    
                    for (unsigned int d = 0; d < current_row_len; d++)
                    {
                        if (d != n)
                        {
                            sign *= LNM[d];
                            
                            if (fabs(LNM[d]) < minimum)
                                minimum = fabs(LNM[d]);
                        }
                    }
                    
                    // update codeword
                    if (sign > 0)
                    {
                        m_LMN[n + lmn_offset] = minimum;
                        rx_codeword[temp_index] = LNM[n] + minimum;
                    }
                    else
                    {
                        m_LMN[n + lmn_offset] = -minimum;
                        rx_codeword[temp_index] = LNM[n] - minimum;
                    }
                }
            }
            
            // Perform hard decision decode
            #pragma omp parallel for num_threads(m_num_threads)
            for (unsigned int n = 0; n < m_N; n++)
            {
                if(rx_codeword[n] <= 0)
                    decoded[n] = 1;
                else
                    decoded[n] = 0;
            }
            
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