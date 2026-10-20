#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <ctime>
#include <chrono>
#include <random>
#include <volk/volk.h>

#include "ldpc_encoder.h"
#include "ldpc_decoder.h"
#include "BER_runner.h"

#define MAX_ITER 10
#define NUM_ROUNDS 500
#define BER_ROUNDS 5000
#define NUM_THREADS 1

using namespace wimax_ldpc_lib;

struct rate_info {
    coderate rate;
    const char* name;
};

static void fill_with_random(uint8_t* buffer, unsigned int len, unsigned int seed)
{
    srand(seed);
    for (unsigned int i = 0; i < len; i++)
        buffer[i] = rand() % 2;
}

static void add_errors(uint8_t* buffer, unsigned int len,
                       unsigned int num_errors, unsigned int seed)
{
    srand(seed);
    for (unsigned int i = 0; i < num_errors; i++)
    {
        unsigned int idx = rand() % len;
        buffer[idx] ^= 1;
    }
}

static unsigned int dataword_len_for_rate(coderate rate, unsigned int codeword_len)
{
    switch (rate) {
        case HALFRATE:       return codeword_len / 2;
        case TWOTHIRDSA:
        case TWOTHIRDSB:     return (codeword_len * 2) / 3;
        case THREEQUARTERSA:
        case THREEQUARTERSB: return (codeword_len * 3) / 4;
        case FIVESIXTHS:     return (codeword_len * 5) / 6;
        default:             return 0;
    }
}

int main(int argc, char* argv[])
{
    unsigned int z = 96;
    if (argc > 1)
        z = atoi(argv[1]);

    unsigned int codeword_len = (z / 96.0) * 2304;

    rate_info rates[] = {
        {HALFRATE,       "1/2 "},
        {TWOTHIRDSA,     "2/3A"},
        {TWOTHIRDSB,     "2/3B"},
        {THREEQUARTERSA, "3/4A"},
        {THREEQUARTERSB, "3/4B"},
        {FIVESIXTHS,     "5/6 "},
    };
    unsigned int num_rates = sizeof(rates) / sizeof(rates[0]);

    unsigned int error_counts[] = {0, 1, 2, 3, 5, 8, 10, 15, 20, 30, 50, 75, 100, 150};
    unsigned int num_error_counts = sizeof(error_counts) / sizeof(error_counts[0]);

    printf("WiMAX LDPC Benchmark — z=%u, N=%u, %d rounds per cell, max_iter=%d\n\n",
           z, codeword_len, NUM_ROUNDS, MAX_ITER);

    printf("%-6s | %-5s | %12s | %12s | %8s | %s\n",
           "Rate", "Errs", "Enc (Mb/s)", "Dec (Mb/s)", "Decoded", "Status");
    printf("-------+-------+--------------+--------------+----------+--------\n");

    for (unsigned int r = 0; r < num_rates; r++)
    {
        coderate rate = rates[r].rate;
        unsigned int dw_len = dataword_len_for_rate(rate, codeword_len);

        ldpc_encoder encoder(rate, z, NUM_THREADS);
        ldpc_decoder decoder(rate, z, MAX_ITER, NUM_THREADS);

        uint8_t* dataword     = (uint8_t*)malloc(dw_len);
        uint8_t* codeword     = (uint8_t*)malloc(codeword_len);
        uint8_t* codeword_err = (uint8_t*)malloc(codeword_len);
        int8_t*  decoded      = (int8_t*)volk_malloc(codeword_len, volk_get_alignment());

        for (unsigned int e = 0; e < num_error_counts; e++)
        {
            unsigned int num_errors = error_counts[e];
            if (num_errors >= codeword_len)
                continue;

            uint64_t enc_time_sum = 0;
            uint64_t dec_time_sum = 0;
            unsigned int decode_ok = 0;

            for (unsigned int round = 0; round < NUM_ROUNDS; round++)
            {
                unsigned int seed = round * 1000 + r * 100 + e;
                fill_with_random(dataword, dw_len, seed);

                auto enc_start = std::chrono::high_resolution_clock::now();
                encoder.encode_data(dataword, codeword);
                auto enc_end = std::chrono::high_resolution_clock::now();
                enc_time_sum += std::chrono::duration_cast<std::chrono::nanoseconds>(
                    enc_end - enc_start).count();

                memcpy(codeword_err, codeword, codeword_len);
                if (num_errors > 0)
                    add_errors(codeword_err, codeword_len, num_errors, seed + 500);

                int8_t* input = (int8_t*)codeword_err;

                auto dec_start = std::chrono::high_resolution_clock::now();
                unsigned int remaining = decoder.decode(input, decoded);
                auto dec_end = std::chrono::high_resolution_clock::now();
                dec_time_sum += std::chrono::duration_cast<std::chrono::nanoseconds>(
                    dec_end - dec_start).count();

                if (remaining == 0)
                    decode_ok++;
            }

            double enc_avg_ns = enc_time_sum / (double)NUM_ROUNDS;
            double dec_avg_ns = dec_time_sum / (double)NUM_ROUNDS;
            double enc_mbps = (codeword_len * 1000.0) / enc_avg_ns;
            double dec_mbps = (codeword_len * 1000.0) / dec_avg_ns;

            const char* status = (decode_ok == NUM_ROUNDS) ? "OK" : "FAIL";

            printf("%-6s | %5u | %12.2f | %12.2f | %4u/%3u | %s\n",
                   rates[r].name, num_errors,
                   enc_mbps, dec_mbps,
                   decode_ok, NUM_ROUNDS,
                   status);
        }

        printf("-------+-------+--------------+--------------+----------+--------\n");

        free(dataword);
        free(codeword);
        free(codeword_err);
        volk_free(decoded);
    }

    double ebno_points[] = {1.5, 1.75, 2.0, 2.25, 2.5, 3.0, 3.5, 4.0};
    unsigned int num_ebno = sizeof(ebno_points) / sizeof(ebno_points[0]);

    unsigned int iter_values[] = {10, 20, 30};
    float nms_offsets[] = {0.65f, 0.70f, 0.75f, 0.815f};
    unsigned int num_iter = sizeof(iter_values) / sizeof(iter_values[0]);
    unsigned int num_nms = sizeof(nms_offsets) / sizeof(nms_offsets[0]);

    rate_info sweep_rates[] = {
        {HALFRATE,   "1/2 "},
        {FIVESIXTHS, "5/6 "},
    };
    unsigned int num_sweep_rates = sizeof(sweep_rates) / sizeof(sweep_rates[0]);

    #define BER_SWEEP_ROUNDS 2000

    printf("\n\nBER Sweep — z=%u, N=%u, %d frames per point\n", z, codeword_len, BER_SWEEP_ROUNDS);

    printf("\n%-14s", "iter/nms");
    for (unsigned int p = 0; p < num_ebno; p++)
        printf(" | %8.2f", ebno_points[p]);
    printf("\n");

    printf("--------------");
    for (unsigned int p = 0; p < num_ebno; p++)
        printf("-+----------");
    printf("\n");

    for (unsigned int ii = 0; ii < num_iter; ii++)
    {
        for (unsigned int ni = 0; ni < num_nms; ni++)
        {
            unsigned int iters = iter_values[ii];
            float nms = nms_offsets[ni];

            for (unsigned int r = 0; r < num_sweep_rates; r++)
            {
                BER_runner ber(sweep_rates[r].rate, z, NUM_THREADS, iters, nms);

                printf("%s i%2u n%.3f", sweep_rates[r].name, iters, nms);

                for (unsigned int p = 0; p < num_ebno; p++)
                {
                    ber.reset_test();

                    for (unsigned int i = 0; i < BER_SWEEP_ROUNDS; i++)
                        ber.run_iteration(ebno_points[p]);

                    uint64_t total_bits = ber.get_total_num_bits();
                    uint64_t total_errors = ber.get_total_num_errors();
                    double ber_val = (total_bits > 0) ? (double)total_errors / total_bits : 0.0;

                    if (ber_val == 0.0)
                        printf(" | %8s", "0");
                    else
                        printf(" | %8.2e", ber_val);
                }

                printf("\n");
            }

            printf("--------------");
            for (unsigned int p = 0; p < num_ebno; p++)
                printf("-+----------");
            printf("\n");
        }
    }

    return 0;
}
