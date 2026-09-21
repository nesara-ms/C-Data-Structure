//Binary search Algorithm in C
#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1; // Element not found
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
        return mid; // Element found at index mid
    }
    if (arr[mid] > target) {
        return binarySearch(arr, low, mid - 1, target); // Search in the left half
    } else {
        return binarySearch(arr, mid + 1, high, target); // Search in the right half
    }
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 12;
    int result = binarySearch(arr, 0, n - 1, target);
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }
    return 0;
}