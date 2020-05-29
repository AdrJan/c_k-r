#include <stdio.h>

void putSpecEsc();

int main() {
    int c;

    while((c = getchar()) != EOF) {
        if(c == '\\') {
            putSpecEsc('\\');
        }
        else if(c == '\t') {
            putSpecEsc('t');
        }
        else if(c == '\b') {
            putSpecEsc('b');
        } else {
            putchar(c);
        }
    }
}

void putSpecEsc(int c) {
    putchar('\\');
    putchar(c);
}