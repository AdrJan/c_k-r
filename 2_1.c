#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void print_max_int();
void print_max_short();
void print_max_char();
void print_max_long();

int main()
{
    printf("= VARIABLES =\n\n");

    printf("=== NORMAL ===\n");
    printf("Char size: %d\n", CHAR_MAX);
    printf("Short max: %d\n", SHRT_MAX);
    printf("Int max: %d\n", INT32_MAX);
    printf("Long max: %ld\n\n", LONG_MAX);

    printf("=== UNSIGNED ===\n");
    printf("Unsigned char size: %d\n", UCHAR_MAX);
    printf("Unsigned short max: %d\n", USHRT_MAX);
    printf("Unsigned int max: %u\n", UINT32_MAX);
    printf("Unsigned long max: %lu\n\n", ULONG_MAX);

    printf("=== PROGRAMATICALLY ===\n");
    print_max_char();
    print_max_short();
    print_max_int();
    print_max_long();

    return EXIT_SUCCESS;
}

void print_max_char()
{
    char i = 0;

    while ((char)(i + 1) > (char)i)
        i++;
    printf("Char max (programmatically): %d\n", i);
}

void print_max_short()
{
    int i = 0;

    while ((short)(i + 1) > (short)i)
        i++;
    printf("Short max (programmatically): %d\n", i);
}

void print_max_int()
{
    int i = 0;

    while ((i + 1) > i)
        i++;
    printf("Int max (programmatically): %d\n", i);
}

void print_max_long()
{
    long i = 0;
    long step = 2147483647;

    while ((long)(i + step) > (long)i)
        i += step;
    while ((long)(i + 1) > (long)i)
        i++;
    printf("Long max (programmatically): %ld\n", i);
}
