//Array deletion by value in C
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int value = 3;
    int i, j;

    // Find the index of the value to be deleted
    for (i = 0; i < n; i++) {
        if (arr[i] == value) {
            // Shift elements to the left
            for (j = i; j < n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            break;
        }
    }

    // Print the modified array
    printf("Modified array: ");
    for (i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}