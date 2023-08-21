#include "converter_layer.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <riscv-pk/encoding.h>

void printBufferContents(int *out_int, size_t bufsize) {
    for (size_t i = 0; i < bufsize; i++) {
        printf("%d ", out_int[i]);
    }
    printf("\n");
}

void printBufferContentsFloat(float *out_int, size_t bufsize) {
    for (size_t i = 0; i < bufsize; i++) {
        printf("%f ", out_int[i]);
    }
    printf("\n");
}


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
    int bufsize = 416 * 416 * 32;
    printf("%d\n\r", bufsize);
    float *in_fp32 = calloc(1, sizeof(float));
    initializeBuffer(in_fp32, 1);
    // printBufferContentsFloat(in_fp32, bufsize);
    int *in_int = calloc(bufsize, sizeof(int));
    initializeintBuffer(in_int, bufsize);
    //printBufferContentsFloat(in_fp32, bufsize);
    float *out_fp32 = calloc(bufsize, sizeof(float));
    int *out_int = calloc(1, sizeof(int));
    int fp_conv = 0;
    unsigned long start, end;
    start = rdcycle();
    forward_converter_layer(fp_conv, in_int, in_fp32, out_int, out_fp32);
    //printBufferContents(out_int, bufsize);

    // fp_conv = 0;
    //printBufferContents(in_int, bufsize);
    //forward_converter_layer(fp_conv, in_int, in_fp32, out_int, out_fp32);
    //printBufferContentsFloat(out_fp32, bufsize);
    end = rdcycle();
    printf("Overall execution cyles: %lu\n", end - start - 6297 - 6295);
    return 0;
}
