#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100000

void escape(char[], char[]);

int main()
{
    char s[MAX_LEN] = "It is example with tab \t and few newlines \n\n end \n\t.";
    char t[MAX_LEN];

    escape(s, t);
    printf("Text to escape: %s\n", s);
    printf("Text escaped: %s\n", t);

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
