#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>

#define EPSILON 0.0000001

double atof_custom(char[]);
int fequal(double, double);

int main()
{
    assert(fequal(atof_custom("1.21"), 1.21));
    assert(fequal(atof_custom("123.78"), 123.78));
    assert(fequal(atof_custom("   -8625.2312"), -8625.2312));
    assert(fequal(atof_custom("1.121e-1"), 0.1121));

    return EXIT_SUCCESS;
}

double atof_custom(char s[])
{
    double val, power, magn;
    int i, sign, sign_e, tens;

    magn = 1.0;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if (s[i] == 'e' || s[i] == 'E')
    {
        sign_e = (s[++i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (tens = 0; isdigit(s[i]); i++)
            tens = 10 * tens + (s[i] - '0');
        for(int j = 0; j < tens; j++)
            magn *= 10.0;
        if(sign_e == -1)
            magn = 1.0/magn;

    }
    return sign * (val / power) * magn;
}

int fequal(double d1, double d2)
{
    return fabs(d1 - d2) < EPSILON;
}
