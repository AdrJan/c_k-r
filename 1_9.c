#include <stdio.h>

#define IS_SPACE 1
#define NOT_SPACE 0 

int main() {
    int c;
    int space_state = IS_SPACE;

    while((c = getchar()) != EOF) {
        if(c == ' ') {
            if(!space_state)
                putchar(c);
            space_state = IS_SPACE;
        } 
        else {
            putchar(c);
            space_state = NOT_SPACE;
        }
    }
}