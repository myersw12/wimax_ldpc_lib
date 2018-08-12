#ifndef LDPC_DECODER_H
#define LDPC_DECODER_H

#include <stdint.h>

#include "enums.h"
#include "ldpc.h"


class ldpc_decoder : public ldpc
{

    private:
        unsigned int m_max_iter;
        
        float* m_LMN;
        
    public:
        ldpc_decoder(coderate rate,
                     unsigned int z_factor,
                     unsigned int max_iter,
                     unsigned int num_threads);
        ~ldpc_decoder();
        
        unsigned int compute_syndrome(uint8_t* rx_codeword);
        unsigned int decode(uint8_t* rx_codeword, uint8_t* decoded);
        unsigned int decode(float* rx_codeword, uint8_t* decoded);
};



#endif // LDPC_ENCODER_H