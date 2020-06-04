#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned setbits(unsigned, int, int, unsigned);

int main()
{
    assert(setbits(0b1, 4, 1, 0b101) == 17);
    assert(setbits(0b101, 4, 0, 0b1111) ==  5);
    assert(setbits(0b100001, 2, 3, 0b101) == 53);
    
    return EXIT_SUCCESS;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return  ((~(~0<<n) & y) << p) | ((~(~(~0<<n) << p)) & x);
}
