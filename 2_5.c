#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int any(char[], char[]);

int main()
{
    char s1[100] = "ABCDEFGHIJKL";
    char s2[100] = "GKLCL";

    any(s1, s2);
    printf("S1: %s\n", s1);
    printf("S2: %s\n", s2);
    printf("Position of first character of S2 in S1: %d \n", any(s1, s2));

    return EXIT_SUCCESS;
}

int any(char s1[], char s2[])
{
    int j, k;
    int min = strlen(s1) + 1;

    for (int i = 0; s2[i] != '\0'; i++)
        for (j = 0; s1[j] != '\0'; j++)
            if (s2[i] == s1[j] && j < min)
                min = j;

    return min == strlen(s1) ? -1 : min;
}
