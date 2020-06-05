#include <stdio.h>
#include <stdlib.h>

int main() {
    int value = (getchar() != EOF);
    
    printf("Value: %d\n", value);

    return EXIT_SUCCESS;
}
