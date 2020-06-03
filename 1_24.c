#include <stdio.h>
#include <stdlib.h>

int get_line(char line[], int maxline);
void count_elem(char[]);
void analyze();
int should_be_counted(char[], int);

#define MAXLINE 1000
#define LINE_SIZE 80

int squ_br = 0;
int cur_br = 0;
int rou_br = 0;

int dou_qu = 0;
int sin_qu = 0;

int multi_comm = 0;

int main()
{
    int len;
    int max;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0)
        count_elem(line);
    analyze();

    return EXIT_SUCCESS;
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

void count_elem(char s[])
{
    int i = 0;

    while (s[i] != '\0' && should_be_counted(s, i))
    {
        switch (s[i])
        {
        case '{':
            cur_br++;
            break;
        case '}':
            cur_br--;
            break;
        case '[':
            squ_br++;
            break;
        case ']':
            squ_br--;
            break;
        case '(':
            rou_br++;
            break;
        case ')':
            rou_br--;
            break;
        case '\'':
            sin_qu++;
            break;
        case '\"':
            dou_qu++;
            break;
        default:
            break;
        }

        if (s[i] == '/' && s[i + 1] == '*')
            multi_comm++;
        if (s[i] == '*' && s[i + 1] == '/')
            multi_comm--;

        i++;
    }
}

int should_be_counted(char s[], int i)
{
    return (i == 0 || s[i-1] == '\'');
}

void analyze()
{
    if (squ_br != 0)
        printf("ERROR: square brackets arent closed properly.\n");
    if (rou_br != 0)
        printf("ERROR: round brackets arent closed properly.\n");
    if (cur_br != 0)
        printf("ERROR: curly brackets arent closed properly.\n");

    if (sin_qu % 2 != 0)
        printf("ERROR: single quotes arent closed properly.\n");
    if (dou_qu % 2 != 0)
        printf("ERROR: double quotes arent closed properly.\n");

    if (multi_comm != 0)
        printf("ERROR: multiline comment is not closed properly\n");
}
