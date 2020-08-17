#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY_SIZE 100

void my_strncpy(char *s, char *t, int n);
void my_strncat(char *s, char *t, int n);

int main()
{
    char s[MAX_ARRAY_SIZE] = "String, start.";
    char t[MAX_ARRAY_SIZE] = "String also start.";

    my_strncat(s, t, 6);

    return EXIT_SUCCESS;
}

void my_strncpy(char *s, char *t, int n)
{
    int i = 0;

    while((*s != '\0' || *t != '\0') && i++ < n)
        *t++ = *s++;
    *t = '\0';
}

void my_strncat(char *s, char *t, int n)
{
    int i = 0;
    int t_len = strlen(t);
    while(t_len-- > 0)
        *t++;

    while((*s != '\0' || *t != '\0') && i++ < n)
        *t++ = *s++;
    *t = '\0';
}
