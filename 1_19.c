#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_line(char line[], int maxline);
void copy(char to[], char from[]);
char *reverse(char s[]);

#define MAXLINE 1000
#define LINE_SIZE 80

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char *rev_line;

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        rev_line = reverse(line);
        printf("%s", reverse(line));
        free(rev_line);
    }
    printf("\n");

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

char *reverse(char s[])
{
    int len = strlen(s);
    char *temp_s = malloc(len);
    int temp_i = 0;

    for (int i = len - 1; i >= 0; i--)
        temp_s[temp_i++] = s[i];
    temp_s[temp_i] = '\0';

    return temp_s;
}
