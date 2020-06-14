#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int);
int getfloat(float *);

char buf[BUFSIZE];
int bufp = 0;

int main()
{
    float var;

    getfloat(&var);
    printf("%.10f\n", var);

    return EXIT_SUCCESS;
}

int getfloat(float *pn)
{
    double val, power;
    int c, sign;

    while (isspace(c = getchar()))
        ;
    if (!isdigit(c) && c != EOF && c != '-' && c != '+')
    {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getchar();
    for (val = 0.0; isdigit(c); c = getchar())
        val = 10.0 * val + (c - '0');
    if (c == '.')
        c = getchar();
    for (power = 1.0; isdigit(c); c = getchar())
    {
        val = 10.0 * val + (c - '0');
        power *= 10;
    }
    *pn = sign * (val / power);
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
