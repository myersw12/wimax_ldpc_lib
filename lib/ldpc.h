#ifndef LDPC_H
#define LDPC_H

#include <stdio.h>
#include <chrono>

#include "enums.h"
#include "matrices/wimax_576_0_5.h"
#include "matrices/wimax_576_0_66A.h"
#include "matrices/wimax_576_0_66B.h"
#include "matrices/wimax_576_0_75A.h"
#include "matrices/wimax_576_0_75B.h"
#include "matrices/wimax_576_0_83.h"

#define BASE_LDPC_BLOCK_LEN 2304

class ldpc
{
    
    private:
        void set_checknode_array(coderate rate, unsigned int z_factor);

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

