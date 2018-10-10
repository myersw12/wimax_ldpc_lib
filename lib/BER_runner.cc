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
        
        m_dist_awgn = std::normal_distribution<float> (0.0, 1.0);
        m_generator_awgn = std::mt19937(0);
        
        m_dist_data = std::uniform_real_distribution<> (0.0, 1.0);
        m_generator_data = std::mt19937(0);
        
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
        for (unsigned int i = 0; i < buf_len; i++)
        {
            buffer[i] = (uint8_t)(m_dist_data(m_generator_data) < 0.5);
        }
    }
    
    unsigned int BER_runner::compare_data(uint8_t* rand_data, int8_t* decoded_data)
    {
        unsigned int num_errors = 0;
        
        for(unsigned int j = 0; j < m_dataword_len; j++)
        {
            if (rand_data[j] != decoded_data[j])
            {
                num_errors++;
            }
        }
        return num_errors;
    }
    
    float BER_runner::gaussian_dev()
    {
        if(m_num_stored)
        {
            m_num_stored = false;
            return m_stored_value;
        }
        else
        {
            float x,y,s;
            do{
                x = 2.0*m_dist_awgn(m_generator_awgn)-1.0;
                y = 2.0*m_dist_awgn(m_generator_awgn)-1.0;
                s = x*x+y*y;
            }while(s >= 1.0f || s == 0.0f);
            m_num_stored = true;
            m_stored_value = x*std::sqrt(-2.0*std::log(s)/s);
            return y*std::sqrt(-2.0*std::log(s)/s);
        }
    
    }
    
    double BER_runner::run_iteration(double EbNo_dB)
    {
        
        uint8_t temp_dataword[m_dataword_len];
        uint8_t temp_codeword[m_codeword_len];
        
        float codeword_buffer[m_codeword_len];
        
        int8_t decoded_data[m_codeword_len];
        
        double EbNo_linear = pow(10.0,(EbNo_dB/10.0));
        
        unsigned int errs;
        
        //printf("linear: %f\n", EbNo_linear);
        
        float noise_amplitude = (1.0/std::sqrt(EbNo_linear)) * std::sqrt(1.0/(m_float_rate*BITS_PER_SYM));
        
        //printf("noise amp %f\n", noise_amplitude);
        
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
            codeword_buffer[j] = codeword_buffer[j] +
                        std::sqrt(0.5) * noise_amplitude * gaussian_dev();
        }
        
        
        errs = m_decoder->decode(codeword_buffer,
                         decoded_data);
        
            
        m_num_bits += m_dataword_len;
        m_num_errors += compare_data(temp_dataword, decoded_data);
        
        
        return (double) m_num_errors / (double) m_num_bits;
        
    }
    
    
    
} // end namespace wimax_ldpc_lib