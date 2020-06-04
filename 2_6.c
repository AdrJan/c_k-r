#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned setbits(unsigned, int, int, unsigned);

int main()
{
    assert(setbits(0b1, 4, 1, 0b101) == 0b10001);
    assert(setbits(0b101, 4, 0, 0b1111) == 0b101);
    assert(setbits(0b100001, 2, 3, 0b101) == 0b100101);

    return EXIT_SUCCESS;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return ((~(~0 << n) & y) << (p + 1 - n)) | ((~(~(~0 << n) << (p + 1 - n))) & x);
}
