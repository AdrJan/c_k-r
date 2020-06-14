#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_ARRAY_SIZE 1024

int strend(char *s, char *t);

int main()
{
    assert(strend("string", "ing") == 1);
    assert(strend("string", "inf") == 0);
    assert(strend("string", "ING") == 0);
    assert(strend("str", "string") == 0);
    assert(strend("ing", "string") == 0);
    assert(strend("string", "string") == 1);

    return EXIT_SUCCESS;
}

int strend(char *s, char *t)
{
    int t_len = strlen(t);
    int s_len = strlen(s);
    if(t_len > s_len)
        return 0;

    s += s_len - t_len;
    for (; *t != '\0'; s++, t++)
        if (*s != *t)
            return 0;
    return 1;
}
