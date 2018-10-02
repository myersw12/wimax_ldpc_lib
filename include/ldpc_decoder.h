#ifndef LDPC_DECODER_H
#define LDPC_DECODER_H

#include <stdint.h>

#include "enums.h"
#include "ldpc.h"

namespace wimax_ldpc_lib {
    
    class ldpc_decoder : public ldpc
    {

        private:
            unsigned int m_max_iter;
            
            float* m_LMN;
            //float* LNM;
            
            unsigned int* m_row_lens;
            
            unsigned int m_alignment;
            
        public:
            ldpc_decoder(coderate rate,
                        unsigned int z_factor,
                        unsigned int max_iter,
                        unsigned int num_threads);
            ~ldpc_decoder();
            
            unsigned int compute_syndrome(uint8_t* rx_codeword, bool exit_early);
            unsigned int decode(uint8_t* rx_codeword, uint8_t* decoded);
            unsigned int decode(float* rx_codeword, uint8_t* decoded);
    };
}// end namespace wimax_ldpc_lib



#endif // LDPC_ENCODER_H