#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int htoi(char s[]);

#define ASCII_CHAR_HEX_OFFSET 87
#define HEX_DEC 16

int main()
{
    printf("FF: %d\n", htoi("FF"));
    printf("0xAA123: %d\n", htoi("0xAA123"));
    printf("AA123: %d\n", htoi("AA123"));
    printf("F0: %d\n", htoi("F0"));
    printf("0xH123: %d\n", htoi("0xK123"));
    printf("0x: %d\n", htoi("0x"));
    return EXIT_SUCCESS;
}

int htoi(char s[])
{
    int i = 0;
    int len = strlen(s);
    int dec_num = 0;
    int pow_num = 0;

    for (i = len - 1; i >= 0; i--)
    {
        if (i == 1 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        {
            if (len == 2)
                return -1;
            else
                return dec_num;
        }
        if (isdigit(s[i]))
            dec_num += (s[i] - '0') * pow(HEX_DEC, pow_num++);
        else if (tolower(s[i]) >= 'a' && tolower(s[i]) <= 'f')
            dec_num += ((tolower(s[i])) - ASCII_CHAR_HEX_OFFSET) * pow(HEX_DEC, pow_num++);
        else
            return -1;
    }
    return (int)dec_num;
}
