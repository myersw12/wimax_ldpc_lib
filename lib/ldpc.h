#ifndef LDPC_H
#define LDPC_H

#include <stdio.h>
#include <chrono>
#include <iostream>

#include "enums.h"
#include "matrices/matrices.h"

#define BASE_LDPC_BLOCK_LEN 2304

// Use this to enable/disable matrice switch statements
#define Z_24
#define Z_28
#define Z_32
#define Z_36
#define Z_40
#define Z_44
#define Z_48
#define Z_52
#define Z_56
#define Z_60
#define Z_64
#define Z_68
#define Z_72
#define Z_76
#define Z_80
#define Z_84
#define Z_88
#define Z_92
#define Z_96

class ldpc
{
    
    private:
        unsigned int set_checknode_array(coderate rate, unsigned int z_factor);

    protected:
        
        int16_t*    m_checknode_array;
        
        unsigned int    m_N;
        unsigned int    m_M;
        unsigned int    m_z;
        unsigned int    m_col_size;
        unsigned int    m_row_size; 
        unsigned int    m_num_threads;
        
    public:
        ldpc(coderate rate, unsigned int z_factor, unsigned int num_threads);
        ~ldpc();
        
        uint64_t get_nanoseconds();
    
    
};

#endif // LDPC_H

