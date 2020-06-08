#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

int get_line(char line[], int max);
int strindex(char source[], char search_for[]);

char pattern[] = "FOUND";

int main()
{
    char line[MAXLINE];
    int found = 0;
    int found_pos = -1;

    while (get_line(line, MAXLINE) > 0)
    {
        found_pos = strindex(line, pattern);
        if (strindex(line, pattern) >= 0)
        {
            printf("Pos: %d, Text: %s", found_pos, line);
            found++;
        }
    }

    return found;
}

int get_line(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int strindex(char s[], char t[])
{
    int i, j, k;

    for (i = strlen(s) - 1; s[i] > 0; i--)
    {
        for (j = i, k = strlen(t) - 1; k >= 0 && t[k] == s[j]; j--, k--)
            ;
        if (k < 0)
            return i - strlen(t) + 1;
    }
    return -1;
}
