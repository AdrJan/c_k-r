#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define EL_MAX 1000000
#define EL_NUM 10000

int binsearch(int, int[], int);
int binsearch_v2(int, int[], int);
void fill_arr(int[]);

int main()
{
    int arr[EL_MAX];
    int el_val = 0;
    int pos_1, pos_2;
    clock_t t_start, t_end;
    float time;

    fill_arr(arr);

    t_start = clock();
    pos_1 = binsearch(el_val, arr, EL_NUM);
    t_end = clock();
    time = (float)(t_end - t_start) / CLOCKS_PER_SEC;

    printf("Element: %d, time: %f\n", pos_1, time);

    t_start = clock();
    pos_2 = binsearch_v2(el_val, arr, EL_NUM);
    t_end = clock();
    time = (float)(t_end - t_start) / CLOCKS_PER_SEC;

    printf("Element: %d, time: %f\n", pos_2, time);

    return EXIT_SUCCESS;
}

void fill_arr(int arr[])
{
    for (int i = 0; i < EL_NUM; i++)
        arr[i] = i;
    arr[EL_NUM] = '\0';
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
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int binsearch_v2(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low != high)
    {
        mid = ceil((low + high) / 2.0);
        if (v[mid] > x)
            high = mid - 1;
        else
            low = mid;
    }
    if(x == v[low])
        return low;
    else
        return -1;
}
