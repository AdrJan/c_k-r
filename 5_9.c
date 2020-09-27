#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int day_of_year(int year, int month, int day);
int month_day(int year, int year_day, int *p_month, int *p_day);
int is_leap(int year);

static int days_in_month[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int main()
{
    // *** FIRST METHOD TESTING ***
    assert(day_of_year(1987, 11, 26) == 330);
    assert(day_of_year(2000, 7, 29) == 211);
    assert(day_of_year(1965, 7, 29) == 210);
    assert(day_of_year(1987, 1, 21) == 21);
    assert(day_of_year(1999, 2, 29) == -1);
    assert(day_of_year(1234, 1, 32) == -1);

    // *** SECOND METHOD TESTING ***
    int day;
    int month;
    month_day(2020, 12, &month, &day);
    assert(day == 12 && month == 1);
    month_day(1965, 210, &month, &day);
    assert(day == 29 && month == 7);

    return EXIT_SUCCESS;
}

int day_of_year(int year, int month, int day)
{
    if (month < 0 || month > 12 || day < 0)
        return -1;
    int leap = is_leap(year);
    if (day > *(*(days_in_month + leap) + month))
        return -1;

    for (int i = 1; i < month; i++)
        day += *(*(days_in_month + leap) + i);

    return day;
}

int month_day(int year, int year_day, int *p_month, int *p_day)
{
    if (year_day < 0)
        return -1;
    int leap = is_leap(year);
    if ((leap && year_day > 366) || (!leap && year_day > 365))
        return -1;

    int month = 1;
    int days = 0;
    int days_bef;
    while (days < year_day)
    {
        days_bef = days;
        days += *(*(days_in_month + leap) + month++);
    }

    *p_month = month - 1;
    *p_day = year_day - days_bef;

    return EXIT_SUCCESS;
}

int is_leap(int year)
{
    return (year % 4) == 0 && (year % 100 != 0 || year % 400 == 0);
}
