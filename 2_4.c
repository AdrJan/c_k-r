#include <stdio.h>
#include <stdlib.h>

void squeeze(char[], char[]);

int main()
{
    char s1[100] = "ABCDEFGHIJKL";
    char s2[100] = "BGKLL";

    printf("Before squeeze: %s\n", s1);
    squeeze(s1, s2);
    printf("After squeeze: %s\n", s1);

    return EXIT_SUCCESS;
}

void squeeze(char s1[], char s2[])
{
    int j, k;
    for (int i = 0; s2[i] != '\0'; i++)
    {
        for (j = k = 0; s1[j] != '\0'; j++)
            if (s2[i] != s1[j])
                s1[k++] = s1[j];
        s1[k] = '\0';
    }
}
