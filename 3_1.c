#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EL 10000

int binsearch(int, int[], int);

int main()
{
    int tab[10000];
    clock_t t_start, t_end;
    float time;

    t_start = clock();
    for (int i = 0; i < MAX_EL - 1; i++)
        tab[i] = i;
    tab[MAX_EL - 1] = '\0';
    t_end = clock();
    time = (float)(t_end - t_start) / CLOCKS_PER_SEC;

    printf("Element: %d, time: %f\n", binsearch(7, tab, MAX_EL), time);

    return EXIT_SUCCESS;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid + 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
