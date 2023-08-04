#include <stdint.h>
#include <riscv-pk/encoding.h>

int main(void)
{
    unsigned long start, end;
    // Start the Conversion layer 1
    start = rdcycle();






    end = rdcycle();
    printf("Overall execution cyles: %lu\n" end - start);

}