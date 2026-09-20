// Pointers with Functions
#include <stdio.h>

void modifyValue(int *ptr) {
    *ptr = 10;
}

int main() {
    int value = 5;
    printf("Before modification: %d\n", value);
    modifyValue(&value);
    printf("After modification: %d\n", value);
    return 0;
}