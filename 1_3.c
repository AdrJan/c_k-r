#include <stdio.h>

void printHeader();
void printConv();

int main() {
    printHeader();
    printConv();
}

void printHeader() {
    printf("----CONVERSION----\n");
    printf("Fahrenheit Celsius\n");
}

void printConv() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while(fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%10.0f %7.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}