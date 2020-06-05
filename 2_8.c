#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define BITS_IN_BYTE 8

unsigned rightrot(unsigned, int);
int byte_count(int);

int main()
{
    assert(rightrot(0b00000001, 1) == 0b10000000);
    assert(rightrot(0b00000001, 3) == 0b00100000);
    assert(rightrot(0b00000110, 2) == 0b10000001);
    assert(rightrot(0b100000001, 1) == 0b1000000010000000);
    return EXIT_SUCCESS;
}

unsigned rightrot(unsigned x, int n)
{
    int byte = byte_count(x);
    int real_n = n % (byte * BITS_IN_BYTE);
    int shift = byte * BITS_IN_BYTE - real_n;

    return (x >> real_n) | ((~(~0 << real_n) << (shift)) & (x << shift));
}

int byte_count(int x)
{
    int n = 0;
    do
    {
        x >>= 8;
        n++;
    } while (x);
    return n;
}
