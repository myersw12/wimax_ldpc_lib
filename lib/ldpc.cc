#include <stdio.h>

#include "ldpc.h"

//#define DEBUG_INITIALIZATION

namespace wimax_ldpc_lib {
    
    ldpc::ldpc() {}
    
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
                throw std::exception();
                break;
            }
        }
    
        if(set_checknode_array(rate, z_factor) == 0)
            throw std::exception();
 
        #ifdef DEBUG_INITIALIZATION
        printf("m_N: %d\nm_M: %d\nm_z: %d\n", m_N, m_M, m_z);
        printf("m_row_size: %d\nm_col_size: %d\nm_D: %d\nm_X: %d\n", m_row_size, m_col_size, m_D, m_X);
        #endif       
    }

    ldpc::~ldpc()
    {
        
    }

    unsigned int ldpc::set_checknode_array(coderate rate, unsigned int z_factor)
    {
        
        // get the correct check node array
        switch(z_factor) {
            
            #ifdef Z_24
            case 24:
            {
                if (rate == HALFRATE)
                {
                    m_checknode_array = (int16_t*) &wimax_576_0_5;
                    m_row_size = sizeof(wimax_576_0_5) / sizeof(wimax_576_0_5[0]);
                    m_col_size = sizeof(wimax_576_0_5[0]) / sizeof(int16_t);
                    m_D = wimax_576_0_5_D;
                    m_X = wimax_576_0_5_X;
                }
                else if (rate == TWOTHIRDSA)
                {
                    m_checknode_array = (int16_t*) &wimax_576_0_66A;
                    m_row_size = sizeof(wimax_576_0_66A) / sizeof(wimax_576_0_66A[0]);
                    m_col_size = sizeof(wimax_576_0_66A[0]) / sizeof(int16_t);
                    m_D = wimax_576_0_66A_D;
                    m_X = wimax_576_0_66A_X;

                }
                else if (rate == TWOTHIRDSB){
                    m_checknode_array = (int16_t*) &wimax_576_0_66B;
                    m_row_size = sizeof(wimax_576_0_66B) / sizeof(wimax_576_0_66B[0]);
                    m_col_size = sizeof(wimax_576_0_66B[0]) / sizeof(int16_t);
                    m_D = wimax_576_0_66B_D;
                    m_X = wimax_576_0_66B_X;
                }
                else if (rate == THREEQUARTERSA)
                {
                    m_checknode_array = (int16_t*) &wimax_576_0_75A;
                    m_row_size = sizeof(wimax_576_0_75A) / sizeof(wimax_576_0_75A[0]);
                    m_col_size = sizeof(wimax_576_0_75A[0]) / sizeof(int16_t);
                    m_D = wimax_576_0_75A_D;
                    m_X = wimax_576_0_75A_X;
                }
                else if (rate == THREEQUARTERSB)
                {
                    m_checknode_array = (int16_t*) &wimax_576_0_75B;
                    m_row_size = sizeof(wimax_576_0_75B) / sizeof(wimax_576_0_75B[0]);
                    m_col_size = sizeof(wimax_576_0_75B[0]) / sizeof(int16_t);
                    m_D = wimax_576_0_75B_D;
                    m_X = wimax_576_0_75B_X;
                }
                else if (rate == FIVESIXTHS)
                {
                    m_checknode_array = (int16_t*) &wimax_576_0_83;
                    m_row_size = sizeof(wimax_576_0_83) / sizeof(wimax_576_0_83[0]);
                    m_col_size = sizeof(wimax_576_0_83[0]) / sizeof(int16_t);
                    m_D = wimax_576_0_83_D;
                    m_X = wimax_576_0_83_X;
                }
                else
                {
                    printf("[!]ldpc_encoder - Invalid Coderate: %d\n", rate);
                    return 0;
                }
                break;
            }
            #endif
            
            #ifdef Z_28
            case 28:
            {
                if (rate == HALFRATE)
                {
                    m_checknode_array = (int16_t*) &wimax_672_0_5;
                    m_row_size = sizeof(wimax_672_0_5) / sizeof(wimax_672_0_5[0]);
                    m_col_size = sizeof(wimax_672_0_5[0]) / sizeof(int16_t);
                    m_D = wimax_672_0_5_D;
                    m_X = wimax_672_0_5_X;
                }
                else if (rate == TWOTHIRDSA)
                {
                    m_checknode_array = (int16_t*) &wimax_672_0_66A;
                    m_row_size = sizeof(wimax_672_0_66A) / sizeof(wimax_672_0_66A[0]);
                    m_col_size = sizeof(wimax_672_0_66A[0]) / sizeof(int16_t);
                    m_D = wimax_672_0_66A_D;
                    m_X = wimax_672_0_66A_X;

                }
                else if (rate == TWOTHIRDSB){
                    m_checknode_array = (int16_t*) &wimax_672_0_66B;
                    m_row_size = sizeof(wimax_672_0_66B) / sizeof(wimax_672_0_66B[0]);
                    m_col_size = sizeof(wimax_672_0_66B[0]) / sizeof(int16_t);
                    m_D = wimax_672_0_66B_D;
                    m_X = wimax_672_0_66B_X;
                }
                else if (rate == THREEQUARTERSA)
                {
                    m_checknode_array = (int16_t*) &wimax_672_0_75A;
                    m_row_size = sizeof(wimax_672_0_75A) / sizeof(wimax_672_0_75A[0]);
                    m_col_size = sizeof(wimax_672_0_75A[0]) / sizeof(int16_t);
                    m_D = wimax_672_0_75A_D;
                    m_X = wimax_672_0_75A_X;
                }
                else if (rate == THREEQUARTERSB)
                {
                    m_checknode_array = (int16_t*) &wimax_672_0_75B;
                    m_row_size = sizeof(wimax_672_0_75B) / sizeof(wimax_672_0_75B[0]);
                    m_col_size = sizeof(wimax_672_0_75B[0]) / sizeof(int16_t);
                    m_D = wimax_672_0_75B_D;
                    m_X = wimax_672_0_75B_X;
                }
                else if (rate == FIVESIXTHS)
                {
                    m_checknode_array = (int16_t*) &wimax_672_0_83;
                    m_row_size = sizeof(wimax_672_0_83) / sizeof(wimax_672_0_83[0]);
                    m_col_size = sizeof(wimax_672_0_83[0]) / sizeof(int16_t);
                    m_D = wimax_672_0_83_D;
                    m_X = wimax_672_0_83_X;
                }
                else
                {
                    printf("[!]ldpc_encoder - Invalid Coderate: %d\n", rate);
                    return 0;
                }
                break;
            }
            #endif
            
            #ifdef Z_32
            case 32:
            {
                if (rate == HALFRATE)
                {
                    m_checknode_array = (int16_t*) &wimax_768_0_5;
                    m_row_size = sizeof(wimax_768_0_5) / sizeof(wimax_768_0_5[0]);
                    m_col_size = sizeof(wimax_768_0_5[0]) / sizeof(int16_t);
                    m_D = wimax_768_0_5_D;
                    m_X = wimax_768_0_5_X;
                }
                else if (rate == TWOTHIRDSA)
                {
                    m_checknode_array = (int16_t*) &wimax_768_0_66A;
                    m_row_size = sizeof(wimax_768_0_66A) / sizeof(wimax_768_0_66A[0]);
                    m_col_size = sizeof(wimax_768_0_66A[0]) / sizeof(int16_t);
                    m_D = wimax_768_0_66A_D;
                    m_X = wimax_768_0_66A_X;
                }
                else if (rate == TWOTHIRDSB){
                    m_checknode_array = (int16_t*) &wimax_768_0_66B;
                    m_row_size = sizeof(wimax_768_0_66B) / sizeof(wimax_768_0_66B[0]);
                    m_col_size = sizeof(wimax_768_0_66B[0]) / sizeof(int16_t);
                    m_D = wimax_768_0_66B_D;
                    m_X = wimax_768_0_66B_X;
                }
                else if (rate == THREEQUARTERSA)
                {
                    m_checknode_array = (int16_t*) &wimax_768_0_75A;
                    m_row_size = sizeof(wimax_768_0_75A) / sizeof(wimax_768_0_75A[0]);
                    m_col_size = sizeof(wimax_768_0_75A[0]) / sizeof(int16_t);
                    m_D = wimax_768_0_75A_D;
                    m_X = wimax_768_0_75A_X;
                }
                else if (rate == THREEQUARTERSB)
                {
                    m_checknode_array = (int16_t*) &wimax_768_0_75B;
                    m_row_size = sizeof(wimax_768_0_75B) / sizeof(wimax_768_0_75B[0]);
                    m_col_size = sizeof(wimax_768_0_75B[0]) / sizeof(int16_t);
                    m_D = wimax_768_0_75B_D;
                    m_X = wimax_768_0_75B_X;
                }
                else if (rate == FIVESIXTHS)
                {
                    m_checknode_array = (int16_t*) &wimax_768_0_83;
                    m_row_size = sizeof(wimax_768_0_83) / sizeof(wimax_768_0_83[0]);
                    m_col_size = sizeof(wimax_768_0_83[0]) / sizeof(int16_t);
                    m_D = wimax_768_0_83_D;
                    m_X = wimax_768_0_83_X;
                }
                else
                {
                    printf("[!]ldpc_encoder - Invalid Coderate: %d\n", rate);
                    return 0;
                }
                break;
            }
            #endif
            
            #ifdef Z_36
            case 36:
            {
                if (rate == HALFRATE)
                {
                    m_checknode_array = (int16_t*) &wimax_864_0_5;
                    m_row_size = sizeof(wimax_864_0_5) / sizeof(wimax_864_0_5[0]);
                    m_col_size = sizeof(wimax_864_0_5[0]) / sizeof(int16_t);
                    m_D = wimax_864_0_5_D;
                    m_X = wimax_864_0_5_X;
                }
                else if (rate == TWOTHIRDSA)
                {
                    m_checknode_array = (int16_t*) &wimax_864_0_66A;
                    m_row_size = sizeof(wimax_864_0_66A) / sizeof(wimax_864_0_66A[0]);
                    m_col_size = sizeof(wimax_864_0_66A[0]) / sizeof(int16_t);
                    m_D = wimax_864_0_66A_D;
                    m_X = wimax_864_0_66A_X;
                }
                else if (rate == TWOTHIRDSB){
                    m_checknode_array = (int16_t*) &wimax_864_0_66B;
                    m_row_size = sizeof(wimax_864_0_66B) / sizeof(wimax_864_0_66B[0]);
                    m_col_size = sizeof(wimax_864_0_66B[0]) / sizeof(int16_t);
                    m_D = wimax_864_0_66B_D;
                    m_X = wimax_864_0_66B_X;
                }
                else if (rate == THREEQUARTERSA)
                {
                    m_checknode_array = (int16_t*) &wimax_864_0_75A;
                    m_row_size = sizeof(wimax_864_0_75A) / sizeof(wimax_864_0_75A[0]);
                    m_col_size = sizeof(wimax_864_0_75A[0]) / sizeof(int16_t);
                    m_D = wimax_864_0_75A_D;
                    m_X = wimax_864_0_75A_X;
                }
                else if (rate == THREEQUARTERSB)
                {
                    m_checknode_array = (int16_t*) &wimax_864_0_75B;
                    m_row_size = sizeof(wimax_864_0_75B) / sizeof(wimax_864_0_75B[0]);
                    m_col_size = sizeof(wimax_864_0_75B[0]) / sizeof(int16_t);
                    m_D = wimax_864_0_75B_D;
                    m_X = wimax_864_0_75B_X;
                }
                else if (rate == FIVESIXTHS)
                {
                    m_checknode_array = (int16_t*) &wimax_864_0_83;
                    m_row_size = sizeof(wimax_864_0_83) / sizeof(wimax_864_0_83[0]);
                    m_col_size = sizeof(wimax_864_0_83[0]) / sizeof(int16_t);
                    m_D = wimax_864_0_83_D;
                    m_X = wimax_864_0_83_X;
                }
                else
                {
                    printf("[!]ldpc_encoder - Invalid Coderate: %d\n", rate);
                    return 0;
                }
                break;
            }    
            #endif
            
            #ifdef Z_40
            case 40:
            {
                if (rate == HALFRATE)
                {
                    m_checknode_array = (int16_t*) &wimax_960_0_5;
                    m_row_size = sizeof(wimax_960_0_5) / sizeof(wimax_960_0_5[0]);
                    m_col_size = sizeof(wimax_960_0_5[0]) / sizeof(int16_t);
                    m_D = wimax_960_0_5_D;
                    m_X = wimax_960_0_5_X;
                }
                else if (rate == TWOTHIRDSA)
                {
                    m_checknode_array = (int16_t*) &wimax_960_0_66A;
                    m_row_size = sizeof(wimax_960_0_66A) / sizeof(wimax_960_0_66A[0]);
                    m_col_size = sizeof(wimax_960_0_66A[0]) / sizeof(int16_t);
                    m_D = wimax_960_0_66A_D;
                    m_X = wimax_960_0_66A_X;
                }
                else if (rate == TWOTHIRDSB){
                    m_checknode_array = (int16_t*) &wimax_960_0_66B;
                    m_row_size = sizeof(wimax_960_0_66B) / sizeof(wimax_960_0_66B[0]);
                    m_col_size = sizeof(wimax_960_0_66B[0]) / sizeof(int16_t);
                    m_D = wimax_960_0_66B_D;
                    m_X = wimax_960_0_66B_X;
                }
                else if (rate == THREEQUARTERSA)
                {
                    m_checknode_array = (int16_t*) &wimax_960_0_75A;
                    m_row_size = sizeof(wimax_960_0_75A) / sizeof(wimax_960_0_75A[0]);
                    m_col_size = sizeof(wimax_960_0_75A[0]) / sizeof(int16_t);
                    m_D = wimax_960_0_75A_D;
                    m_X = wimax_960_0_75A_X;
                }
                else if (rate == THREEQUARTERSB)
                {
                    m_checknode_array = (int16_t*) &wimax_960_0_75B;
                    m_row_size = sizeof(wimax_960_0_75B) / sizeof(wimax_960_0_75B[0]);
                    m_col_size = sizeof(wimax_960_0_75B[0]) / sizeof(int16_t);
                    m_D = wimax_960_0_75B_D;
                    m_X = wimax_960_0_75B_X;
                }
                else if (rate == FIVESIXTHS)
                {
                    m_checknode_array = (int16_t*) &wimax_960_0_83;
                    m_row_size = sizeof(wimax_960_0_83) / sizeof(wimax_960_0_83[0]);
                    m_col_size = sizeof(wimax_960_0_83[0]) / sizeof(int16_t);
                    m_D = wimax_960_0_83_D;
                    m_X = wimax_960_0_83_X;
                }
                else
                {
                    printf("[!]ldpc_encoder - Invalid Coderate: %d\n", rate);
                    return 0;
                }
                break;
            }
            #endif
            
            #ifdef Z_44
            case 44:
            {
                if (rate == HALFRATE)
                {
                    m_checknode_array = (int16_t*) &wimax_1056_0_5;
                    m_row_size = sizeof(wimax_1056_0_5) / sizeof(wimax_1056_0_5[0]);
                    m_col_size = sizeof(wimax_1056_0_5[0]) / sizeof(int16_t);
                    m_D = wimax_1056_0_5_D;
                    m_X = wimax_1056_0_5_X;
                }
                else if (rate == TWOTHIRDSA)
                {
                    m_checknode_array = (int16_t*) &wimax_1056_0_66A;
                    m_row_size = sizeof(wimax_1056_0_66A) / sizeof(wimax_1056_0_66A[0]);
                    m_col_size = sizeof(wimax_1056_0_66A[0]) / sizeof(int16_t);
                    m_D = wimax_1056_0_66A_D;
                    m_X = wimax_1056_0_66A_X;
                }
                else if (rate == TWOTHIRDSB){
                    m_checknode_array = (int16_t*) &wimax_1056_0_66B;
                    m_row_size = sizeof(wimax_1056_0_66B) / sizeof(wimax_1056_0_66B[0]);
                    m_col_size = sizeof(wimax_1056_0_66B[0]) / sizeof(int16_t);
                    m_D = wimax_1056_0_66B_D;
                    m_X = wimax_1056_0_66B_X;
                }
                else if (rate == THREEQUARTERSA)
                {
                    m_checknode_array = (int16_t*) &wimax_1056_0_75A;
                    m_row_size = sizeof(wimax_1056_0_75A) / sizeof(wimax_1056_0_75A[0]);
                    m_col_size = sizeof(wimax_1056_0_75A[0]) / sizeof(int16_t);
                    m_D = wimax_1056_0_75A_D;
                    m_X = wimax_1056_0_75A_X;
                }
                else if (rate == THREEQUARTERSB)
                {
                    m_checknode_array = (int16_t*) &wimax_1056_0_75B;
                    m_row_size = sizeof(wimax_1056_0_75B) / sizeof(wimax_1056_0_75B[0]);
                    m_col_size = sizeof(wimax_1056_0_75B[0]) / sizeof(int16_t);
                    m_D = wimax_1056_0_75B_D;
                    m_X = wimax_1056_0_75B_X;
                }
                else if (rate == FIVESIXTHS)
                {
                    m_checknode_array = (int16_t*) &wimax_1056_0_83;
                    m_row_size = sizeof(wimax_1056_0_83) / sizeof(wimax_1056_0_83[0]);
                    m_col_size = sizeof(wimax_1056_0_83[0]) / sizeof(int16_t);
                    m_D = wimax_1056_0_83_D;
                    m_X = wimax_1056_0_83_X;
                }
                else
                {
                    printf("[!]ldpc_encoder - Invalid Coderate: %d\n", rate);
                    return 0;
                }
                break;
            }
            #endif
            
            #ifdef Z_48
            case 48:
            {
                if (rate == HALFRATE)
                {
                    m_checknode_array = (int16_t*) &wimax_1152_0_5;
                    m_row_size = sizeof(wimax_1152_0_5) / sizeof(wimax_1152_0_5[0]);
                    m_col_size = sizeof(wimax_1152_0_5[0]) / sizeof(int16_t);
                    m_D = wimax_1152_0_5_D;
                    m_X = wimax_1152_0_5_X;
                }
                else if (rate == TWOTHIRDSA)
                {
                    m_checknode_array = (int16_t*) &wimax_1152_0_66A;
                    m_row_size = sizeof(wimax_1152_0_66A) / sizeof(wimax_1152_0_66A[0]);
                    m_col_size = sizeof(wimax_1152_0_66A[0]) / sizeof(int16_t);
                    m_D = wimax_1152_0_66A_D;
                    m_X = wimax_1152_0_66A_X;
                }
                else if (rate == TWOTHIRDSB){
                    m_checknode_array = (int16_t*) &wimax_1152_0_66B;
                    m_row_size = sizeof(wimax_1152_0_66B) / sizeof(wimax_1152_0_66B[0]);
                    m_col_size = sizeof(wimax_1152_0_66B[0]) / sizeof(int16_t);
                    m_D = wimax_1152_0_66B_D;
                    m_X = wimax_1152_0_66B_X;
                }
                else if (rate == THREEQUARTERSA)
                {
                    m_checknode_array = (int16_t*) &wimax_1152_0_75A;
                    m_row_size = sizeof(wimax_1152_0_75A) / sizeof(wimax_1152_0_75A[0]);
                    m_col_size = sizeof(wimax_1152_0_75A[0]) / sizeof(int16_t);
                    m_D = wimax_1152_0_75A_D;
                    m_X = wimax_1152_0_75A_X;
                }
                else if (rate == THREEQUARTERSB)
                {
                    m_checknode_array = (int16_t*) &wimax_1152_0_75B;
                    m_row_size = sizeof(wimax_1152_0_75B) / sizeof(wimax_1152_0_75B[0]);
                    m_col_size = sizeof(wimax_1152_0_75B[0]) / sizeof(int16_t);
                    m_D = wimax_1152_0_75B_D;
                    m_X = wimax_1152_0_75B_X;
                }
                else if (rate == FIVESIXTHS)
                {
                    m_checknode_array = (int16_t*) &wimax_1152_0_83;
                    m_row_size = sizeof(wimax_1152_0_83) / sizeof(wimax_1152_0_83[0]);
                    m_col_size = sizeof(wimax_1152_0_83[0]) / sizeof(int16_t);
                    m_D = wimax_1152_0_83_D;
                    m_X = wimax_1152_0_83_X;
                }
                else
                {
                    printf("[!]ldpc_encoder - Invalid Coderate: %d\n", rate);
                    return 0;
                }
                break;
            }
            #endif
            
            #ifdef Z_52
            case 52:
            {
                if (rate == HALFRATE)
                {
                    m_checknode_array = (int16_t*) &wimax_1248_0_5;
                    m_row_size = sizeof(wimax_1248_0_5) / sizeof(wimax_1248_0_5[0]);
                    m_col_size = sizeof(wimax_1248_0_5[0]) / sizeof(int16_t);
                    m_D = wimax_1248_0_5_D;
                    m_X = wimax_1248_0_5_X;
                }
                else if (rate == TWOTHIRDSA)
                {
                    m_checknode_array = (int16_t*) &wimax_1248_0_66A;
                    m_row_size = sizeof(wimax_1248_0_66A) / sizeof(wimax_1248_0_66A[0]);
                    m_col_size = sizeof(wimax_1248_0_66A[0]) / sizeof(int16_t);
                    m_D = wimax_1248_0_66A_D;
                    m_X = wimax_1248_0_66A_X;
                }
                else if (rate == TWOTHIRDSB){
                    m_checknode_array = (int16_t*) &wimax_1248_0_66B;
                    m_row_size = sizeof(wimax_1248_0_66B) / sizeof(wimax_1248_0_66B[0]);
                    m_col_size = sizeof(wimax_1248_0_66B[0]) / sizeof(int16_t);
                    m_D = wimax_1248_0_66B_D;
                    m_X = wimax_1248_0_66B_X;
                }
                else if (rate == THREEQUARTERSA)
                {
                    m_checknode_array = (int16_t*) &wimax_1248_0_75A;
                    m_row_size = sizeof(wimax_1248_0_75A) / sizeof(wimax_1248_0_75A[0]);
                    m_col_size = sizeof(wimax_1248_0_75A[0]) / sizeof(int16_t);
                    m_D = wimax_1248_0_75A_D;
                    m_X = wimax_1248_0_75A_X;
                }
                else if (rate == THREEQUARTERSB)
                {
                    m_checknode_array = (int16_t*) &wimax_1248_0_75B;
                    m_row_size = sizeof(wimax_1248_0_75B) / sizeof(wimax_1248_0_75B[0]);
                    m_col_size = sizeof(wimax_1248_0_75B[0]) / sizeof(int16_t);
                    m_D = wimax_1248_0_75B_D;
                    m_X = wimax_1248_0_75B_X;
                }
                else if (rate == FIVESIXTHS)
                {
                    m_checknode_array = (int16_t*) &wimax_1248_0_83;
                    m_row_size = sizeof(wimax_1248_0_83) / sizeof(wimax_1248_0_83[0]);
                    m_col_size = sizeof(wimax_1248_0_83[0]) / sizeof(int16_t);
                    m_D = wimax_1248_0_83_D;
                    m_X = wimax_1248_0_83_X;
                }
                else
                {
                    printf("[!]ldpc_encoder - Invalid Coderate: %d\n", rate);
                    return 0;
                }
                break;
            }
            #endif

            #ifdef Z_56
            case 56:
            {
                if (rate == HALFRATE)
                {
                    m_checknode_array = (int16_t*) &wimax_1344_0_5;
                    m_row_size = sizeof(wimax_1344_0_5) / sizeof(wimax_1344_0_5[0]);
                    m_col_size = sizeof(wimax_1344_0_5[0]) / sizeof(int16_t);
                    m_D = wimax_1344_0_5_D;
                    m_X = wimax_1344_0_5_X;
                }
                else if (rate == TWOTHIRDSA)
                {
                    m_checknode_array = (int16_t*) &wimax_1344_0_66A;
                    m_row_size = sizeof(wimax_1344_0_66A) / sizeof(wimax_1344_0_66A[0]);
                    m_col_size = sizeof(wimax_1344_0_66A[0]) / sizeof(int16_t);
                    m_D = wimax_1344_0_66A_D;
                    m_X = wimax_1344_0_66A_X;
                }
                else if (rate == TWOTHIRDSB){
                    m_checknode_array = (int16_t*) &wimax_1344_0_66B;
                    m_row_size = sizeof(wimax_1344_0_66B) / sizeof(wimax_1344_0_66B[0]);
                    m_col_size = sizeof(wimax_1344_0_66B[0]) / sizeof(int16_t);
                    m_D = wimax_1344_0_66B_D;
                    m_X = wimax_1344_0_66B_X;
                }
                else if (rate == THREEQUARTERSA)
                {
                    m_checknode_array = (int16_t*) &wimax_1344_0_75A;
                    m_row_size = sizeof(wimax_1344_0_75A) / sizeof(wimax_1344_0_75A[0]);
                    m_col_size = sizeof(wimax_1344_0_75A[0]) / sizeof(int16_t);
                    m_D = wimax_1344_0_75A_D;
                    m_X = wimax_1344_0_75A_X;
                }
                else if (rate == THREEQUARTERSB)
                {
                    m_checknode_array = (int16_t*) &wimax_1344_0_75B;
                    m_row_size = sizeof(wimax_1344_0_75B) / sizeof(wimax_1344_0_75B[0]);
                    m_col_size = sizeof(wimax_1344_0_75B[0]) / sizeof(int16_t);
                    m_D = wimax_1344_0_75B_D;
                    m_X = wimax_1344_0_75B_X;
                }
                else if (rate == FIVESIXTHS)
                {        
                    m_checknode_array = (int16_t*) &wimax_1344_0_83;
                    m_row_size = sizeof(wimax_1344_0_83) / sizeof(wimax_1344_0_83[0]);
                    m_col_size = sizeof(wimax_1344_0_83[0]) / sizeof(int16_t);
                    m_D = wimax_1344_0_83_D;
                    m_X = wimax_1344_0_83_X;
                }
                else
                {
                    printf("[!]ldpc_encoder - Invalid Coderate: %d\n", rate);
                    return 0;
                }
                break;
            }
            #endif
            
            #ifdef Z_60
            case 60:
            {
                if (rate == HALFRATE)
                {
                    m_checknode_array = (int16_t*) &wimax_1440_0_5;
                    m_row_size = sizeof(wimax_1440_0_5) / sizeof(wimax_1440_0_5[0]);
                    m_col_size = sizeof(wimax_1440_0_5[0]) / sizeof(int16_t);
                    m_D = wimax_1440_0_5_D;
                    m_X = wimax_1440_0_5_X;
                }
                else if (rate == TWOTHIRDSA)
                {
                    m_checknode_array = (int16_t*) &wimax_1440_0_66A;
                    m_row_size = sizeof(wimax_1440_0_66A) / sizeof(wimax_1440_0_66A[0]);
                    m_col_size = sizeof(wimax_1440_0_66A[0]) / sizeof(int16_t);
                    m_D = wimax_1440_0_66A_D;
                    m_X = wimax_1440_0_66A_X;
                }
                else if (rate == TWOTHIRDSB){
                    m_checknode_array = (int16_t*) &wimax_1440_0_66B;
                    m_row_size = sizeof(wimax_1440_0_66B) / sizeof(wimax_1440_0_66B[0]);
                    m_col_size = sizeof(wimax_1440_0_66B[0]) / sizeof(int16_t);
                    m_D = wimax_1440_0_66B_D;
                    m_X = wimax_1440_0_66B_X;
                }
                else if (rate == THREEQUARTERSA)
                {
                    m_checknode_array = (int16_t*) &wimax_1440_0_75A;
                    m_row_size = sizeof(wimax_1440_0_75A) / sizeof(wimax_1440_0_75A[0]);
                    m_col_size = sizeof(wimax_1440_0_75A[0]) / sizeof(int16_t);
                    m_D = wimax_1440_0_75A_D;
                    m_X = wimax_1440_0_75A_X;
                }
                else if (rate == THREEQUARTERSB)
                {
                    m_checknode_array = (int16_t*) &wimax_1440_0_75B;
                    m_row_size = sizeof(wimax_1440_0_75B) / sizeof(wimax_1440_0_75B[0]);
                    m_col_size = sizeof(wimax_1440_0_75B[0]) / sizeof(int16_t);
                    m_D = wimax_1440_0_75B_D;
                    m_X = wimax_1440_0_75B_X;
                }
                else if (rate == FIVESIXTHS)
                {
                    m_checknode_array = (int16_t*) &wimax_1440_0_83;
                    m_row_size = sizeof(wimax_1440_0_83) / sizeof(wimax_1440_0_83[0]);
                    m_col_size = sizeof(wimax_1440_0_83[0]) / sizeof(int16_t);
                    m_D = wimax_1440_0_83_D;
                    m_X = wimax_1440_0_83_X;
                }
                else
                {
                    printf("[!]ldpc_encoder - Invalid Coderate: %d\n", rate);
                    return 0;
                }
                break;
            }
            #endif
            
            #ifdef Z_64
            case 64:
            {
                if (rate == HALFRATE)
                {
                    m_checknode_array = (int16_t*) &wimax_1536_0_5;
                    m_row_size = sizeof(wimax_1536_0_5) / sizeof(wimax_1536_0_5[0]);
                    m_col_size = sizeof(wimax_1536_0_5[0]) / sizeof(int16_t);
                    m_D = wimax_1536_0_5_D;
                    m_X = wimax_1536_0_5_X;
                }
                else if (rate == TWOTHIRDSA)
                {
                    m_checknode_array = (int16_t*) &wimax_1536_0_66A;
                    m_row_size = sizeof(wimax_1536_0_66A) / sizeof(wimax_1536_0_66A[0]);
                    m_col_size = sizeof(wimax_1536_0_66A[0]) / sizeof(int16_t);
                    m_D = wimax_1536_0_66A_D;
                    m_X = wimax_1536_0_66A_X;
                }
                else if (rate == TWOTHIRDSB){
                    m_checknode_array = (int16_t*) &wimax_1536_0_66B;
                    m_row_size = sizeof(wimax_1536_0_66B) / sizeof(wimax_1536_0_66B[0]);
                    m_col_size = sizeof(wimax_1536_0_66B[0]) / sizeof(int16_t);
                    m_D = wimax_1536_0_66B_D;
                    m_X = wimax_1536_0_66B_X;
                }
                else if (rate == THREEQUARTERSA)
                {
                    m_checknode_array = (int16_t*) &wimax_1536_0_75A;
                    m_row_size = sizeof(wimax_1536_0_75A) / sizeof(wimax_1536_0_75A[0]);
                    m_col_size = sizeof(wimax_1536_0_75A[0]) / sizeof(int16_t);
                    m_D = wimax_1536_0_75A_D;
                    m_X = wimax_1536_0_75A_X;
                }
                else if (rate == THREEQUARTERSB)
                {
                    m_checknode_array = (int16_t*) &wimax_1536_0_75B;
                    m_row_size = sizeof(wimax_1536_0_75B) / sizeof(wimax_1536_0_75B[0]);
                    m_col_size = sizeof(wimax_1536_0_75B[0]) / sizeof(int16_t);
                    m_D = wimax_1536_0_75B_D;
                    m_X = wimax_1536_0_75B_X;
                }
                else if (rate == FIVESIXTHS)
                {
                    m_checknode_array = (int16_t*) &wimax_1536_0_83;
                    m_row_size = sizeof(wimax_1536_0_83) / sizeof(wimax_1536_0_83[0]);
                    m_col_size = sizeof(wimax_1536_0_83[0]) / sizeof(int16_t);
                    m_D = wimax_1536_0_83_D;
                    m_X = wimax_1536_0_83_X;
                }
                else
                {
                    printf("[!]ldpc_encoder - Invalid Coderate: %d\n", rate);
                    return 0;
                }
                break;
            }
            #endif
            
            #ifdef Z_68
            case 68:
            {
                if (rate == HALFRATE)
                {
                    m_checknode_array = (int16_t*) &wimax_1632_0_5;
                    m_row_size = sizeof(wimax_1632_0_5) / sizeof(wimax_1632_0_5[0]);
                    m_col_size = sizeof(wimax_1632_0_5[0]) / sizeof(int16_t);
                    m_D = wimax_1632_0_5_D;
                    m_X = wimax_1632_0_5_X;
                }
                else if (rate == TWOTHIRDSA)
                {
                    m_checknode_array = (int16_t*) &wimax_1632_0_66A;
                    m_row_size = sizeof(wimax_1632_0_66A) / sizeof(wimax_1632_0_66A[0]);
                    m_col_size = sizeof(wimax_1632_0_66A[0]) / sizeof(int16_t);
                    m_D = wimax_1632_0_66A_D;
                    m_X = wimax_1632_0_66A_X;
                }
                else if (rate == TWOTHIRDSB){
                    m_checknode_array = (int16_t*) &wimax_1632_0_66B;
                    m_row_size = sizeof(wimax_1632_0_66B) / sizeof(wimax_1632_0_66B[0]);
                    m_col_size = sizeof(wimax_1632_0_66B[0]) / sizeof(int16_t);
                    m_D = wimax_1632_0_66B_D;
                    m_X = wimax_1632_0_66B_X;
                }
                else if (rate == THREEQUARTERSA)
                {
                    m_checknode_array = (int16_t*) &wimax_1632_0_75A;
                    m_row_size = sizeof(wimax_1632_0_75A) / sizeof(wimax_1632_0_75A[0]);
                    m_col_size = sizeof(wimax_1632_0_75A[0]) / sizeof(int16_t);
                    m_D = wimax_1632_0_75A_D;
                    m_X = wimax_1632_0_75A_X;
                }
                else if (rate == THREEQUARTERSB)
                {
                    m_checknode_array = (int16_t*) &wimax_1632_0_75B;
                    m_row_size = sizeof(wimax_1632_0_75B) / sizeof(wimax_1632_0_75B[0]);
                    m_col_size = sizeof(wimax_1632_0_75B[0]) / sizeof(int16_t);
                    m_D = wimax_1632_0_75B_D;
                    m_X = wimax_1632_0_75B_X;
                }
                else if (rate == FIVESIXTHS)
                {
                    m_checknode_array = (int16_t*) &wimax_1632_0_83;
                    m_row_size = sizeof(wimax_1632_0_83) / sizeof(wimax_1632_0_83[0]);
                    m_col_size = sizeof(wimax_1632_0_83[0]) / sizeof(int16_t);
                    m_D = wimax_1632_0_83_D;
                    m_X = wimax_1632_0_83_X;
                }
                else
                {
                    printf("[!]ldpc_encoder - Invalid Coderate: %d\n", rate);
                    return 0;
                }
                break;
            }
            #endif
            
            #ifdef Z_72
            case 72:
            {
                if (rate == HALFRATE)
                {
                    m_checknode_array = (int16_t*) &wimax_1728_0_5;
                    m_row_size = sizeof(wimax_1728_0_5) / sizeof(wimax_1728_0_5[0]);
                    m_col_size = sizeof(wimax_1728_0_5[0]) / sizeof(int16_t);
                    m_D = wimax_1728_0_5_D;
                    m_X = wimax_1728_0_5_X;
                }
                else if (rate == TWOTHIRDSA)
                {
                    m_checknode_array = (int16_t*) &wimax_1728_0_66A;
                    m_row_size = sizeof(wimax_1728_0_66A) / sizeof(wimax_1728_0_66A[0]);
                    m_col_size = sizeof(wimax_1728_0_66A[0]) / sizeof(int16_t);
                    m_D = wimax_1728_0_66A_D;
                    m_X = wimax_1728_0_66A_X;
                }
                else if (rate == TWOTHIRDSB){
                    m_checknode_array = (int16_t*) &wimax_1728_0_66B;
                    m_row_size = sizeof(wimax_1728_0_66B) / sizeof(wimax_1728_0_66B[0]);
                    m_col_size = sizeof(wimax_1728_0_66B[0]) / sizeof(int16_t);
                    m_D = wimax_1728_0_66B_D;
                    m_X = wimax_1728_0_66B_X;
                }
                else if (rate == THREEQUARTERSA)
                {
                    m_checknode_array = (int16_t*) &wimax_1728_0_75A;
                    m_row_size = sizeof(wimax_1728_0_75A) / sizeof(wimax_1728_0_75A[0]);
                    m_col_size = sizeof(wimax_1728_0_75A[0]) / sizeof(int16_t);
                    m_D = wimax_1728_0_75A_D;
                    m_X = wimax_1728_0_75A_X;
                }
                else if (rate == THREEQUARTERSB)
                {
                    m_checknode_array = (int16_t*) &wimax_1728_0_75B;
                    m_row_size = sizeof(wimax_1728_0_75B) / sizeof(wimax_1728_0_75B[0]);
                    m_col_size = sizeof(wimax_1728_0_75B[0]) / sizeof(int16_t);
                    m_D = wimax_1728_0_75B_D;
                    m_X = wimax_1728_0_75B_X;
                }
                else if (rate == FIVESIXTHS)
                {
                    m_checknode_array = (int16_t*) &wimax_1728_0_83;
                    m_row_size = sizeof(wimax_1728_0_83) / sizeof(wimax_1728_0_83[0]);
                    m_col_size = sizeof(wimax_1728_0_83[0]) / sizeof(int16_t);
                    m_D = wimax_1728_0_83_D;
                    m_X = wimax_1728_0_83_X;
                }
                else
                {
                    printf("[!]ldpc_encoder - Invalid Coderate: %d\n", rate);
                    return 0;
                }
                break;
            }
            #endif
            
            #ifdef Z_76 
            case 76:
            {
                if (rate == HALFRATE)
                {
                    m_checknode_array = (int16_t*) &wimax_1824_0_5;
                    m_row_size = sizeof(wimax_1824_0_5) / sizeof(wimax_1824_0_5[0]);
                    m_col_size = sizeof(wimax_1824_0_5[0]) / sizeof(int16_t);
                    m_D = wimax_1824_0_5_D;
                    m_X = wimax_1824_0_5_X;
                }
                else if (rate == TWOTHIRDSA)
                {
                    m_checknode_array = (int16_t*) &wimax_1824_0_66A;
                    m_row_size = sizeof(wimax_1824_0_66A) / sizeof(wimax_1824_0_66A[0]);
                    m_col_size = sizeof(wimax_1824_0_66A[0]) / sizeof(int16_t);
                    m_D = wimax_1824_0_66A_D;
                    m_X = wimax_1824_0_66A_X;
                }
                else if (rate == TWOTHIRDSB){
                    m_checknode_array = (int16_t*) &wimax_1824_0_66B;
                    m_row_size = sizeof(wimax_1824_0_66B) / sizeof(wimax_1824_0_66B[0]);
                    m_col_size = sizeof(wimax_1824_0_66B[0]) / sizeof(int16_t);
                    m_D = wimax_1824_0_66B_D;
                    m_X = wimax_1824_0_66B_X;
                }
                else if (rate == THREEQUARTERSA)
                {
                    m_checknode_array = (int16_t*) &wimax_1824_0_75A;
                    m_row_size = sizeof(wimax_1824_0_75A) / sizeof(wimax_1824_0_75A[0]);
                    m_col_size = sizeof(wimax_1824_0_75A[0]) / sizeof(int16_t);
                    m_D = wimax_1824_0_75A_D;
                    m_X = wimax_1824_0_75A_X;
                }
                else if (rate == THREEQUARTERSB)
                {
                    m_checknode_array = (int16_t*) &wimax_1824_0_75B;
                    m_row_size = sizeof(wimax_1824_0_75B) / sizeof(wimax_1824_0_75B[0]);
                    m_col_size = sizeof(wimax_1824_0_75B[0]) / sizeof(int16_t);
                    m_D = wimax_1824_0_75B_D;
                    m_X = wimax_1824_0_75B_X;
                }
                else if (rate == FIVESIXTHS)
                {
                    m_checknode_array = (int16_t*) &wimax_1824_0_83;
                    m_row_size = sizeof(wimax_1824_0_83) / sizeof(wimax_1824_0_83[0]);
                    m_col_size = sizeof(wimax_1824_0_83[0]) / sizeof(int16_t);
                    m_D = wimax_1824_0_83_D;
                    m_X = wimax_1824_0_83_X;
                }
                else
                {
                    printf("[!]ldpc_encoder - Invalid Coderate: %d\n", rate);
                    return 0;
                }
                break;
            }
            #endif  
            
            #ifdef Z_80
            case 80:
            {
                if (rate == HALFRATE)
                {
                    m_checknode_array = (int16_t*) &wimax_1920_0_5;
                    m_row_size = sizeof(wimax_1920_0_5) / sizeof(wimax_1920_0_5[0]);
                    m_col_size = sizeof(wimax_1920_0_5[0]) / sizeof(int16_t);
                    m_D = wimax_1920_0_5_D;
                    m_X = wimax_1920_0_5_X;
                }
                else if (rate == TWOTHIRDSA)
                {
                    m_checknode_array = (int16_t*) &wimax_1920_0_66A;
                    m_row_size = sizeof(wimax_1920_0_66A) / sizeof(wimax_1920_0_66A[0]);
                    m_col_size = sizeof(wimax_1920_0_66A[0]) / sizeof(int16_t);
                    m_D = wimax_1920_0_66A_D;
                    m_X = wimax_1920_0_66A_X;
                }
                else if (rate == TWOTHIRDSB){
                    m_checknode_array = (int16_t*) &wimax_1920_0_66B;
                    m_row_size = sizeof(wimax_1920_0_66B) / sizeof(wimax_1920_0_66B[0]);
                    m_col_size = sizeof(wimax_1920_0_66B[0]) / sizeof(int16_t);
                    m_D = wimax_1920_0_66B_D;
                    m_X = wimax_1920_0_66B_X;
                }
                else if (rate == THREEQUARTERSA)
                {
                    m_checknode_array = (int16_t*) &wimax_1920_0_75A;
                    m_row_size = sizeof(wimax_1920_0_75A) / sizeof(wimax_1920_0_75A[0]);
                    m_col_size = sizeof(wimax_1920_0_75A[0]) / sizeof(int16_t);
                    m_D = wimax_1920_0_75A_D;
                    m_X = wimax_1920_0_75A_X;
                }
                else if (rate == THREEQUARTERSB)
                {
                    m_checknode_array = (int16_t*) &wimax_1920_0_75B;
                    m_row_size = sizeof(wimax_1920_0_75B) / sizeof(wimax_1920_0_75B[0]);
                    m_col_size = sizeof(wimax_1920_0_75B[0]) / sizeof(int16_t);
                    m_D = wimax_1920_0_75B_D;
                    m_X = wimax_1920_0_75B_X;
                }
                else if (rate == FIVESIXTHS)
                {
                    m_checknode_array = (int16_t*) &wimax_1920_0_83;
                    m_row_size = sizeof(wimax_1920_0_83) / sizeof(wimax_1920_0_83[0]);
                    m_col_size = sizeof(wimax_1920_0_83[0]) / sizeof(int16_t);
                    m_D = wimax_1920_0_83_D;
                    m_X = wimax_1920_0_83_X;
                }
                else
                {
                    printf("[!]ldpc_encoder - Invalid Coderate: %d\n", rate);
                    return 0;
                }
                break;
            }
            #endif
            
            #ifdef Z_84
            case 84:
            {
                if (rate == HALFRATE)
                {
                    m_checknode_array = (int16_t*) &wimax_2016_0_5;
                    m_row_size = sizeof(wimax_2016_0_5) / sizeof(wimax_2016_0_5[0]);
                    m_col_size = sizeof(wimax_2016_0_5[0]) / sizeof(int16_t);
                    m_D = wimax_2016_0_5_D;
                    m_X = wimax_2016_0_5_X;
                }
                else if (rate == TWOTHIRDSA)
                {
                    m_checknode_array = (int16_t*) &wimax_2016_0_66A;
                    m_row_size = sizeof(wimax_2016_0_66A) / sizeof(wimax_2016_0_66A[0]);
                    m_col_size = sizeof(wimax_2016_0_66A[0]) / sizeof(int16_t);
                    m_D = wimax_2016_0_66A_D;
                    m_X = wimax_2016_0_66A_X;
                }
                else if (rate == TWOTHIRDSB){
                    m_checknode_array = (int16_t*) &wimax_2016_0_66B;
                    m_row_size = sizeof(wimax_2016_0_66B) / sizeof(wimax_2016_0_66B[0]);
                    m_col_size = sizeof(wimax_2016_0_66B[0]) / sizeof(int16_t);
                    m_D = wimax_2016_0_66B_D;
                    m_X = wimax_2016_0_66B_X;
                }
                else if (rate == THREEQUARTERSA)
                {
                    m_checknode_array = (int16_t*) &wimax_2016_0_75A;
                    m_row_size = sizeof(wimax_2016_0_75A) / sizeof(wimax_2016_0_75A[0]);
                    m_col_size = sizeof(wimax_2016_0_75A[0]) / sizeof(int16_t);
                    m_D = wimax_2016_0_75A_D;
                    m_X = wimax_2016_0_75A_X;
                }
                else if (rate == THREEQUARTERSB)
                {
                    m_checknode_array = (int16_t*) &wimax_2016_0_75B;
                    m_row_size = sizeof(wimax_2016_0_75B) / sizeof(wimax_2016_0_75B[0]);
                    m_col_size = sizeof(wimax_2016_0_75B[0]) / sizeof(int16_t);
                    m_D = wimax_2016_0_75B_D;
                    m_X = wimax_2016_0_75B_X;
                }
                else if (rate == FIVESIXTHS)
                {
                    m_checknode_array = (int16_t*) &wimax_2016_0_83;
                    m_row_size = sizeof(wimax_2016_0_83) / sizeof(wimax_2016_0_83[0]);
                    m_col_size = sizeof(wimax_2016_0_83[0]) / sizeof(int16_t);
                    m_D = wimax_2016_0_83_D;
                    m_X = wimax_2016_0_83_X;
                }
                else
                {
                    printf("[!]ldpc_encoder - Invalid Coderate: %d\n", rate);
                    return 0;
                }
                break;
            }
            #endif
            
            #ifdef Z_88
            case 88:
            {
                if (rate == HALFRATE)
                {
                    m_checknode_array = (int16_t*) &wimax_2112_0_5;
                    m_row_size = sizeof(wimax_2112_0_5) / sizeof(wimax_2112_0_5[0]);
                    m_col_size = sizeof(wimax_2112_0_5[0]) / sizeof(int16_t);
                    m_D = wimax_2112_0_5_D;
                    m_X = wimax_2112_0_5_X;
                }
                else if (rate == TWOTHIRDSA)
                {
                    m_checknode_array = (int16_t*) &wimax_2112_0_66A;
                    m_row_size = sizeof(wimax_2112_0_66A) / sizeof(wimax_2112_0_66A[0]);
                    m_col_size = sizeof(wimax_2112_0_66A[0]) / sizeof(int16_t);
                    m_D = wimax_2112_0_66A_D;
                    m_X = wimax_2112_0_66A_X;
                }
                else if (rate == TWOTHIRDSB){
                    m_checknode_array = (int16_t*) &wimax_2112_0_66B;
                    m_row_size = sizeof(wimax_2112_0_66B) / sizeof(wimax_2112_0_66B[0]);
                    m_col_size = sizeof(wimax_2112_0_66B[0]) / sizeof(int16_t);
                    m_D = wimax_2112_0_66B_D;
                    m_X = wimax_2112_0_66B_X;
                }
                else if (rate == THREEQUARTERSA)
                {
                    m_checknode_array = (int16_t*) &wimax_2112_0_75A;
                    m_row_size = sizeof(wimax_2112_0_75A) / sizeof(wimax_2112_0_75A[0]);
                    m_col_size = sizeof(wimax_2112_0_75A[0]) / sizeof(int16_t);
                    m_D = wimax_2112_0_75A_D;
                    m_X = wimax_2112_0_75A_X;
                }
                else if (rate == THREEQUARTERSB)
                {
                    m_checknode_array = (int16_t*) &wimax_2112_0_75B;
                    m_row_size = sizeof(wimax_2112_0_75B) / sizeof(wimax_2112_0_75B[0]);
                    m_col_size = sizeof(wimax_2112_0_75B[0]) / sizeof(int16_t);
                    m_D = wimax_2112_0_75B_D;
                    m_X = wimax_2112_0_75B_X;
                }
                else if (rate == FIVESIXTHS)
                {
                    m_checknode_array = (int16_t*) &wimax_2112_0_83;
                    m_row_size = sizeof(wimax_2112_0_83) / sizeof(wimax_2112_0_83[0]);
                    m_col_size = sizeof(wimax_2112_0_83[0]) / sizeof(int16_t);
                    m_D = wimax_2112_0_83_D;
                    m_X = wimax_2112_0_83_X;
                }
                else
                {
                    printf("[!]ldpc_encoder - Invalid Coderate: %d\n", rate);
                    return 0;
                }
                break;
            }
            #endif
            
            #ifdef Z_92
            case 92:
            {
                if (rate == HALFRATE)
                {
                    m_checknode_array = (int16_t*) &wimax_2208_0_5;
                    m_row_size = sizeof(wimax_2208_0_5) / sizeof(wimax_2208_0_5[0]);
                    m_col_size = sizeof(wimax_2208_0_5[0]) / sizeof(int16_t);
                    m_D = wimax_2208_0_5_D;
                    m_X = wimax_2208_0_5_X;
                }
                else if (rate == TWOTHIRDSA)
                {
                    m_checknode_array = (int16_t*) &wimax_2208_0_66A;
                    m_row_size = sizeof(wimax_2208_0_66A) / sizeof(wimax_2208_0_66A[0]);
                    m_col_size = sizeof(wimax_2208_0_66A[0]) / sizeof(int16_t);
                    m_D = wimax_2208_0_66A_D;
                    m_X = wimax_2208_0_66A_X;
                }
                else if (rate == TWOTHIRDSB){
                    m_checknode_array = (int16_t*) &wimax_2208_0_66B;
                    m_row_size = sizeof(wimax_2208_0_66B) / sizeof(wimax_2208_0_66B[0]);
                    m_col_size = sizeof(wimax_2208_0_66B[0]) / sizeof(int16_t);
                    m_D = wimax_2208_0_66B_D;
                    m_X = wimax_2208_0_66B_X;
                }
                else if (rate == THREEQUARTERSA)
                {
                    m_checknode_array = (int16_t*) &wimax_2208_0_75A;
                    m_row_size = sizeof(wimax_2208_0_75A) / sizeof(wimax_2208_0_75A[0]);
                    m_col_size = sizeof(wimax_2208_0_75A[0]) / sizeof(int16_t);
                    m_D = wimax_2208_0_75A_D;
                    m_X = wimax_2208_0_75A_X;
                }
                else if (rate == THREEQUARTERSB)
                {
                    m_checknode_array = (int16_t*) &wimax_2208_0_75B;
                    m_row_size = sizeof(wimax_2208_0_75B) / sizeof(wimax_2208_0_75B[0]);
                    m_col_size = sizeof(wimax_2208_0_75B[0]) / sizeof(int16_t);
                    m_D = wimax_2208_0_75B_D;
                    m_X = wimax_2208_0_75B_X;
                }
                else if (rate == FIVESIXTHS)
                {
                    m_checknode_array = (int16_t*) &wimax_2208_0_83;
                    m_row_size = sizeof(wimax_2208_0_83) / sizeof(wimax_2208_0_83[0]);
                    m_col_size = sizeof(wimax_2208_0_83[0]) / sizeof(int16_t);
                    m_D = wimax_2208_0_83_D;
                    m_X = wimax_2208_0_83_X;
                }
                else
                {
                    printf("[!]ldpc_encoder - Invalid Coderate: %d\n", rate);
                    return 0;
                }
                break;
            }
            #endif
            
            #ifdef Z_96
            case 96:
            {
                if (rate == HALFRATE)
                {
                    m_checknode_array = (int16_t*) &wimax_2304_0_5;
                    m_row_size = sizeof(wimax_2304_0_5) / sizeof(wimax_2304_0_5[0]);
                    m_col_size = sizeof(wimax_2304_0_5[0]) / sizeof(int16_t);
                    m_D = wimax_2304_0_5_D;
                    m_X = wimax_2304_0_5_X;
                }
                else if (rate == TWOTHIRDSA)
                {
                    m_checknode_array = (int16_t*) &wimax_2304_0_66A;
                    m_row_size = sizeof(wimax_2304_0_66A) / sizeof(wimax_2304_0_66A[0]);
                    m_col_size = sizeof(wimax_2304_0_66A[0]) / sizeof(int16_t);
                    m_D = wimax_2304_0_66A_D;
                    m_X = wimax_2304_0_66A_X;
                }
                else if (rate == TWOTHIRDSB){
                    m_checknode_array = (int16_t*) &wimax_2304_0_66B;
                    m_row_size = sizeof(wimax_2304_0_66B) / sizeof(wimax_2304_0_66B[0]);
                    m_col_size = sizeof(wimax_2304_0_66B[0]) / sizeof(int16_t);
                    m_D = wimax_2304_0_66B_D;
                    m_X = wimax_2304_0_66B_X;
                }
                else if (rate == THREEQUARTERSA)
                {
                    m_checknode_array = (int16_t*) &wimax_2304_0_75A;
                    m_row_size = sizeof(wimax_2304_0_75A) / sizeof(wimax_2304_0_75A[0]);
                    m_col_size = sizeof(wimax_2304_0_75A[0]) / sizeof(int16_t);
                    m_D = wimax_2304_0_75A_D;
                    m_X = wimax_2304_0_75A_X;
                }
                else if (rate == THREEQUARTERSB)
                {
                    m_checknode_array = (int16_t*) &wimax_2304_0_75B;
                    m_row_size = sizeof(wimax_2304_0_75B) / sizeof(wimax_2304_0_75B[0]);
                    m_col_size = sizeof(wimax_2304_0_75B[0]) / sizeof(int16_t);
                    m_D = wimax_2304_0_75B_D;
                    m_X = wimax_2304_0_75B_X;
                }
                else if (rate == FIVESIXTHS)
                {
                    m_checknode_array = (int16_t*) &wimax_2304_0_83;
                    m_row_size = sizeof(wimax_2304_0_83) / sizeof(wimax_2304_0_83[0]);
                    m_col_size = sizeof(wimax_2304_0_83[0]) / sizeof(int16_t);
                    m_D = wimax_2304_0_83_D;
                    m_X = wimax_2304_0_83_X;
                }
                else
                {
                    printf("[!]ldpc_encoder - Invalid Coderate: %d\n", rate);
                    return 0;
                }
                break;
            }
            #endif
            
            default:
            {
                printf("[!]ldpc_encoder - Invalid Z factor: %d\n", z_factor);
                return 0;
                break;
            }
        }
        return 1;
    }

    uint64_t ldpc::get_nanoseconds()
    {
        uint64_t nanoseconds =
        std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::
                    now().time_since_epoch()).count();
            
        return nanoseconds;
    }

    
}// end namespace wimax_ldpc_lib
