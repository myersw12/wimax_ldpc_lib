#include <stdio.h>

#include "ldpc_encoder.h"

int main()
{
    FILE *f;
    
    uint8_t file_buffer[4096*(576/2)];
    
    f = fopen("../example_data/576_infowords.bin", "rb");
    
    if(f)
    {
        fread(file_buffer, 1, 4096*(576/2), f);
    }
    
    fclose(f);
    
    
    
    ldpc_encoder encoder = ldpc_encoder(HALFRATE, 24);
    
    printf("testing 123\n");
    
    uint8_t temp_codeword[576];
    
    f = fopen("../example_data/576_codewords.bin", "wb");
    
    for (unsigned int i = 0; i < 4096; i++)
    {
        encoder.encode_data(&file_buffer[i*(576/2)], temp_codeword);
        fwrite(temp_codeword, 1, 576, f);
    }
    
    fclose(f);
   
    return 1;
}