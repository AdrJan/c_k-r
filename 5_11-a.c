#include <stdio.h>
#include <stdlib.h>

#define TAB_SPACE_NUM 8

void print_spaces(int);

int main(int argc, char *argv[])
{
    int c;
    int i;
    int tab_space_num = (argc == 1) ? TAB_SPACE_NUM : atoi(++argv[1]);

    i = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
            print_spaces(tab_space_num - (i % tab_space_num));
        else
            printf("%c", c);
        if (c == '\n')
            i = 0;
        else
            i++;
    }

    return 0;
}

void print_spaces(int n)
{
    for (int i = 0; i < n; i++)
        printf(" ");
}
