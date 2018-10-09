#ifndef BER_RUNNER_H
#define BER_RUNNER_H

#include <stdint.h>

#include "enums.h"
#include "ldpc.h"
#include "ldpc_encoder.h"
#include "ldpc_decoder.h"

namespace wimax_ldpc_lib {
    class BER_runner : public ldpc
    {

        private:
           
            ldpc_encoder* m_encoder;
            ldpc_decoder* m_decoder;
            
            unsigned int m_num_bits;
            unsigned int m_num_errors;
            unsigned int m_codeword_len;
            unsigned int m_dataword_len;
            
            float m_float_rate;
            
            unsigned int compare_data(uint8_t* rand_data,
                                      int8_t* decoded_data);
            
            void fill_with_random(uint8_t* buffer,
                                  unsigned int buf_len);
            
            
        public:
            BER_runner();
            BER_runner(coderate rate, unsigned int z_factor,
                       unsigned int num_threads,
                       unsigned int max_iter
                      );
            ~BER_runner();
            
            void reset_test();
            
            double run_iteration(double EbNo_dB);
            
            unsigned int get_total_num_bits();
            
            unsigned int get_total_num_errors();
            
    };
}// end namespace wimax_ldpc_lib



#endif // BER_RUNNER_H