#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXLINE 1000
#define IS_EQUAL 0

void itoa(int num, char *s, int base);
void reverse(char *s, int len);

int main()
{
    char s[MAXLINE];

    itoa(10, s, 2);
    assert(strcmp(s, "1010") == IS_EQUAL);
    itoa(100, s, 16);
    assert(strcmp(s, "64") == IS_EQUAL);

    return EXIT_SUCCESS;
}

void itoa(int n, char *s, int b)
{
    int i, sign;
    char *s_head = s;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do
    {
        *s++ = n % b + '0';
        i++;
    } while ((n /= b) > 0);
    if (sign < 0)
        *s++ = '-';
    *s++ = '\0';
    reverse(s_head, i);
}

void reverse(char *s, int len)
{
    int i, j;
    char temp;

    for (i = 0, j = len - 1; i < len / 2; i++, j--)
    {
        temp = *(s + i);
        *(s + i) = *(s + j);
        *(s + j) = temp;
    }
}
