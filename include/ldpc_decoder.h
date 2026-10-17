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

            unsigned int* m_row_lens;

            // QC layer description: each layer is z consecutive rows that
            // share a column-block pattern, so all z rows run in SIMD lanes
            unsigned int m_num_layers;
            unsigned int m_lanes;
            unsigned int* m_layer_degs;
            unsigned int* m_layer_base;
            unsigned int* m_layer_shift;

            // per-layer scratch, one entry per lane (row in the layer)
            float* m_LNM;
            float* m_min1;
            float* m_min2;
            int32_t* m_min_idx;
            int32_t* m_sign;

            unsigned int m_alignment;

            float m_nms_offset;

        public:
            ldpc_decoder();
            ldpc_decoder(coderate rate,
                        unsigned int z_factor,
                        unsigned int max_iter,
                        unsigned int num_threads,
                        float nms_offset = 0.815f);
            ~ldpc_decoder();
            
            unsigned int compute_syndrome(int8_t* rx_codeword, bool exit_early);
            unsigned int decode(int8_t* rx_codeword, int8_t* decoded);
            unsigned int decode(float* rx_codeword, int8_t* decoded);
    };
}// end namespace wimax_ldpc_lib



#endif // LDPC_ENCODER_H