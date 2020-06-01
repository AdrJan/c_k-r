#include <stdio.h>

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

#define MAXLINE 1000

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    int line_index = 1;
    while ((len = get_line(line, MAXLINE)) > 0)
    {
        printf("Line: %d - %d characters\n", line_index, len);
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
        line_index++;
    }
    if (max > 0)
    {
        printf("Longest line: %d - %d characters\n", --line_index, max);
        printf("TEXT: %s\n", longest);
    }
    return 0;
}

int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        i++;
}