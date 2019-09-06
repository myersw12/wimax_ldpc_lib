#include <stdio.h>
#include <cmath>
#include <cstring>

#include "ldpc_encoder.h"

namespace wimax_ldpc_lib {
    
    ldpc_encoder::ldpc_encoder(coderate rate,
                            unsigned int z_factor,
                            unsigned int num_threads) : ldpc(rate,
                                                                z_factor,
                                                                num_threads)
    {
        m_P = (uint8_t*)calloc(m_M, sizeof(uint8_t));
        m_V = (uint8_t*)calloc(m_M, sizeof(uint8_t));
    }

    // Destructor
    ldpc_encoder::~ldpc_encoder()
    {
        free(m_P);
        free(m_V);
    }

    // For information on the LDPC encoding algorithm used here
    // please see the paper "Efficient Encoding for Dual-Diagonal Structured LDPC
    // Codes Based on Parity Bit Prediction and Correction" by Lin, Wei, and Ku
    void ldpc_encoder::compute_v(uint8_t* infoword)
    {
        int16_t temp_index = 0;
        uint8_t value = 0;

        #pragma omp parallel for private(temp_index, value) num_threads(m_num_threads)
        for (unsigned int m = 0; m < m_row_size; m++)
        {
            value = 0;
            for (unsigned int n = 0; n < m_col_size; n++)
            {
                temp_index = m_checknode_array[m*m_col_size + n];
                if (temp_index != -1 && (uint16_t)temp_index < (m_N - m_M))
                {
                    value ^= 1 && infoword[temp_index];
                }
            }
            m_V[m] = value;
        }
    }

    void ldpc_encoder::encode_data(uint8_t* infoword, uint8_t* codeword)
    {
        unsigned int i;

        uint8_t Y[m_z];
        memset(m_P, 0, m_z); 
        memset(m_V, 0, m_M);

        compute_v(infoword);

        // calculate the last subblock
        for (i = m_M-1; i > m_M-1-m_z; i--)
        {
            m_P[i] = m_V[i] ^ m_P[m_M-1-i];
        }

        // forward subsitution
        for (i = m_z; i < (m_X+1)*m_z; i++)
        {
            m_P[i] = m_V[i-m_z] ^ m_P[i-m_z];
        }

        // backwards substitution
        for (i = m_M-1-m_z; i > (((m_X+1)*m_z)-1); i--)
        {
            m_P[i] = m_V[i] ^ m_P[i+m_z];
        }

        // calculate Y
        for (i = m_X*m_z; i < (m_X*m_z)+m_z; i++)
        {
            Y[i-(m_X*m_z)] = m_V[i] ^ m_P[m_z+i];
        }

        // calculate the first block
        for (i = 0; i < m_z; i++)
        {
            m_P[i] = Y[i] ^ m_P[(m_z*m_X)+i];
        }

        memcpy(codeword, infoword, m_N - m_M);

        // apply F to the rest of the parity bits
        for (i = 0; i < m_M; i++)
        {
            if(i < m_z)
            {
                codeword[(m_N - m_M) + i] = m_P[i];
            }
            else
            {
                codeword[(m_N - m_M) + i] = m_P[i] ^ m_P[(i+m_D)%m_z];
            }
        }

    }
}// end namespace wimax_ldpc_lib
