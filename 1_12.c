#include <stdio.h>

#define IS_WHITESPACE 1
#define NOT_WHITESPACE 0 

int main() {
    int c;
    int ws_state = IS_WHITESPACE;

    while((c = getchar()) != EOF) {
        if(c == ' ' || c == '\n' || c == '\t') {
            if(!ws_state)
                putchar('\n');
            ws_state = IS_WHITESPACE;
        } 
        else {
            putchar(c);
            ws_state = NOT_WHITESPACE;
        }
    }
}