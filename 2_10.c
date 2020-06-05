#include <stdio.h>
#include <stdlib.h>

#define ASCII_OFFSET 32
#define MAX_TEXT 100

void lower(char[]);

int main()
{
    char s[MAX_TEXT] = "PleASe LOweR mE\n";

    printf("Before lower: %s", s);
    lower(s);
    printf("After lower: %s", s);

    return EXIT_SUCCESS;
}

void lower(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
        s[i] = (s[i] >= 'A' && s[i] <= 'Z')
                   ? s[i] + ASCII_OFFSET
                   : s[i];
}
