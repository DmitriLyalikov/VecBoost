#include <stdint.h>
#include <riscv-pk/encoding.h>
#include "converter_layer.h"

void initializeBuffer(float *buffer, size_t bufsize) {
    // You can put your desired initialization logic here.
    // For example, filling the buffer with consecutive numbers:
    for (size_t i = 0; i < bufsize; i++) {
        buffer[i] = (float)i;
    }
}

void initializeintBuffer(int *buffer, size_t bufsize) {
    // You can put your desired initialization logic here.
    // For example, filling the buffer with consecutive numbers:
    for (size_t i = 0; i < bufsize; i++) {
        buffer[i] = (int)i;
    }
}


int main(void)
{
    int bufsize = 4 * 4 * 32;
    float *in_fp32 = calloc(bufsize, sizeof(float));
    initializeBuffer(in_fp32, bufsize);
    int *in_int = calloc(bufsize, sizeof(int));
    initializeintBuffer(in_int, bufsize);
    float *out_fp32 = calloc(bufsize, sizeof(float));
    int *out_int = calloc(bufsize, sizeof(int));
    int conv_type = 0;
    unsigned long start, end;
    // Start the Conversion layer 1
    start = rdcycle();
    forward_converter_layer(conv_type, in_int, in_fp32, out_int, out_fp32);
    end = rdcycle();
    printf("Overall execution cyles: %lu\n" end - start);
    return 0;
}