#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char[], int, int);
void swap(char[], int, int);

int main()
{
    char s[] = "012345678";

    printf("Before reverse: %s\n", s);
    reverse(s, 0, strlen(s) - 1);
    printf("Reversed: %s\n", s);

    return EXIT_SUCCESS;
}

void reverse(char s[], int start, int end)
{
    if(start <= end - 1)
    {
        swap(s, start, end);
        reverse(s, ++start, --end);
    }
    else
        return;    
}

void swap(char s[], int i, int j)
{
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}
