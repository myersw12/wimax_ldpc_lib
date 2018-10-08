#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <volk/volk.h>
#include <math.h>
#include <random>

#include <mgl2/qt.h>    

#include "ldpc_encoder.h"
#include "ldpc_decoder.h"

#define MAX_ITER 10
#define BLOCK_MULTIPLE 100
#define BITS_PER_SYM 2
#define CONFIDENCE_VALUE 0.95

using namespace wimax_ldpc_lib;

void fill_with_random(uint8_t* buffer, unsigned int buf_len)
{
    // initialize the random number generator
    srand(time(0));
    for (unsigned int i = 0; i < buf_len; i++)
    {
        buffer[i] = rand() % 2;
    }
}

unsigned int compare_data(int8_t* rand_data, int8_t* decoded_data, unsigned int codeword_len,
                          unsigned int num_threads)
{
    unsigned int num_errors = 0;
    
    #pragma omp parallel for num_threads(num_threads)
    for(unsigned int j = 0; j < num_threads * codeword_len; j++)
    {
        if (rand_data[j] != decoded_data[j])
        {
            num_errors++;
        }
    }
    return num_errors;
}

double run_BER_iteration(ldpc_encoder encoder, ldpc_decoder* decoders,
                         unsigned int codeword_len, unsigned int dataword_len,
                         float* codeword_buffer, int8_t* decoded_buffer,
                         int8_t* decoded_data, unsigned int num_threads,
                         unsigned int num_total, unsigned int num_errors, 
                         double EbNo_dB, double rate,
                         std::default_random_engine generator,
                         std::normal_distribution<float> dist
                        )
{
    
    uint8_t temp_dataword[dataword_len];
    uint8_t temp_codeword[codeword_len];
    
    int8_t rand_data[dataword_len*num_threads];
    
    float EbNo_linear = pow(10,(EbNo_dB/10.0));
    
    float noise_amplitude = (1.0/std::sqrt(EbNo_linear)) * std::sqrt(1.0/(rate*BITS_PER_SYM));
    
    
    // generate random data and BPSK modulate
    for (unsigned int j = 0; j < num_threads; j++)
    {
        fill_with_random(temp_dataword, dataword_len);
        
        memcpy(rand_data + j*dataword_len, temp_dataword, dataword_len);
    
        encoder.encode_data(temp_dataword, temp_codeword);
        
        for(unsigned int k = 0; k < codeword_len; k++)
        {
            codeword_buffer[j*codeword_len+k] = temp_codeword[k] * 2 - 1; 
        }
    
    }
    
    // Apply AWGN
    #pragma omp parallel for num_threads(num_threads)
    for (unsigned int j = 0; j < num_threads*codeword_len; j++)
    {
        codeword_buffer[j] = codeword_buffer[j] + noise_amplitude * dist(generator);
    }
    
    
    
    #pragma omp parallel for num_threads(num_threads)
    for(unsigned int j = 0; j < num_threads; j++)
    {
        num_errors = decoders[j].decode(codeword_buffer + j * codeword_len * sizeof(float),
                            decoded_buffer + j*codeword_len);
        memcpy(decoded_data, decoded_buffer + j*codeword_len, dataword_len);
    
    }
    
    num_total += codeword_len*num_threads;
    num_errors += compare_data(rand_data, decoded_data, codeword_len, num_threads);
   
    return (double)num_total / (double)num_errors;
}

int main(int argc, char *argv[])
{
    
    if (argc != 7)
    {
        printf("\nError: Incorrect number of arguments\n");
        printf("Usage: ./BER_example <num_threads> <rate> <z> <EbNo_start> <EbNo_end> <EbNo_step> \n");
        printf("Argument Description:\n");
        printf("num_threads: Number of threads to use.  num_codewords modulo num_threads == 0.\n");
        printf("rate: LDPC code rate - half-rate        = 0\n");
        printf("                       two-thirds-A     = 1\n");
        printf("                       two-thirds-B     = 2\n");
        printf("                       three-quarters-A = 3\n");
        printf("                       three-quarters-B = 4\n");
        printf("                       five-sixths      = 5\n");
        printf("z: Z Factor (please refer to section 8.4.9.2.5 of the 802.16-2012 standard for more information)\n");
        printf("EbNo_start: Starting value for BER plot x axis (dB)\n");
        printf("EbNo_end: Ending value for BER plot x axis (dB)\n");
        printf("EbNo_step: Step value for BER plot x axis (dB)\n\n");
        return 0;
    }
    
    uint64_t start_time;
    uint64_t elapsed_time;
    uint64_t time_sum = 0;
    double avg_time;
    uint64_t max_time = 0;
    uint64_t min_time = 10000000000;
    
    double BER;
    double EbNo_dB;
    
    float float_rate = 0.0;
    
    std::default_random_engine generator;
    std::normal_distribution<float> dist(0.0, 1.0);

    
    coderate rate = (coderate)std::stoi(argv[2], nullptr, 0);
    unsigned int num_threads = std::stoi(argv[1], nullptr, 0);
    int z = std::stoi(argv[3], nullptr, 0);
    
    int start = std::stoi(argv[4], nullptr, 0);
    int stop = std::stoi(argv[5], nullptr, 0);
    float step = std::stof(argv[6], nullptr);
    
    unsigned int num_steps;
    
    if (fmod(stop - stop, step) != 0)
    {
        printf("[!] BER_example: step size does not evenly divide range\n");
    }
    else
    {
        num_steps = (unsigned int)(stop-start)/step;
    }
    
    unsigned int num_errors = 0.0;
    unsigned int num_total = 0.0;
    
    ldpc_decoder* decoders[num_threads];
    ldpc_encoder encoder = ldpc_encoder(rate, z, num_threads);

    
    int codeword_len = (z / 96.0) * BASE_LDPC_BLOCK_LEN;
    int dataword_len = 0;
    
    float* codeword_buffer = (float*) volk_malloc(num_threads*codeword_len, volk_get_alignment());
    int8_t* decoded_buffer = (int8_t*) volk_malloc(num_threads*codeword_len, volk_get_alignment());

    
    for (unsigned int i = 0; i < num_threads; i++){
        decoders[i] = new ldpc_decoder(rate, z, MAX_ITER, num_threads);
    }
    
    int8_t* temp_codeword = (int8_t*)volk_malloc(codeword_len * num_threads, volk_get_alignment());

    switch(rate)
    {
        case (HALFRATE):
        {
            dataword_len = codeword_len / 2; 
            float_rate = 0.5;
            break;
        }
        
        case (TWOTHIRDSA):
        case (TWOTHIRDSB):
        {
            dataword_len = (codeword_len * 2) / 3;
            float_rate = 2.0/3.0;
            break;
        }
        
        case (THREEQUARTERSA):
        case (THREEQUARTERSB):
        {
            dataword_len = (codeword_len * 3) / 4;
            float_rate = 3.0/4.0;
            break;
        }
        
        case (FIVESIXTHS):
        {
            dataword_len = (codeword_len * 5) / 6;
            float_rate = 5.0/6.0;
            break;
        }
        
        default:
        {
            printf("[!]test_encoder - Invalid Coderate: %d\n", rate);
            throw std::exception();
            break;
        }
    }
    
    
    int8_t* decoded_data = (int8_t*) volk_malloc(num_threads*dataword_len, volk_get_alignment());
    
    
    double confidence_level = 0.0;
    
    EbNo_dB = (double)start;
    
    for (int i = start; i < num_steps; i++)
    {
        printf("EbN0(dB): %f\n", EbNo_dB);
        
        while(confidence_level < CONFIDENCE_VALUE)
        {
            BER = run_BER_iteration(encoder, *decoders, codeword_len, dataword_len,
                                codeword_buffer, decoded_buffer, decoded_data,
                                num_threads, num_total, num_errors, EbNo_dB,
                                float_rate, generator, dist);
            
            confidence_level = 1 - std::exp(num_total*BER*-1);
        }
        
        printf("confidence_level: %f\n", confidence_level);
        printf("BER: %f\n\n", BER);
        EbNo_dB += step;
        
    }

    
    volk_free(decoded_data);
    volk_free(codeword_buffer);
    volk_free(decoded_buffer);
    volk_free(temp_codeword);

    
    return 1;
}
