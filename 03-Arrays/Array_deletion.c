//Array deletion by index in C
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int index = 2;

    // Delete element at index
    for (int i = index; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;

    // Print the array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}