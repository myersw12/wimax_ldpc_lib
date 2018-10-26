#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <volk/volk.h>
#include <math.h>
#include <random>
#include <string>

#include <mgl2/qt.h>    
#include "BER_runner.h"
#include "capacity_curve_data.cc"

#define MAX_ITER 10
#define EBNO_STEP 0.01

using namespace wimax_ldpc_lib;

// put precomputed data into the right format for MGL
void fill_capacity_plots(mglData *shannon_rate, mglData *shannon_ebno,
                         mglData *bpsk_rate, mglData *bpsk_ebno)
{
 
    for(unsigned int i = 0; i < 2000; i++)
    {
     
        shannon_ebno->a[i] = shannon_cap_ebno[i];
        shannon_rate->a[i] = shannon_cap_rate[i];
        bpsk_ebno->a[i] = bpsk_cap_ebno[i];
        bpsk_rate->a[i] = bpsk_cap_rate[i];
        
    }
    
}


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
    mglData plot_rate;
    mglData plot_ebno;
    
    mglData shannon_rate;
    mglData shannon_ebno;
    
    mglData bpsk_rate;
    mglData bpsk_ebno;
    
    std::string string_rate;
    char sbuff [50];
    
    unsigned int ratelist[5] = {0, 1, 2, 3, 5};
    
    sprintf(sbuff, "WiMAX LDPC Code Performance\nN = %d", (unsigned int)((z/96.0)*2304));

    gr.Title(sbuff, "k:C", 7);
    
    gr.Label('x', "Eb/N0 [dB]", 0);
    gr.Label('y', "Capacity [bits/dimension]", 0);
    
    gr.Box();
    
    gr.SetRanges(-2, 10, 0, 1);
    
    gr.SetTicks('y', 0.25, .25, 0);
    gr.SetTicks('x', 1, -2, 0);
    
    gr.Axis();
    gr.Grid("xy", ":b");
    
    gr.AddLegend("Shannon Bound", "b");
    gr.AddLegend("BPSK-AWGN Bound", "g");
    gr.Legend(1);
    
    plot_rate.Create(5);
    plot_ebno.Create(5);
    
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
                plot_rate.a[i] = 0.5;
                break;
            }
            case (TWOTHIRDSA):
            {
                string_rate = "2/3A";
                plot_rate.a[i] = 0.67;
                break;
            }
            case (TWOTHIRDSB):
            {
                string_rate = "2/3B";
                plot_rate.a[i] = 0.67;
                break;
            }
            case (THREEQUARTERSA):
            {
                string_rate = "3/4A";
                plot_rate.a[i] = 0.75;
                break;
            }
            case (THREEQUARTERSB):
            {
                string_rate = "3/4B";
                plot_rate.a[i] = 0.75;
                break;
            }
            case (FIVESIXTHS):
            {
                string_rate = "5/6";
                plot_rate.a[i] = 0.83;
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
            // we are looking to find the Eb/No value where the BER is 
            // 1e-5.  The value of num_req is equal to the number of sequential bits
            // received without error that must pass in order to meet the 98% 
            // confidence requirement.  
            
            //Please see https://www.keysight.com/main/editorial.jspx?ckey=1481106&id=1481106&nid=-11143.0.00&lc=eng&cc=US
            // for a good explanation on how to calculate the number
            
            // if an error occurs before this number is met, then the Eb/No
            // value being used is too low and should be incremented up.
            // The test is restarted after each increment.
            for (unsigned int j = 0; j < (num_req / ber_test.get_codeword_len())+1; j++)
            {
                BER = ber_test.run_iteration(EbNo_dB);
                if(BER != 0.0)
                {
                    break;
                }
            }   
            
            ber_test.reset_test();
            
            // no errors, we made it past the threshold for 1e-5
            if(BER == 0.0)
            {
                complete = true;
                printf("Rate: %s, EbNo: %f\n", string_rate.c_str(), EbNo_dB);
                plot_ebno.a[i] = EbNo_dB;
            }
            else
            {
                EbNo_dB += EBNO_STEP;
            }
            
        }

    }
    
    shannon_rate.Create(2000);
    shannon_ebno.Create(2000);
    
    bpsk_rate.Create(2000);
    bpsk_ebno.Create(2000);
    
    fill_capacity_plots(&shannon_rate, &shannon_ebno, &bpsk_rate, &bpsk_ebno);
    
    gr.Plot(plot_ebno, plot_rate, " +r", "");
    gr.Label(plot_ebno, plot_rate, "\n  %y", 0);
    
    gr.Plot(shannon_ebno, shannon_rate, " -b", "");
    gr.Plot(bpsk_ebno, bpsk_rate, " -g", "");
    
    sprintf(sbuff, "CAP_LDPC_N%d.png", (unsigned int)((z/96.0)*2304));
    gr.WriteFrame(sbuff); 
    
    
    return 1;
}
