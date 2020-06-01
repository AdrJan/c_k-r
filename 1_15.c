#include <stdio.h>

void print_header();
void print_conv();
float get_conv_fahr_cels(float);

int main() {
    print_header();
    print_conv();
}

void print_header() {
    printf("----CONVERSION----\n");
    printf("Fahrenheit Celsius\n");
}

void print_conv() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while(fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%10.0f %7.1f\n", fahr, get_conv_fahr_cels(fahr));
        fahr = fahr + step;
    }
}

float get_conv_fahr_cels(float fahr) {
    return (5.0/9.0) * (fahr-32.0);
}
