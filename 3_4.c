#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAXLINE 1000

void itoa(unsigned, char[]);
void reverse(char []);

int main()
{
    char s[MAXLINE];

    itoa(INT_MIN, s);
    printf("%s\n", s);
    
    return EXIT_SUCCESS;
}

void itoa(unsigned n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do
    {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int s_len = strlen(s);
    int i, j;
    char temp;

    for (i = 0, j = s_len - 1; i < s_len / 2; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
