#include <stdio.h>

#include "ldpc_encoder.h"

#include <gsl/gsl_linalg.h>


ldpc_encoder::ldpc_encoder(coderate rate, unsigned int z_factor)
{
    
    m_z = z_factor;
    m_N = (m_z / 96.0) * BASE_LDPC_BLOCK_LEN;
    
    
    switch(rate) {
        
        case (HALFRATE):
        {
            m_M = m_N / 2;
            break;
        }
        
        case (TWOTHIRDSA):
        case (TWOTHIRDSB):
        {
            m_M = m_N - ((m_N * 2) / 3);
            break;
        }
        
        case (THREEQUARTERSA):
        case (THREEQUARTERSB):
        {
            m_M = m_N - ((m_N * 3) / 4);
            break;
        }
        
        case (FIVESIXTHS):
        {
            m_M = m_N - ((m_N * 5) / 6);
            break;
        }
        
        default:
        {
            printf("[!]ldpc_encoder - Invalid Coderate: %d\n", rate);
            break;
        }
    }
   
    set_checknode_array(rate, z_factor);
    
    m_M1 = (uint8_t*)malloc(z_factor * (m_N - m_M));
    m_M2 = (uint8_t*)malloc((m_M - z_factor) * (m_N - m_M));
    m_M3 = (uint8_t*)malloc((m_M - z_factor) * z_factor);
    
    m_P1 = (uint8_t*)malloc(m_z);
    m_P2 = (uint8_t*)malloc(m_M - m_z);

    generate_encoding_matrices(m_checknode_array);
    
}

// Destructor
ldpc_encoder::~ldpc_encoder()
{
    free(m_M1);
    free(m_M2);
    free(m_M3);
    free(m_P1);
    free(m_P2);
}

void ldpc_encoder::set_checknode_array(coderate rate, unsigned int z_factor)
{
    
    // get the correct check node array
    switch(z_factor) {
        
        case 24:
        {
            if (rate == HALFRATE)
            {
                m_checknode_array = (uint16_t*) &wimax_576_0_5;
                m_row_size = sizeof(wimax_576_0_5) / sizeof(wimax_576_0_5[0]);
                m_col_size = sizeof(wimax_576_0_5[0]) / sizeof(uint16_t);
            }
            else if (rate == TWOTHIRDSA)
            {
                m_checknode_array = (uint16_t*) &wimax_576_0_66A;
                m_row_size = sizeof(wimax_576_0_66A) / sizeof(wimax_576_0_66A[0]);
                m_col_size = sizeof(wimax_576_0_66A[0]) / sizeof(uint16_t);

            }
            else if (rate == TWOTHIRDSB){
                m_checknode_array = (uint16_t*) &wimax_576_0_66B;
                m_row_size = sizeof(wimax_576_0_66B) / sizeof(wimax_576_0_66B[0]);
                m_col_size = sizeof(wimax_576_0_66B[0]) / sizeof(uint16_t);
            }
            else if (rate == THREEQUARTERSA)
            {
                m_checknode_array = (uint16_t*) &wimax_576_0_75A;
                m_row_size = sizeof(wimax_576_0_75A) / sizeof(wimax_576_0_75A[0]);
                m_col_size = sizeof(wimax_576_0_75A[0]) / sizeof(uint16_t);
            }
            else if (rate == THREEQUARTERSB)
            {
                m_checknode_array = (uint16_t*) &wimax_576_0_75B;
                m_row_size = sizeof(wimax_576_0_75B) / sizeof(wimax_576_0_75B[0]);
                m_col_size = sizeof(wimax_576_0_75B[0]) / sizeof(uint16_t);
            }
            else if (rate == FIVESIXTHS)
            {
                m_checknode_array = (uint16_t*) &wimax_576_0_83;
                m_row_size = sizeof(wimax_576_0_83) / sizeof(wimax_576_0_83);
                m_col_size = sizeof(wimax_576_0_83[0]) / sizeof(uint16_t);
            }
            else
            {
                printf("[!]ldpc_encoder - Invalid Coderate: %d\n", rate);
                return;
            }
            break;
        }
       
        default:
        {
            printf("[!]ldpc_encoder - Invalid Z factor: %d\n", z_factor);
            break;
        }
    }
}

void ldpc_encoder::generate_encoding_matrices(uint16_t* checknodes)
{
    uint16_t temp_index = 0;
     
    double* T = (double*)calloc((m_M - m_z) * (m_M - m_z), sizeof(double));
    uint8_t* A = (uint8_t*)calloc((m_N - m_M) * (m_M - m_z), sizeof(uint8_t));
    uint8_t* B = (uint8_t*)calloc(m_z * (m_M - m_z), sizeof(uint8_t));
    uint8_t* C = (uint8_t*)calloc((m_N - m_M) * m_z, sizeof(uint8_t));
    uint8_t* E = (uint8_t*)calloc((m_N - m_M) * (m_M - m_z), sizeof(uint8_t));
    
    uint8_t* T_inv = (uint8_t*)malloc((m_M - m_z) * (m_M - m_z));
    uint8_t* temp1 = (uint8_t*)malloc(m_z * (m_M - m_z));
    uint8_t* temp2 = (uint8_t*)malloc(m_z * (m_N - m_M));
    
    // Generate A, B, C, and T
    for (unsigned int i = 0; i < m_row_size; i++)
    {
        for (unsigned int j = 0; j < m_col_size; j++)
        {
            temp_index = checknodes[i * m_col_size + j];
            // potentially fill a place in A, B, or T
            if (j < (m_M - m_z))
            {
                // fill a spot in A
                if (temp_index < (m_N - m_M))
                {
                    A[i * (m_N - m_M) + temp_index] = 1;
                }
                // fill a spot in B
                else if (temp_index > (m_N - m_M) && temp_index < ((m_N - m_M) + m_z))
                {
                    B[i * m_z + (temp_index - (m_N - m_M))] = 1;
                }
                // fill a spot in T
                else
                {
                    T[i * (m_M - m_z) + (temp_index - ((m_N - m_M) + m_z))] = 1.0;
                }
            }
            // potentially fill a place in C or E
            else
            {
                if (temp_index < (m_N - m_M))
                {
                    C[i*(m_N - m_M) + temp_index] = 1;
                }
                else if (temp_index > ((m_N - m_M) + m_z))
                {
                    E[i * (m_M - m_z) + (temp_index - ((m_N - m_M) + m_z))] = 1;
                }
            }
        }
    }
   
    // calculate the inverse of T
    invert_T_mod2(T, T_inv, m_M - m_z);
   
    // calculate M1
    mult_matrices_mod2(E, T_inv, temp1, m_z, m_M - m_z, m_M - m_z, m_M - m_z);
    mult_matrices_mod2(temp1, A, temp2, m_z, m_M - m_z, m_M - m_z, m_N - m_M);
    add_matrices_mod2(temp2, C, m_M1, m_z, m_N - m_M);
    
    // calculate M2
    mult_matrices_mod2(T_inv, A, m_M2, m_M - m_z, m_M - m_z, m_M - m_z, m_N - m_M); 

    // calculate M3
    mult_matrices_mod2(T_inv, B, m_M3, m_M - m_z, m_M - m_z, m_M - m_z, m_z);
    
    free(T);
    free(T_inv);
    free(A);
    free(B);
    free(C);
    free(E);
    free(temp1);
    free(temp2);
    
}

// Multiply two matrices together
void ldpc_encoder::mult_matrices_mod2(uint8_t* A, uint8_t* B, uint8_t* C, unsigned int a_rows,
                                 unsigned int a_cols, unsigned int b_rows, unsigned int b_cols)
{
    //#pragma omp parallel for shared(A, B, C)
    for(unsigned int i = 0; i < a_cols; i++)
    {
        for (unsigned int j = 0; j < b_cols; j++)
        {
            unsigned int sum = 0;
            unsigned int idx = i * a_cols;
            
            for(unsigned int k = 0; k < a_cols; k++)
            {
                sum += A[idx + k] * B[k * b_cols + j];
            }
            C[idx + j] = sum % 2;
        }
    }
}

void ldpc_encoder::add_matrices_mod2(uint8_t* A, uint8_t* B, uint8_t* C, unsigned int rows,
                                unsigned int cols)
{
 
    //#pragma omp parallel for shared(A, B, C)
    for(unsigned int i = 0; i < rows; i++)
    {
        for(unsigned int j = 0; j < cols; j++)
        {
            C[i * rows + j] = (A[i*rows + j] + B[i*rows + j]) % 2;
        }
    }
}


void ldpc_encoder::invert_T_mod2(double* T, uint8_t* T_inv, unsigned int dimensions)
{
    int s;
    gsl_matrix* inv;
    
    gsl_matrix_view m = gsl_matrix_view_array(T, dimensions, dimensions);
    
    inv = gsl_matrix_alloc(dimensions, dimensions);
    
    gsl_permutation *p = gsl_permutation_alloc(dimensions);
    
    gsl_linalg_LU_decomp(&m.matrix, p, &s);
    gsl_linalg_LU_invert(&m.matrix, p, inv);
    
    for (unsigned int i = 0; i < dimensions; i++)
    {
        for (unsigned int k = 0; i < dimensions; k++)
        {
            double value = gsl_matrix_get(inv, i, k);
            T_inv[i * dimensions + k] = (uint8_t)value % 2;
        }
    }
    
    gsl_permutation_free(p);
    gsl_matrix_free(inv);
}

void ldpc_encoder::encode_data(uint8_t* infoword, uint8_t* codeword)
{
    
    uint8_t temp1[m_M - m_z];
    uint8_t temp2[m_M - m_z];
    
    mult_matrices_mod2(m_M1, infoword, m_P1, m_z, m_N - m_M, m_N - m_M, 1);
    
    mult_matrices_mod2(m_M2, infoword, temp1, m_M - m_z, m_N - m_M, m_N - m_M, 1);
    mult_matrices_mod2(m_M3, m_P1, temp2, m_M - m_z, m_z, m_z, 1);
    
    add_matrices_mod2(temp1, temp2, m_P2, m_M - m_z, 1);
    
    for (unsigned int i = 0; i < (m_M - m_N); i++)
    {
        codeword[i] = infoword[i];
    }
    
    for (unsigned int j = 0; j < m_z; j++)
    {
        codeword[(m_N - m_M) + j] = m_P1[j];
    }
    
    for (unsigned int k = 0; k < (m_M - m_z); k++)
    {
        codeword[(m_N - m_M) + m_z + k] = m_P2[k];
    }
    
}
    
    