#include <stdio.h>

int main() {
    int ws_cnt, c;

    ws_cnt = 0;

    while((c = getchar()) != EOF) {
        if(c == '\n' || c == '\t' || c == ' ')
            ++ws_cnt;
    }

    printf("Whitespace count: %d\n", ws_cnt);
}