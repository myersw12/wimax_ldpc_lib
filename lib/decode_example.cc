#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "ldpc_decoder.h"

#define MAX_ITER 10
#define NUM_THREADS 4

int main()
{
    FILE *f;
    FILE *fw;
    
    uint64_t start_time;
    uint64_t elapsed_time;
    uint64_t time_sum = 0;
    double avg_time;
    uint64_t max_time = 0;
    uint64_t min_time = 10000000000;
    unsigned int num_errors;
    unsigned int initial_errors;
    
    uint8_t* file_buffer = (uint8_t*) malloc(4096*(576));
    
    f = fopen("../example_data/576_codewords.bin", "rb");
    
    if(f)
    {
        int n = fread(file_buffer, 1, 4096*(576), f);
        printf("nread: %d\n", n);
    }
    
    fclose(f);
    
    ldpc_decoder decoder = ldpc_decoder(HALFRATE, 24, MAX_ITER, NUM_THREADS);
   
    uint8_t temp_codeword[576];
    
    fw = fopen("../example_data/576_decoded.bin", "wb");
    
    for (unsigned int i = 0; i < 4096; i++)
    {
        initial_errors = decoder.compute_syndrome(file_buffer + i*576);
        
        start_time = decoder.get_nanoseconds();
        
        num_errors = decoder.decode(file_buffer + i * 576, temp_codeword);
        
        elapsed_time = decoder.get_nanoseconds() - start_time;
        time_sum += elapsed_time;
       
        if(elapsed_time > max_time)
            max_time = elapsed_time;
        
        if(elapsed_time < min_time)
            min_time = elapsed_time;
        
        fwrite(temp_codeword, 1, 576, fw);
        
        printf("Rate (Mbits/Sec): %f\n", (576.0 * 1000.0) / (elapsed_time) ); 
        printf("Initial Number of Errors: %d\n", initial_errors);
        printf("Final Number of Errors: %d\n\n", num_errors);
    }
    
    avg_time = time_sum / 4096.0;
    printf("Average Rate (Mbits/Sec): %f\n", (576.0 * 1000.0) / (avg_time) ); 
    printf("Fastest Time (Mbits/Sec): %f\n", (576.0 * 1000.0) / (min_time) );
    printf("Slowest Time (Mbits/Sec): %f\n", (576.0 * 1000.0) / (max_time) );

    fclose(fw);
    
    free(file_buffer);
    
    return 1;
}