#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100

void itoa(int, char[], int);
void reverse(char[], int, int);
void swap(char[], int, int);

int main()
{
    char s[MAXLINE];

    itoa(-2382718, s, 0);
    printf("%s\n", s);

    return EXIT_SUCCESS;
}

void itoa(int n, char s[], int start_i)
{
    if (n < 0 && start_i == 0)
    {
        n = -n;
        s[start_i++] = '-';
    }

    s[start_i++] = n % 10 + '0';
    if (n / 10)
        itoa(n / 10, s, start_i);
    if ((n / 10) == 0)
    {
        int sign_gap = (s[0] == '-') ? 1 : 0;
        reverse(s, sign_gap, strlen(s) - 1);
        s[start_i] = '\0';
        return;
    }
}

void reverse(char s[], int start, int end)
{
    if (start <= end - 1)
    {
        swap(s, start, end);
        reverse(s, ++start, --end);
    }
    else
        return;
}

void swap(char s[], int i, int j)
{
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}
