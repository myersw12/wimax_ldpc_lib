#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <chrono>

#include "ldpc_encoder.h"


uint64_t get_nanoseconds()
{
    auto now = std::chrono::high_resolution_clock::now(); 
    uint64_t nanoseconds =
    std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::
                  now().time_since_epoch()).count();
        
    return nanoseconds;
}

int main()
{
    FILE *f;
    FILE *fw;
    
    uint64_t start_time;
    uint64_t elapsed_time;
    uint64_t avg_time;
    
    uint8_t* file_buffer = (uint8_t*) malloc(4096*(576/2));
    
    f = fopen("../example_data/576_infowords.bin", "rb");
    
    if(f)
    {
        int n = fread(file_buffer, 1, 4096*(576/2), f);
        printf("nread: %d\n", n);
    }
    
    fclose(f);
    
    ldpc_encoder encoder = ldpc_encoder(HALFRATE, 24);
    
    printf("testing 123\n");
    
    uint8_t temp_codeword[576];
    
    
    fw = fopen("../example_data/576_codewords.bin", "wb");
    
    for (unsigned int i = 0; i < 4096; i++)
    {
        
        start_time = get_nanoseconds();
        encoder.encode_data(file_buffer + i * 288, temp_codeword);
        elapsed_time = get_nanoseconds() - start_time;
        avg_time += elapsed_time;
        printf("Rate (Mbits/Sec): %f\n", (4096.0 * 1000.0) / (elapsed_time) ); 
        fwrite(temp_codeword, 1, 576, fw);
    }
    
    avg_time = avg_time / 4096;
    printf("Average Rate (Mbits/Sec): %f\n", (4096.0 * 1000.0) / (avg_time) ); 

    
    fclose(fw);
    printf("closed the file\n");
    
    free(file_buffer);
    
    
    
    
    return 1;
}