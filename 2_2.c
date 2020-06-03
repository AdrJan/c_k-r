#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int main()
{
    int i;
    int lim = 80;
    char c;
    char s[MAXLINE];

    // for(i = 0; i < lim - 1 && (c=getchar()) != '\n' && c != EOF; ++i)
    //     s[i] = c;

    for (i = 0; i < lim - 1; i++)
    {
        c = getchar();
        if (c == EOF)
            break;
        if (c == '\n')
            break;
        s[i] = c;
    }
    printf("%s\n", s);

    return EXIT_SUCCESS;
}
