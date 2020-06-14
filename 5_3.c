#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY_SIZE 1024

void strcat_custom(char *s, char *t);

int main()
{
    char s[MAX_ARRAY_SIZE] = "string ends.";
    char t[MAX_ARRAY_SIZE] = "String starts, ";

    printf("Before concatenating: %s\n", t);
    strcat_custom(s, t);
    printf("After concatenating: %s\n", t);

    return EXIT_SUCCESS;
}

void strcat_custom(char *s, char *t)
{
    int t_len = strlen(t);

    t += t_len;
    while((*t++ = *s++) != '\0')
    ;
}
