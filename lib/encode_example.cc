#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <chrono>
#include <inttypes.h>
#include <string>
#include <ctime>

#include "ldpc_encoder.h"

#define NUM_THREADS 4

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

void add_errors(uint8_t* buffer, unsigned int buf_len, unsigned int num_errors)
{
    srand(time(0));
    for (unsigned int i = 0; i < num_errors; i++)
    {
        unsigned int rand_index = (rand() % buf_len) + 1;
        buffer[rand_index] = not buffer[rand_index];
    }
}

int main(int argc, char *argv[])
{
    
    if (argc != 7)
    {
        printf("\nError: Incorrect number of arguments\n");
        printf("Usage: ./test_encoder <rate> <z> <num_rounds> <errors_to_add> <unencoded_data_file> <encoded_data_file>\n");
        printf("Argument Description:\n");
        printf("rate: LDPC code rate - half-rate        = 0\n");
        printf("                       two-thirds-A     = 1\n");
        printf("                       two-thirds-B     = 2\n");
        printf("                       three-quarters-A = 3\n");
        printf("                       three-quarters-B = 4\n");
        printf("                       five-sixths      = 5\n");
        printf("z: Z Factor (please refer to section 8.4.9.2.5 of the 802.16-2012 standard for more information\n");
        printf("num_rounds: How many LDPC encoding rounds to run.\n");
        printf("errors_to_add: How many errors to add to each LDPC codeword.\n");
        printf("unencoded_data_file: File to write the unencoded data to.\n");
        printf("encoded_data_file: File to write LDPC encoded data to.\n\n");
        return 0;
    }
    
    FILE *data_file;
    FILE *encoded_file;
    
    uint64_t start_time;
    uint64_t elapsed_time;
    uint64_t time_sum = 0;
    double avg_time;
    uint64_t max_time = 0;
    uint64_t min_time = 10000000000;
   
    coderate rate = (coderate)std::stoi(argv[1], nullptr, 0);
    int z = std::stoi(argv[2], nullptr, 0);
    unsigned int num_rounds = std::stoi(argv[3], nullptr, 0);
    unsigned int num_errors = std::stoi(argv[4], nullptr, 0);
    
    unsigned int codeword_len = (z / 96.0) * BASE_LDPC_BLOCK_LEN;
    unsigned int dataword_len = 0;
    
    if(num_errors >= codeword_len){
        printf("[!] Error: Num_errors greater than codeword length\n");
        return 0;
    }
    
    data_file = fopen(argv[5], "wb");
    encoded_file = fopen(argv[6], "wb");
    
    ldpc_encoder encoder = ldpc_encoder(rate, z, NUM_THREADS);
   
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
    
    uint8_t temp_codeword[codeword_len];
    uint8_t temp_dataword[dataword_len];
    
    for (unsigned int i = 0; i < num_rounds; i++)
    {
        fill_with_random(temp_dataword, dataword_len);
        fwrite(temp_dataword, 1, dataword_len, data_file);
        
        start_time = encoder.get_nanoseconds();
        encoder.encode_data(temp_dataword, temp_codeword);
        elapsed_time = encoder.get_nanoseconds() - start_time;
        time_sum += elapsed_time;
        printf("Round[%d] Rate (Mbits/Sec): %f\n", i,(codeword_len * 1000.0) / (elapsed_time)); 
        
        if(elapsed_time > max_time)
            max_time = elapsed_time;
        
        if(elapsed_time < min_time)
            min_time = elapsed_time;
        
        if(num_errors > 0)
            add_errors(temp_codeword, codeword_len, num_errors);
        
        fwrite(temp_codeword, 1, codeword_len, encoded_file);
    }
    
    avg_time = time_sum / float(num_rounds);
    printf("\n\nTiming Statistics:\n\n");
    printf("Average Rate (Mbits/Sec): %f\n", (codeword_len * 1000.0) / (avg_time) ); 
    printf("Fastest Time (Mbits/Sec): %f\n", (codeword_len * 1000.0) / (min_time) );
    printf("Slowest Time (Mbits/Sec): %f\n", (codeword_len * 1000.0) / (max_time) );

    fclose(data_file);
    fclose(encoded_file);
    
    return 1;
}