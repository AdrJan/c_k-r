#include <stdio.h>

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

#define MAXLINE 1000
#define LINE_SIZE 80
#define WRAP_SIZE 50

void print_divided(char[], int);
void print_line(char[], int);

int main()
{
    int len;
    int max;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0)
        print_divided(line, WRAP_SIZE);
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

void print_divided(char s[], int lim)
{
    int i = 0;
    char temp_s[lim];
    int temp_i = 0;
    int last_i = 0;

    while (i >= 0 && s[i] != '\0')
    {
        while (s[i] != '\0' && i < last_i + lim)
            temp_s[temp_i++] = s[i++];
        if (s[i] == '\0')
        {
            temp_s[temp_i] = '\0';
            print_line(temp_s, temp_i);
            break;
        }
        while (temp_i >= 0 && temp_s[temp_i] != ' ')
        {
            i--;
            temp_i--;
        }
        while (temp_i >= 0 && temp_s[temp_i] == ' ')
            temp_i--;
        while (s[i] == ' ')
            i++;
        temp_s[++temp_i] = '\0';
        print_line(temp_s, temp_i);
        temp_i = 0;
        last_i = i;
    }
}

void print_line(char s[], int i)
{
    if (s[i - 1] == '\n')
        printf("%s", s);
    else
        printf("%s\n", s);
}
