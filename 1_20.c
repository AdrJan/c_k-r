#include <stdio.h>

#define TAB_SPACE_NUM 15

void print_spaces(int);

int main()
{
    int c;
    int i;

    i = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
            print_spaces(TAB_SPACE_NUM - (i % TAB_SPACE_NUM));
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
