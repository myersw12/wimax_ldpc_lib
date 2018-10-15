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
            
            uint64_t m_num_bits;
            uint64_t m_num_errors;
            
            unsigned int m_codeword_len;
            unsigned int m_dataword_len;
            
            float m_float_rate;
            float m_stored_value;
            
            bool m_num_stored;
            
            uint32_t m_lfsr;
            uint32_t m_lfsr_start_state;
            unsigned int m_lfsr_index;
            unsigned int m_lfsr_reset_len;
            
            
            unsigned int compare_data(uint8_t* rand_data,
                                      int8_t* decoded_data);
            
            void fill_with_random(uint8_t* buffer,
                                  unsigned int buf_len);
            
            
            uint32_t lfsr_get_num();
            
            std::mt19937 m_generator_awgn; 

            std::normal_distribution<float> m_dist_awgn;
            
        public:
            BER_runner();
            BER_runner(coderate rate, unsigned int z_factor,
                       unsigned int num_threads,
                       unsigned int max_iter
                      );
            ~BER_runner();
            
            void reset_test();
            
            double run_iteration(double EbNo_dB);
            
            uint64_t get_total_num_bits();
            
            uint64_t get_total_num_errors();
            
            unsigned int get_codeword_len();
            
            unsigned int get_dataword_len();
            
    };
}// end namespace wimax_ldpc_lib



#endif // BER_RUNNER_H