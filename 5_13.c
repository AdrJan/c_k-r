#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000
#define MAXLINES 5000

char *lineptr[MAXLINES];

int getline(char s[], int lim);
int getlines(char *lines[], int lim);
void write_tail(char *lines[], int lines_c, int to_write_c);

int main(int argc, char *argv[])
{
    int lines_c = getlines(lineptr, MAXLINES);

    if(argc == 1) write_tail(lineptr, lines_c, 5);
    else write_tail(lineptr, lines_c, atoi(++argv[1]));

    return EXIT_SUCCESS;
}

void write_tail(char *lines[], int lines_c, int to_write_c)
{
    int i = lines_c - to_write_c;

    while(i < lines_c)
        printf("%s", lines[i++]);
}

int getlines(char *lines[], int lim) 
{
    char line[MAXLEN];
    int lines_c = 0;
    char *ptr;
    int len = 0;

    while((len = getline(line, MAXLEN)) > 0)
    {
        if(lines_c >= lim)
            return -1;
        else
        {
            ptr = (char *) malloc(len);
            strcpy(ptr, line);
            lines[lines_c++] = ptr;
        }
    }
    return lines_c;
}

int getline(char s[], int lim)
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
