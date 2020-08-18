#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_ARRAY_SIZE 100

void my_strncpy(char *s, char *t, int n);
void my_strncat(char *s, char *t, int n);
int my_strncmp(char *s, char *t, int n);

int main()
{
    char s[MAX_ARRAY_SIZE] = "String, start.";
    char t[MAX_ARRAY_SIZE] = "String also start.";

    assert(my_strncmp(s, t, 6) == 0);
    assert(my_strncmp(s, t, 7) > 0);
    my_strncpy(s, t, 7);
    assert(strcmp(t, "String,also start.") == 0);
    my_strncat(s, t, 6);
    assert(strcmp(t, "String,also start.String") == 0);

    return EXIT_SUCCESS;
}

void my_strncpy(char *s, char *t, int n)
{
    int i = 0;

    while((*s != '\0' || *t != '\0') && i++ < n)
        *t++ = *s++;
    if(i >= strlen(t))
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

int my_strncmp(char *s, char *t, int n)
{
    int i = 0;
    while((*s != '\0' || *t != '\0') && i++ < n)
        if(*s > *t)
            return 1;
        else if(*s++ < *t++)
            return -1;
    return 0;     
}
