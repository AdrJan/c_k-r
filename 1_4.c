#include <stdio.h>

void printHeader();
void printConv();

int main() {
    printHeader();
    printConv();
}

void printHeader() {
    printf("----CONVERSION----\n");
    printf("Celsius Fahrenheit\n");
}

void printConv() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    while(fahr <= upper) {
        fahr = celsius * (9.0/5.0) + 32.0;
        printf("%7.0f %10.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}