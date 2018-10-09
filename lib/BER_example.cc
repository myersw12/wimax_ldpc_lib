#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <volk/volk.h>
#include <math.h>
#include <random>

#include <mgl2/qt.h>    
#include "BER_runner.h"

#define MAX_ITER 10
#define CONFIDENCE_VALUE 0.0

using namespace wimax_ldpc_lib;

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
        printf("           std::normal_distribution<double>             three-quarters-A = 3\n");
        printf("                       three-quarters-B = 4\n");
        printf("                       five-sixths      = 5\n");
        printf("z: Z Factor (please refer to section 8.4.9.2.5 of the 802.16-2012 standard for more information)\n");
        printf("EbNo_start: Starting value for BER plot x axis (dB)\n");
        printf("EbNo_end: Ending value for BER plot x axis (dB)\n");
        printf("EbNo_step: Step value for BER plot x axis (dB)\n\n");
        return 0;
    }
    
    
    coderate rate = (coderate)std::stoi(argv[2], nullptr, 0);
    unsigned int num_threads = std::stoi(argv[1], nullptr, 0);
    int z = std::stoi(argv[3], nullptr, 0);
    
    int start = std::stoi(argv[4], nullptr, 0);
    int stop = std::stoi(argv[5], nullptr, 0);
    float step = std::stof(argv[6], nullptr);
    
    unsigned int num_steps = 0;
    
    if (fmod(stop - stop, step) != 0)
    {
        printf("[!] BER_example: step size does not evenly divide range\n");
    }
    else
    {
        num_steps = (unsigned int)(stop-start)/step;
    }
    
    BER_runner ber_test = BER_runner(rate, z, num_threads, MAX_ITER);
    
    double EbNo_dB = (double)start;
    double BER = 0.0;
    
    for (unsigned int i = 0; i < num_steps; i++)
    {
        printf("EbN0(dB): %f\n", EbNo_dB);
        
        double confidence_level = 0.0;
        bool confidence = false;
        
        while(!confidence)
        {
            for (unsigned int j = 0; j < 10000; j++)
                BER = ber_test.run_iteration(EbNo_dB);
            
            //printf("exp: %f\n", ((double)ber_test.get_total_num_bits() * BER * -1.0));
             
            confidence_level = 1.0 - std::exp((double)ber_test.get_total_num_bits()*BER*-1.0);
            
            
            //printf("confidence_level: %f\n", confidence_level);
            
            if (confidence_level > CONFIDENCE_VALUE)
                confidence = true;
        }
        
        ber_test.reset_test();
        
        printf("confidence_level: %f\n", confidence_level);
        printf("BER: %f\n\n", BER);
        EbNo_dB += step;
        
    }
    
    
    return 1;
}
