#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <volk/volk.h>

#include "ldpc_decoder.h"

#define MAX_ITER 10

using namespace wimax_ldpc_lib;

int main(int argc, char *argv[])
{
    
    if (argc != 7)
    {
        printf("\nError: Incorrect number of arguments\n");
        printf("Usage: ./test_decoder <num_threads> <rate> <z> <num_codewords> <encoded_data_file> <decoded_data_file>\n");
        printf("Argument Description:\n");
        printf("num_threads: Number of threads to use.  num_codewords modulo num_threads == 0.\n");
        printf("rate: LDPC code rate - half-rate        = 0\n");
        printf("                       two-thirds-A     = 1\n");
        printf("                       two-thirds-B     = 2\n");
        printf("                       three-quarters-A = 3\n");
        printf("                       three-quarters-B = 4\n");
        printf("                       five-sixths      = 5\n");
        printf("z: Z Factor (please refer to section 8.4.9.2.5 of the 802.16-2012 standard for more information)\n");
        printf("num_codewords: How many LDPC codewords are in the file.\n");
        printf("encoded_data_file: File to read the encoded data from.\n");
        printf("decoded_data_file: File to write decoded data to.\n\n");
        return 0;
    }
    
    FILE *encoded_data;
    FILE *decoded_data;
    
    uint64_t start_time;
    uint64_t elapsed_time;
    uint64_t time_sum = 0;
    double avg_time;
    uint64_t max_time = 0;
    uint64_t min_time = 10000000000;

    
    coderate rate = (coderate)std::stoi(argv[2], nullptr, 0);
    unsigned int num_threads = std::stoi(argv[1], nullptr, 0);
    int z = std::stoi(argv[3], nullptr, 0);
    unsigned int num_codewords = std::stoi(argv[4], nullptr, 0);
    
    unsigned int num_errors[num_threads];
    unsigned int initial_errors[num_threads];
    
    ldpc_decoder* decoders[num_threads];
    
    int codeword_len = (z / 96.0) * BASE_LDPC_BLOCK_LEN;
    int dataword_len = 0;
    
    int8_t* file_buffer = (int8_t*) volk_malloc(num_codewords*codeword_len, volk_get_alignment());
    
    encoded_data = fopen(argv[5], "rb");
    decoded_data = fopen(argv[6], "wb");
    
    if(encoded_data)
    {
        unsigned int n = fread(file_buffer, 1, num_codewords*codeword_len, encoded_data);
        if(n != num_codewords*codeword_len)
        {
            printf("[!] Error: File does not contain enough data.\n");
            return 0;
        }
    }
    
    fclose(encoded_data);
    
    for (unsigned int i = 0; i < num_threads; i++){
        decoders[i] = new ldpc_decoder(rate, z, MAX_ITER, num_threads);
    }
    
    int8_t* temp_codeword = (int8_t*)volk_malloc(codeword_len * num_threads, volk_get_alignment());

    switch(rate)
    {
        case (HALFRATE):
        {
            dataword_len = codeword_len / 2; 
            break;
        }
        
        case (TWOTHIRDSA):
        case (TWOTHIRDSB):
        {
            dataword_len = (codeword_len * 2) / 3;
            break;
        }
        
        case (THREEQUARTERSA):
        case (THREEQUARTERSB):
        {
            dataword_len = (codeword_len * 3) / 4;
            break;
        }
        
        case (FIVESIXTHS):
        {
            dataword_len = (codeword_len * 5) / 6;
            break;
        }
        
        default:
        {
            printf("[!]test_encoder - Invalid Coderate: %d\n", rate);
            throw std::exception();
            break;
        }
    }
    
    
    for (unsigned int i = 0; i < num_codewords-(num_threads-1); i+=num_threads)
    {
        
        for (unsigned int k = 0; k < num_threads; k++)
            initial_errors[k] = decoders[k]->compute_syndrome(file_buffer + (i+k)*codeword_len, false);
        
        start_time = decoders[0]->get_nanoseconds();
        
        #pragma omp parallel for num_threads(num_threads)
        for(unsigned int j = 0; j < num_threads; j++)
        {
            num_errors[j] = 
            decoders[j]->decode(file_buffer + (i+j) * codeword_len,
                               temp_codeword + j*codeword_len);
       
        }
        
        elapsed_time = decoders[0]->get_nanoseconds() - start_time;
        time_sum += elapsed_time;
       
        if(elapsed_time > max_time)
            max_time = elapsed_time;
        
        if(elapsed_time < min_time)
            min_time = elapsed_time;
        
        for (unsigned int j = 0; j < num_threads; j++)
            fwrite(temp_codeword + j*codeword_len, 1, dataword_len, decoded_data);
        
        printf("Rate (Mbits/Sec): %f\n", (num_threads*codeword_len * 1000.0) / (elapsed_time) ); 
        
        for (unsigned int n = 0; n < num_threads; n++){
            printf("Initial Number of Errors (%d): %d\n", n, initial_errors[n]);
            printf("Final Number of Errors (%d): %d\n", n, num_errors[n]);
        }
        printf("\n");

    }
    
    avg_time = time_sum / float(num_codewords);
    printf("\nTiming Statistics:\n\n");
    printf("Average Rate (Mbits/Sec): %f\n", (codeword_len * 1000.0) / (avg_time) ); 
    printf("Fastest Iteration (Mbits/Sec): %f\n", (num_threads*codeword_len * 1000.0) / (min_time) );
    printf("Slowest Iteration (Mbits/Sec): %f\n", (num_threads*codeword_len * 1000.0) / (max_time) );

    fclose(decoded_data);
    
    volk_free(file_buffer);
    volk_free(temp_codeword);
    
    for (unsigned int i = 0; i < num_threads; i++){
        delete decoders[i];
    }
    
    return 1;
}
