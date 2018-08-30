#ifndef LDPC_ENCODER_H
#define LDPC_ENCODER_H

#include <stdint.h>

#include "enums.h"
#include "ldpc.h"

namespace wimax_ldpc_lib {
    class ldpc_encoder : public ldpc
    {

        private:
            
            uint8_t*        m_P;
            uint8_t*        m_V;
            
        public:
            ldpc_encoder(coderate rate, unsigned int z_factor, unsigned int num_threads);
            ~ldpc_encoder();
            
            void compute_v(uint8_t* infoword, uint8_t* V);
            void encode_data(uint8_t* infoword, uint8_t* codeword);
            
            
    };
}// end namespace wimax_ldpc_lib



#endif // LDPC_ENCODER_H