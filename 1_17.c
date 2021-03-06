#include <stdio.h>

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

#define MAXLINE 1000
#define LINE_SIZE 80

int main()
{
    int len;
    int max;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        if (len > LINE_SIZE)
            printf("%s\n", line);
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
