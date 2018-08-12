#ifndef LDPC_ENCODER_H
#define LDPC_ENCODER_H

#include <stdint.h>

#include "enums.h"
#include "ldpc.h"


class ldpc_encoder : public ldpc
{

    private:
        
        uint8_t*        m_M1;
        uint8_t*        m_M2;
        uint8_t*        m_M3;
        
        uint8_t*        m_P1;
        uint8_t*        m_P2;
        
        uint8_t*        m_encode_temp1;
        uint8_t*        m_encode_temp2;
        
        void invert_T_mod2(double* T, uint8_t* T_inv, unsigned int dimensions);
        void add_matrices_mod2(uint8_t* A, uint8_t* B, uint8_t* C, unsigned int rows,
                               unsigned int cols);
        void mult_matrices_mod2(uint8_t* A, uint8_t* B, uint8_t* C, unsigned int a_rows,
                                unsigned int a_cols, unsigned int b_rows,
                                unsigned int b_cols);
        void generate_encoding_matrices(int16_t* checknodes);

    public:
        ldpc_encoder(coderate rate, unsigned int z_factor, unsigned int num_threads);
        ~ldpc_encoder();
        
        void encode_data(uint8_t* infoword, uint8_t* codeword);
        
};



#endif // LDPC_ENCODER_H