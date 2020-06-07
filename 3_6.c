#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXLINE 1000
#define IS_EQUAL 0

void itoa(int, char[], int);
void reverse(char []);

int main()
{
    char s[MAXLINE];

    itoa(12332, s, 10);
    assert(strcmp(s, "     12332") == IS_EQUAL);
    itoa(12332, s, 3);
    assert(strcmp(s, "12332") == IS_EQUAL);
    itoa(0, s, 3);
    assert(strcmp(s, "  0") == IS_EQUAL);

    return EXIT_SUCCESS;
}

void itoa(int n, char s[], int w)
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
    while(i < w)
        s[i++] = ' ';
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
