#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int bitcount(unsigned);

int main()
{
    assert(bitcount(0b10001) == 2);
    assert(bitcount(0b10111) == 4);
    assert(bitcount(0b11111) == 5);
    
    return EXIT_SUCCESS;
}

int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; b++)
        x &= (x - 1);
        
    return b;
}
