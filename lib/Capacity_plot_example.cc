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
#define EBNO_STEP 0.01

using namespace wimax_ldpc_lib;

int main(int argc, char *argv[])
{
    
    if (argc != 3)
    {
        printf("\nError: Incorrect number of arguments\n");
        printf("Usage: ./Capacity_example <num_threads> <z>\n");
        printf("Argument Description:\n");
        printf("num_threads: Number of threads to use.  num_codewords modulo num_threads == 0.\n");
        printf("z: Z Factor (please refer to section 8.4.9.2.5 of the 802.16-2012 standard for more information)\n");
        return 0;
    }
    
    
    unsigned int num_threads = std::stoi(argv[1], nullptr, 0);
    int z = std::stoi(argv[2], nullptr, 0);
    
    mglGraph gr;
    mglData BER_array;
    mglData EbNo_db_array;
    
    std::string string_rate;
    char sbuff [50];
    
    unsigned int ratelist[5] = {0, 1, 2, 3, 5};

    
    /*
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
    */
    
    
    unsigned int num_req = (unsigned int)(3.912 / 0.00001);
    
    for (unsigned int i = 0; i < 5; i++)
    {
        coderate rate = (coderate)ratelist[i];
        
        BER_runner ber_test = BER_runner(rate, z, num_threads, MAX_ITER);
        double EbNo_dB = 0.25;
        double BER = 0.0;
        
        bool complete = false;
        
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
        
        while(!complete)
        {
            
            for (unsigned int j = 0; j < (num_req / ber_test.get_dataword_len())+1; j++)
            {
                BER = ber_test.run_iteration(EbNo_dB);
                if(BER != 0.0)
                {
                    break;
                }
            }   
            //printf("BER: %f\n", BER);
            ber_test.reset_test();
            
            if(BER == 0.0)
            {
                complete = true;
                printf("Rate: %s, EbNo: %f\n", string_rate.c_str(), EbNo_dB);
            }
            else
            {
                EbNo_dB += EBNO_STEP;
                //printf("iterating ebno: %f\n", EbNo_dB);
            }
            
        }

    }
    
    /*
    gr.Plot(EbNo_db_array, BER_array, "+");
    gr.Label(BER_array, "%y", 0);
    
    sprintf(sbuff, "BER_LDPC_RATE%d_N%d_K%d.png",
            (int)rate, ber_test.get_codeword_len(),
            ber_test.get_dataword_len());
    gr.WriteFrame(sbuff); 
    */
    
    return 1;
}
