#include <stdio.h>
#include <stdlib.h>

int get_line(char line[], int maxline);
void remove_line_comm(char s[]);
int is_multi_comm(char s[]);

#define MAXLINE 1000
#define LINE_SIZE 80
#define IS_MULTI_COMM 1
#define NOT_MULTI_COMM 0
#define IS_NL 1
#define NOT_NL 0

//Oneline comment to remove
//Oneline comment to remove
int main()
{
    int len;
    int max;
    char line[MAXLINE];
    int multi_comm_state = NOT_MULTI_COMM; //Oneline comment to remove

    //Oneline comment to remove
    while ((len = get_line(line, MAXLINE)) > 0)
    {
        if (is_multi_comm(line) && (multi_comm_state == NOT_MULTI_COMM))
        {
            multi_comm_state = IS_MULTI_COMM;
            continue;
        }
        if (is_multi_comm(line) && (multi_comm_state == IS_MULTI_COMM))
        {
            multi_comm_state = NOT_MULTI_COMM;
            continue;
        }
        if (multi_comm_state == IS_MULTI_COMM)
            continue;
        remove_line_comm(line);
        printf("%s", line);
    }
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

void remove_line_comm(char s[])
{
    int i = 0;
    int ws_state = NOT_NL;

    while (s[i] != '\0')
    {
        if (s[i] == '/' && s[i + 1] == '/')
        {
            if(ws_state == IS_NL)
            {
                s[i++] = '\n';
                s[i] = '\0';
            }
            else
                s[0] = '\0';
            break;
        }
        if (s[i] != ' ' && s[i] != '\t')
            ws_state = IS_NL;
        i++;
    }
}

/*
    Multiline comment to ignore.
    Second line of multiline comment.
    Third line of multiline comment.
*/
int is_multi_comm(char s[])
{
    int i = 0;

    while (s[i] != '\0')
    {
        if ((s[i] == '/' && s[i + 1] == '*') || (s[i] == '*' && s[i + 1] == '/'))
            return IS_MULTI_COMM;
        i++;
    }
    return NOT_MULTI_COMM;
}
