// Pointer Arithmetic Operations

#include <stdio.h>
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        printf("Value at arr[%d] = %d\n", i, *(arr + i)); // Accessing array elements using pointer arithmetic
    }
    return 0;
}