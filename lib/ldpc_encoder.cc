#include <stdio.h>
#include <cmath>
#include <cstring>

#include "ldpc_encoder.h"

#include <gsl/gsl_linalg.h>


ldpc_encoder::ldpc_encoder(coderate rate,
                           unsigned int z_factor,
                           unsigned int num_threads) : ldpc(rate,
                                                            z_factor,
                                                            num_threads)
{
    
    m_M1 = (uint8_t*)calloc(z_factor * (m_N - m_M), sizeof(uint8_t));
    m_M2 = (uint8_t*)calloc((m_M - m_z) * (m_N - m_M), sizeof(uint8_t));
    m_M3 = (uint8_t*)calloc((m_M - m_z) * m_z, sizeof(uint8_t));
    
    m_P1 = (uint8_t*)calloc(m_z, sizeof(uint8_t));
    m_P2 = (uint8_t*)calloc(m_M - m_z, sizeof(uint8_t));
    
    m_encode_temp1 = (uint8_t*)calloc(m_M - m_z, sizeof(uint8_t));
    m_encode_temp2 = (uint8_t*)calloc(m_M - m_z, sizeof(uint8_t));

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
    
    free(m_encode_temp1);
    free(m_encode_temp2);
}

void ldpc_encoder::generate_encoding_matrices(int16_t* checknodes)
{
    int16_t temp_index = 0;
    
    unsigned int a_rows = m_M - m_z;
    unsigned int a_cols = m_N - m_M;
    unsigned int b_rows = m_M - m_z;
    unsigned int b_cols = m_z;
    unsigned int c_rows = m_z;
    unsigned int c_cols = m_N - m_M;
    unsigned int e_rows = m_z;
    unsigned int e_cols = m_M - m_z;
    unsigned int t_rows = m_M - m_z;
    unsigned int t_cols = m_M - m_z;
    
     
    double* T = (double*)calloc(t_rows * t_cols, sizeof(double));
    uint8_t* A = (uint8_t*)calloc(a_rows * a_cols, sizeof(uint8_t));
    uint8_t* B = (uint8_t*)calloc(b_rows * b_cols, sizeof(uint8_t));
    uint8_t* C = (uint8_t*)calloc(c_rows * c_cols, sizeof(uint8_t));
    uint8_t* E = (uint8_t*)calloc(e_rows * e_cols, sizeof(uint8_t));
    uint8_t* T_inv = (uint8_t*)calloc(a_rows * a_rows, sizeof(uint8_t));
    uint8_t* temp1 = (uint8_t*)calloc(m_z * (m_M - m_z), sizeof(uint8_t));
    uint8_t* temp2 = (uint8_t*)calloc(m_z * (m_N - m_M), sizeof(uint8_t));
    
    int a_end = m_N - m_M;
    int b_end = a_end + m_z;
    
    unsigned int vert_split = m_M - m_z;
    
    // Generate A, B, C, and T
    for (unsigned int i = 0; i < m_row_size; i++)
    {
        for (unsigned int j = 0; j < m_col_size; j++)
        {
            temp_index = checknodes[i * m_col_size + j];
            
            if(temp_index != -1)
            {
                // potentially fill a place in A, B, or T
                if (i < vert_split)
                {
                    // fill a spot in A
                    if (temp_index < a_end)
                    {
                        A[i * a_end + temp_index] = 1;
                    }
                    // fill a spot in B
                    else if (temp_index >= a_end && temp_index < b_end)
                    {
                        B[i * b_cols + (temp_index - a_end)] = 1;
                    }
                    // fill a spot in T
                    else if (temp_index >= b_end)
                    {
                        T[i * t_cols + (temp_index - b_end)] = 1.0;
                    }
                }
                // potentially fill a place in C or E
                else
                {
                    if (temp_index < a_end)
                    {
                        C[(i - vert_split) * a_end + temp_index] = 1;
                    }
                    else if (temp_index >= b_end)
                    {
                        E[(i - vert_split) * e_cols + (temp_index - b_end)] = 1;
                    }
                }
            }
        }
    }
    
    // calculate the inverse of T
    invert_T_mod2(T, T_inv, a_rows);
    
    // calculate M1
    mult_matrices_mod2(E, T_inv, temp1, e_rows, e_cols , t_rows, t_cols);
    mult_matrices_mod2(temp1, A, temp2, c_rows, t_cols, a_rows, a_cols);
    add_matrices_mod2(temp2, C, m_M1, c_rows, c_cols);
   
    // calculate M2
    mult_matrices_mod2(T_inv, A, m_M2, t_rows, t_cols, a_rows, a_cols); 
    
    // calculate M3
    mult_matrices_mod2(T_inv, B, m_M3, t_rows, t_cols, b_rows, b_cols);
    
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
    #pragma omp parallel for schedule(dynamic, a_rows/(m_num_threads*4)) shared(A, B, C) num_threads(m_num_threads)
    for(unsigned int i = 0; i < a_rows; i++)
    {
        for (unsigned int j = 0; j < b_cols; j++)
        {
            unsigned int idx = i * a_cols;
            uint8_t value = 0;
            
            for(unsigned int k = 0; k < a_cols; k++)
            {   
                value ^= A[idx + k] && B[k * b_cols + j];
            }
            C[i * b_cols + j] = value;
        }
    }
}

void ldpc_encoder::add_matrices_mod2(uint8_t* A, uint8_t* B, uint8_t* C, unsigned int rows,
                                unsigned int cols)
{
    for(unsigned int i = 0; i < rows * cols; i++)
    {
        C[i] = (A[i] + B[i]) & 0x01;
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
        for (unsigned int k = 0; k < dimensions; k++)
        {
            double value = gsl_matrix_get(inv, i, k);
            T_inv[i * dimensions + k] = (uint8_t)abs(fmod((int)value, 2));
        }
    }
    
    gsl_permutation_free(p);
    gsl_matrix_free(inv);
}

void ldpc_encoder::encode_data(uint8_t* infoword, uint8_t* codeword)
{
    mult_matrices_mod2(m_M1, infoword, m_P1, m_z, m_N - m_M, m_N - m_M, 1);
    mult_matrices_mod2(m_M2, infoword, m_encode_temp1, m_M - m_z, m_N - m_M, m_N - m_M, 1);
    mult_matrices_mod2(m_M3, m_P1, m_encode_temp2, m_M - m_z, m_z, m_z, 1);
    
    add_matrices_mod2(m_encode_temp1, m_encode_temp2, m_P2, m_M - m_z, 1);
    
    memcpy(codeword, infoword, m_N - m_M);
    memcpy(codeword + (m_N - m_M), m_P1, m_z);
    memcpy(codeword + (m_N - m_M) + m_z, m_P2, m_M - m_z);
   
}
    
    