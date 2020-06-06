#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100000

void escape(char[], char[]);
void escape_rev(char[], char[]);

int main()
{
    char s[MAX_LEN] = "\t\t\t    \\TEST\\    \n\n\n";
    char t[MAX_LEN];

    escape(s, t);
    printf("Text to escape: %s\n", s);
    printf("Text escaped: %s\n", t);

    escape_rev(t, s);
    printf("Text to reverse-escape: %s\n", t);
    printf("Text reverse-escaped: %s\n", s);

    return EXIT_SUCCESS;
}

void escape(char s[], char t[])
{
    char c;
    int i, j;
    i = j = 0;

    while (s[i] != '\0')
    {
        switch (s[i])
        {
        case '\n':
            t[j++] = '\\';
            t[j] = 'n';
            break;
        case '\t':
            t[j++] = '\\';
            t[j] = 't';
            break;
        default:
            t[j] = s[i];
            break;
        }
        i++;
        j++;
    }
}

void escape_rev(char s[], char t[])
{
    int i, j;
    i = j = 0;

    while (s[i] != '\0')
    {
        switch (s[i])
        {
        case '\\':
            switch (s[i + 1])
            {
            case 'n':
                t[j] = '\n';
                break;
            case 't':
                t[j] = '\t';
                break;
            default:
                t[j++] = '\\';
                t[j] = s[i + 1];
                break;
            }
            i++;
            break;
        default:
            t[j] = s[i];
            break;
        }
        i++;
        j++;
    }
}
