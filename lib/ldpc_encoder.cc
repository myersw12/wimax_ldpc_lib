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

        m_row_lens = (unsigned int*)malloc(sizeof(unsigned int) * m_row_size);
        for (unsigned int m = 0; m < m_row_size; m++)
        {
            unsigned int len = 0;
            for (unsigned int n = 0; n < m_col_size; n++)
            {
                if (m_checknode_array[m*m_col_size + n] != -1)
                    len++;
            }
            m_row_lens[m] = len;
        }

        // The first parity column has three non-zero blocks: at the first
        // row, at row m_X, and at the last row.  Most rates use shift D at
        // the first and last rows and 0 at row m_X.  Rate 3/4 B is the other
        // way around, so read both shifts from the matrix.
        m_outer_shift = first_parity_shift(0);
        m_middle_shift = first_parity_shift(m_X);
    }

    // Shift of the first parity column's block in block row 'row'
    unsigned int ldpc_encoder::first_parity_shift(unsigned int row)
    {
        unsigned int offset = row * m_z * m_col_size;
        for (unsigned int n = 0; n < m_row_lens[row * m_z]; n++)
        {
            unsigned int index = m_checknode_array[offset + n];
            if (index >= (m_N - m_M) && index < (m_N - m_M) + m_z)
                return index - (m_N - m_M);
        }
        return 0;
    }

    ldpc_encoder::~ldpc_encoder()
    {
        free(m_P);
        free(m_V);
        free(m_row_lens);
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
            unsigned int offset = m * m_col_size;
            for (unsigned int n = 0; n < m_row_lens[m]; n++)
            {
                temp_index = m_checknode_array[offset + n];
                if ((unsigned int)temp_index < (m_N - m_M))
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

        // calculate the first block.  Row m_X sees the first block shifted
        // by m_middle_shift, so undo that shift.
        for (i = 0; i < m_z; i++)
        {
            unsigned int j = (i + m_z - m_middle_shift) % m_z;
            m_P[i] = Y[j] ^ m_P[(m_z*m_X)+j];
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
                codeword[(m_N - m_M) + i] = m_P[i] ^ m_P[(i+m_outer_shift)%m_z];
            }
        }

    }
}// end namespace wimax_ldpc_lib
