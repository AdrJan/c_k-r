#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned invert(unsigned, int, int);

int main()
{
    assert(invert(0b0001, 1, 1) == 0b11);
    assert(invert(0b1110, 3, 3) == 0b0);
    assert(invert(0b0, 4, 1) == 0b10000);

    return EXIT_SUCCESS;
}

unsigned invert(unsigned x, int p, int n)
{
    return (~x & (~(~0 << n) << (p + 1 - n))) | ((~(~(~0 << n) << (p + 1 - n))) & x);
}
