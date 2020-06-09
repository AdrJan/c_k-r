#include <stdio.h>

#define BUFSIZE 1000

int buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);

int main()
{
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
