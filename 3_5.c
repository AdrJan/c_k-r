#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXLINE 1000
#define IS_EQUAL 0

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
    char s[MAXLINE];

    itob(26, s, 16);
    assert(strcmp(s, "1A") == IS_EQUAL);
    itob(26, s, 2);
    assert(strcmp(s, "11010") == IS_EQUAL);
    itob(25, s, 8);
    assert(strcmp(s, "31") == IS_EQUAL);

    return EXIT_SUCCESS;
}

void itob(int n, char s[], int b)
{
    int div = n;
    int rem;
    int i = 0;

    do
    {
        rem = div % b;
        div /= b;
        s[i++] = (rem > 9) ? 'A' + (10 - rem) : (rem + '0');
    } while (div > 0);
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int s_len = strlen(s);
    int i, j;
    char temp;

    for(i = 0, j = s_len - 1; i < s_len/2; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
