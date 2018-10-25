#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <volk/volk.h>
#include <math.h>
#include <random>
#include <string>

#include <mgl2/qt.h>    
#include "BER_runner.h"

#define MAX_ITER 10

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
        printf("                       three-quarters-A = 3\n");
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
    
    BER_runner ber_test = BER_runner(rate, z, num_threads, MAX_ITER);
   
    mglGraph gr;
    mglData BER_array;
    mglData EbNo_db_array;
    
    std::string string_rate;
    char sbuff [50];
    
    switch(rate)
    {
        case (HALFRATE):
        {
            string_rate = "1/2";
            break;
        }
        case (TWOTHIRDSA):
        {
            string_rate = "2/3A";
            break;
        }
        case (TWOTHIRDSB):
        {
            string_rate = "2/3B";
            break;
        }
        case (THREEQUARTERSA):
        {
            string_rate = "3/4A";
            break;
        }
        case (THREEQUARTERSB):
        {
            string_rate = "3/4B";
            break;
        }
        case (FIVESIXTHS):
        {
            string_rate = "5/6";
            break;
        }
        default:
        {
            printf("[!]test_encoder - Invalid Coderate: %d\n", rate);
            throw std::exception();
            break;
        }
        
    }
    
    sprintf(sbuff, "LDPC %s Rate, N = %d, K = %d",
            string_rate.c_str(), ber_test.get_codeword_len(),
            ber_test.get_dataword_len());
    
    gr.Box();
    gr.SetRanges(start-step, stop, pow(10, -8), .1);
    gr.SetFunc("","lg(y)");

    gr.Axis();
    gr.Title(sbuff, "k:C", 7);
    
    sprintf(sbuff, "%d %s Rate LDPC", ber_test.get_codeword_len(), string_rate.c_str());
    
    gr.AddLegend(sbuff, "b");
    gr.Legend();
    gr.Label('x', "Eb/N0 (dB)", 0);
    gr.Label('y', "Bit Error Rate", 0);
    
    
    if (fmod(stop - start, step) != 0)
    {
        printf("[!] BER_example: step size does not evenly divide range\n");
    }
    else
    {
        num_steps = (unsigned int)((stop-start)/step) + 1;
    }
    
    
    double EbNo_dB = (double)start;
    double BER = 0.0;
    unsigned int num_req = 0;
    
    BER_array.Create(num_steps);
    EbNo_db_array.Create(num_steps);
    
    for (unsigned int i = 0; i < num_steps; i++)
    {
        
        printf("EbN0(dB): %f\n", EbNo_dB);
        
        // run a few iterations to get a guestimate of what the BER is 
        // going to be
        for (unsigned int j = 0; j < 46080 / ber_test.get_dataword_len(); j++)
        {
            BER = ber_test.run_iteration(EbNo_dB);
        }  
        
        if(BER == 0.0)
        {
            // if BER is 0, then we are dealing with a low BER
            // the num_req value set below will give us enough 
            // bits to see low BER levels
            num_req = floor(3.912 / 0.00000001);
        }
        else
        {
            num_req = 10 * floor(3.912 / BER);
        }
        
        for (unsigned int j = 0; j < num_req/ber_test.get_dataword_len(); j++)
        {
            BER = ber_test.run_iteration(EbNo_dB);
        }
           
        
        BER_array.a[i] = BER;
        EbNo_db_array.a[i] = EbNo_dB;
        
        ber_test.reset_test();
        
        printf("BER: %e\n\n", BER);
        EbNo_dB += step;

    }
    
    gr.Plot(EbNo_db_array, BER_array, "+");
    gr.Label(BER_array, "%y", 0);
    
    sprintf(sbuff, "BER_LDPC_RATE%d_N%d_K%d.png",
            (int)rate, ber_test.get_codeword_len(),
            ber_test.get_dataword_len());
    gr.WriteFrame(sbuff); 

    
    return 1;
}
