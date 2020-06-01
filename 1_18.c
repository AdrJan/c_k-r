#include <stdio.h>
#include <string.h>

int get_line(char line[], int maxline);
void copy(char to[], char from[]);
void trim(char[]);

#define MAXLINE 1000
#define LINE_SIZE 80
#define NEWLINE_OFFSET 2

int main()
{
    int len;
    int max;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0)
        printf("%s", line);
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
    trim(s);
    return i;
}

void trim(char s[])
{
    int i = strlen(s) - NEWLINE_OFFSET;

    while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
        i--;
    if (i > 0)
        s[++i] = '\n';
    s[++i] = '\0';
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        i++;
}
