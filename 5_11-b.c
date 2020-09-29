#include <stdio.h>
#include <stdlib.h>

#define TABSIZE 8
#define IS_TAB 1
#define NO_TAB 0

void print_spaces(int);

int main(int argc, char *argv[])
{
    int c;
    int pos;
    int ns = 0;
    int tab_state = NO_TAB;
    int tab_ns = 0;
    int tabsize = (argc == 1) ? TABSIZE : atof(++argv[1]);

    pos = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            ns = 0;
            pos = -1;
            putchar(c);
        }
        else if (c == ' ')
            ns++;
        else if (ns > 0)
        {
            for (int i = 0; i < ((pos - ns) % tabsize + ns) / tabsize; i++)
            {
                putchar('\t');
                tab_state = IS_TAB;
            }

            if (tab_state == IS_TAB)
                tab_ns = pos % tabsize;
            else
                tab_ns = ns;
            for (int i = 0; i < tab_ns; i++)
                putchar(' ');

            putchar(c);
            ns = 0;
            tab_state = NO_TAB;
        }
        else
            putchar(c);
        pos++;
    }

    return 0;
}
