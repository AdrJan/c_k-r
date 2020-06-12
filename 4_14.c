#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAXLINE 1000
#define swap(t, x, y)    \
    {                    \
        int temp = t[x]; \
        t[x] = t[y];     \
        t[y] = temp;     \
    }

int main()
{
    char s[MAXLINE] = "abcdefg";

    swap(s, 1, 3);
    assert(!strcmp(s, "adcbefg"));
    swap(s, 0, 5);
    assert(!strcmp(s, "fdcbeag"));

    return EXIT_SUCCESS;
}
