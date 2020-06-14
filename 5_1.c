#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int);
int getint(int *);

char buf[BUFSIZE];
int bufp = 0;

int main()
{
    int var;

    getint(&var);
    printf("%d\n", var);

    return EXIT_SUCCESS;
}

int getint(int *pn)
{
    int c, sign, c_next;

    while (isspace(c = getchar()))
        ;
    if (!isdigit(c) && c != EOF && c != '-' && c != '+')
    {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if ((c == '+' || c == '-'))
    {
        if (isdigit(c_next = getchar()))
            c = c_next;
        else
        {
            ungetch(c_next);
            ungetch(c);
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
