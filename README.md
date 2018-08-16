# LDPC (Low Density Parity Check) Library

LDPC codes are a type of linear forward error correcting code.  They are high performance and in some cases approach the Shannon Limit.  A few protocols/standards that use LDPC:
  *  IEEE 802.3an (10GBASE-T)
  *  802.16E (Mobile WIMAX)
  *  DVB-C2 (Digital Video Broadcasting - Cable)
  *  G.hn (ITU-T Standard for networking over power lines)

This repository contains an LDPC encoder and decoder implemented in Python and C++.  The objective is to create a fast, high performance, easy to use LDPC encoder/decoder. 

The LDPC codes used in this project are from the IEEE 802.16E standard (Mobile WIMAX).  These matrices are used because they are a special form of LDPC codes known as Quasi-Cyclic (QC) LDPC codes.  QC-LDPC codes are faster to encode and decode.  All of the LDPC matrices and coderates from the 802.16e-2012 standard are available for use.

## Encoder

The encoder is based on the Richardson Urbanke (RU) Algorithm <sup>[1](#footnote1)</sup>.

## Decoder

The decoder uses the Turbo-Decoding Message-Passing Algorithm <sup>[2](#footnote2)</sup>.

## Tools


## Directory Structure

## References

<a name="footnote1">1</a>:T. J. Richardson and R. L. Urbanke, "Efficient encoding of low-density parity-check codes," in IEEE Transactions on Information Theory, vol. 47, no. 2, pp. 638-656, Feb 2001.
doi: 10.1109/18.910579

<a name="footnote2">2</a>: B. Le Gal and C. Jego, "High-Throughput Multi-Core LDPC Decoders Based on x86 Processor," in IEEE Transactions on Parallel and Distributed Systems, vol. 27, no. 5, pp. 1373-1386, May 1 2016.
doi: 10.1109/TPDS.2015.2435787 

