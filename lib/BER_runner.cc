#include <stdio.h>
#include <math.h>
#include <random>
#include <cstring>

#include "BER_runner.h"


#define BITS_PER_SYM 1

namespace wimax_ldpc_lib {
    
    BER_runner::BER_runner() {}
    
    BER_runner::BER_runner(coderate rate,
                           unsigned int z_factor,
                           unsigned int num_threads,
                           unsigned int max_iter
                          ) : ldpc(rate,
                                   z_factor,
                                   num_threads)
                           
    {
        m_encoder = new ldpc_encoder(rate, z_factor, num_threads);
        m_decoder = new ldpc_decoder(rate, z_factor, max_iter, num_threads);
        
        
        m_num_bits = 0;
        m_num_errors = 0;

        m_codeword_len = (z_factor / 96.0) * BASE_LDPC_BLOCK_LEN;
        
        switch(rate)
        {
            case (HALFRATE):
            {
                m_dataword_len = m_codeword_len / 2; 
                m_float_rate = 0.5;
                break;
            }
            
            case (TWOTHIRDSA):
            case (TWOTHIRDSB):
            {
                m_dataword_len = (m_codeword_len * 2) / 3;
                m_float_rate = 2.0/3.0;
                break;
            }
            
            case (THREEQUARTERSA):
            case (THREEQUARTERSB):
            {
                m_dataword_len = (m_codeword_len * 3) / 4;
                m_float_rate = 3.0/4.0;
                break;
            }
            case (FIVESIXTHS):
            {
                m_dataword_len = (m_codeword_len * 5) / 6;
                m_float_rate = 5.0/6.0;
                break;
            }
            
            default:
            {
                printf("[!]test_encoder - Invalid Coderate: %d\n", rate);
                throw std::exception();
                break;
            }
        }
        
    }
    
    BER_runner::~BER_runner()
    {
        delete m_encoder;
        delete m_decoder;
    }
    
    
    void BER_runner::reset_test()
    {
        
        m_num_bits = 0;
        m_num_errors = 0;
        
    }
    
    unsigned int BER_runner::get_total_num_bits()
    {
        return m_num_bits;
    }
    
    unsigned int BER_runner::get_total_num_errors()
    {
        return m_num_errors;
    }
    
    void BER_runner::fill_with_random(uint8_t* buffer, unsigned int buf_len)
    {
        // initialize the random number generator
        srand(time(0));
        for (unsigned int i = 0; i < buf_len; i++)
        {
            buffer[i] = rand() % 2;
        }
    }
    
    unsigned int BER_runner::compare_data(uint8_t* rand_data, int8_t* decoded_data)
    {
        unsigned int num_errors = 0;
        
        for(unsigned int j = 0; j < m_codeword_len; j++)
        {
            if (rand_data[j] != decoded_data[j])
            {
                num_errors++;
            }
        }
        return num_errors;
    }
    
    double BER_runner::run_iteration(double EbNo_dB)
    {
        std::default_random_engine generator; 
        std::normal_distribution<float> dist(0.0, 1.0);
        
        uint8_t temp_dataword[m_dataword_len];
        uint8_t temp_codeword[m_codeword_len];
        
        float codeword_buffer[m_codeword_len];
        
        int8_t decoded_data[m_codeword_len];
        
        float EbNo_linear = pow(10,(EbNo_dB/10.0));
        
        float noise_amplitude = (1.0/std::sqrt(EbNo_linear)) * std::sqrt(1.0/(m_float_rate*BITS_PER_SYM));
        
        // generate random data and BPSK modulate
        fill_with_random(temp_dataword, m_dataword_len);
            
        m_encoder->encode_data(temp_dataword, temp_codeword);
        
        for(unsigned int k = 0; k < m_codeword_len; k++)
        {
            //printf("index: %d\n", j*codeword_len + k);
            codeword_buffer[k] = temp_codeword[k] * 2 - 1; 
        }
        
        // Apply AWGN
        //#pragma omp parallel for num_threads(num_threads)
        for (unsigned int j = 0; j <m_codeword_len; j++)
        {
            codeword_buffer[j] = codeword_buffer[j] + noise_amplitude * dist(generator);
        }
        
        
        m_decoder->decode(codeword_buffer,
                         decoded_data);
            
        m_num_bits += m_codeword_len;
        m_num_errors += compare_data(temp_codeword, decoded_data);
        
        return (double) m_num_errors / (double) m_num_bits;
        
    }
    
    
    
} // end namespace wimax_ldpc_lib