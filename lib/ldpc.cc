#include <stdio.h>

#include "ldpc.h"

ldpc::ldpc(coderate rate, unsigned int z_factor, unsigned int num_threads)
{
    m_num_threads = num_threads;
    
    m_z = z_factor;
    m_N = (m_z / 96.0) * BASE_LDPC_BLOCK_LEN;
    
    switch(rate) {
        
        case (HALFRATE):
        {
            m_M = m_N / 2;
            break;
        }
        
        case (TWOTHIRDSA):
        case (TWOTHIRDSB):
        {
            m_M = m_N - ((m_N * 2) / 3);
            break;
        }
        
        case (THREEQUARTERSA):
        case (THREEQUARTERSB):
        {
            m_M = m_N - ((m_N * 3) / 4);
            break;
        }
        
        case (FIVESIXTHS):
        {
            m_M = m_N - ((m_N * 5) / 6);
            break;
        }
        
        default:
        {
            printf("[!]ldpc_encoder - Invalid Coderate: %d\n", rate);
            break;
        }
    }
   
    set_checknode_array(rate, z_factor);
    
}

ldpc::~ldpc()
{
    
}

void ldpc::set_checknode_array(coderate rate, unsigned int z_factor)
{
    
    // get the correct check node array
    switch(z_factor) {
        
        case 24:
        {
            if (rate == HALFRATE)
            {
                m_checknode_array = (int16_t*) &wimax_576_0_5;
                m_row_size = sizeof(wimax_576_0_5) / sizeof(wimax_576_0_5[0]);
                m_col_size = sizeof(wimax_576_0_5[0]) / sizeof(int16_t);
            }
            else if (rate == TWOTHIRDSA)
            {
                m_checknode_array = (int16_t*) &wimax_576_0_66A;
                m_row_size = sizeof(wimax_576_0_66A) / sizeof(wimax_576_0_66A[0]);
                m_col_size = sizeof(wimax_576_0_66A[0]) / sizeof(int16_t);

            }
            else if (rate == TWOTHIRDSB){
                m_checknode_array = (int16_t*) &wimax_576_0_66B;
                m_row_size = sizeof(wimax_576_0_66B) / sizeof(wimax_576_0_66B[0]);
                m_col_size = sizeof(wimax_576_0_66B[0]) / sizeof(int16_t);
            }
            else if (rate == THREEQUARTERSA)
            {
                m_checknode_array = (int16_t*) &wimax_576_0_75A;
                m_row_size = sizeof(wimax_576_0_75A) / sizeof(wimax_576_0_75A[0]);
                m_col_size = sizeof(wimax_576_0_75A[0]) / sizeof(int16_t);
            }
            else if (rate == THREEQUARTERSB)
            {
                m_checknode_array = (int16_t*) &wimax_576_0_75B;
                m_row_size = sizeof(wimax_576_0_75B) / sizeof(wimax_576_0_75B[0]);
                m_col_size = sizeof(wimax_576_0_75B[0]) / sizeof(int16_t);
            }
            else if (rate == FIVESIXTHS)
            {
                m_checknode_array = (int16_t*) &wimax_576_0_83;
                m_row_size = sizeof(wimax_576_0_83) / sizeof(wimax_576_0_83);
                m_col_size = sizeof(wimax_576_0_83[0]) / sizeof(int16_t);
            }
            else
            {
                printf("[!]ldpc_encoder - Invalid Coderate: %d\n", rate);
                return;
            }
            break;
        }
       
        default:
        {
            printf("[!]ldpc_encoder - Invalid Z factor: %d\n", z_factor);
            break;
        }
    }
}

uint64_t ldpc::get_nanoseconds()
{
    uint64_t nanoseconds =
    std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::
                  now().time_since_epoch()).count();
        
    return nanoseconds;
}
