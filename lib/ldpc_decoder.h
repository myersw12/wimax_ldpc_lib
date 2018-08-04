#ifndef LDPC_DECODER_H
#define LDPC_DECODER_H

#include <stdint.h>

#include "enums.h"
#include "ldpc.h"


class ldpc_decoder : public ldpc
{

    private:
        
    public:
        ldpc_decoder(coderate rate, unsigned int z_factor);
        ~ldpc_decoder();
        
};



#endif // LDPC_ENCODER_H