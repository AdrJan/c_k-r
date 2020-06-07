#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 1000
#define TRUE 1
#define FALSE 0

void expand(char[], char[]);
int is_to_expand(char[], int, int);

int main()
{
    char s1[MAXLINE] = "a-k-m  a-z   A-Z    4-8   2-9a-k-z";
    char s2[MAXLINE];

    printf("Before expanding: %s\n", s1);
    expand(s1, s2);
    printf("After expanding: %s\n", s2);
    
    return EXIT_SUCCESS;
}

void expand(char s1[], char s2[])
{
    int i, j;
    i = j = 0;
    int s_len = strlen(s1);
    int is_chained = FALSE;

    while (s1[i] != '\0')
    {
        if (is_to_expand(s1, i, s_len))
        {
            for (int k = s1[i]; k <= s1[i + 2]; k++)
                if(!is_chained)
                    s2[j++] = k;
                else
                    is_chained = FALSE;
            is_chained = TRUE;
            i++;
        } 
        else if(!is_chained)
            s2[j++] = s1[i];
        else
            is_chained = FALSE;
        i++;
    }
    s2[j] = '\0';
}

int is_to_expand(char s[], int pos, int strlen)
{
    return ((s[pos + 1] == '-') && (pos + 2 < strlen) && (s[pos] < s[pos + 2]))
     && ((isalpha(s[pos]) && isalpha(s[pos + 2]))
      || (isnumber(s[pos]) && isnumber(s[pos + 2])));
}
