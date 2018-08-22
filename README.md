# LDPC (Low Density Parity Check) Library

LDPC codes are a type of linear forward error correcting code.  They are high performance and in some cases approach the Shannon Limit.  A few protocols/standards that use LDPC:
  *  IEEE 802.3an (10GBASE-T)
  *  802.16E (Mobile WIMAX)
  *  DVB-C2 (Digital Video Broadcasting - Cable)
  *  G.hn (ITU-T Standard for networking over power lines)

This repository contains an LDPC encoder and decoder implemented in Python and C++.  The objective is to create a fast, high performance, easy to use LDPC encoder/decoder. 

The LDPC codes used in this project are from the IEEE 802.16E standard (Mobile WIMAX).  These matrices are used because they are a special form of LDPC codes known as Quasi-Cyclic (QC) LDPC codes.  QC-LDPC codes are faster to encode and decode.  All of the LDPC matrices and coderates from the 802.16e-2012 standard are available for use.

## Requirements

  * CMake
  * GSL >= 1.10

## Encoder

The encoder is based on the Richardson Urbanke (RU) Algorithm <sup>[1](#footnote1)</sup>.

## Decoder

The decoder uses the Turbo-Decoding Message-Passing Algorithm <sup>[2](#footnote2)</sup>.

## Tools

To build the tools, perform the following steps:
   * clone the repository: `git clone git@github.com:myersw12/wimax_ldpc_lib.git`
   * create the build directory: `cd wimax_ldpc_lib && mkdir build && cd build`
   * run cmake: `cmake ../`
   * run make: `make -j4`
   
The executables listed below are found in the `wimax_ldpc_lib/build/lib/` directory.

### test_encoder

Example Usage: `./lib/test_encoder 0 96 500 100 data.bin encoded.bin`

Stats from running on a i7-4771 @ 3.50GHz (running the example above):
  * Average Rate (Mbits/Sec): 6.877333
  * Fastest Time (Mbits/Sec): 7.820216
  * Slowest Time (Mbits/Sec): 5.030568

### test_decoder

Example Usage: `./lib/test_decoder 0 96 500 encoded.bin decoded.bin`

Stats from running on a i7-4771 @ 3.50GHz (decoding the output from the above example):
  * Average Rate (Mbits/Sec): 16.805945
  * Fastest Time (Mbits/Sec): 20.610994
  * Slowest Time (Mbits/Sec): 0.490290


## Directory Structure

## References

<a name="footnote1">1</a>:T. J. Richardson and R. L. Urbanke, "Efficient encoding of low-density parity-check codes," in IEEE Transactions on Information Theory, vol. 47, no. 2, pp. 638-656, Feb 2001.
doi: 10.1109/18.910579

<a name="footnote2">2</a>: B. Le Gal and C. Jego, "High-Throughput Multi-Core LDPC Decoders Based on x86 Processor," in IEEE Transactions on Parallel and Distributed Systems, vol. 27, no. 5, pp. 1373-1386, May 1 2016.
doi: 10.1109/TPDS.2015.2435787 

