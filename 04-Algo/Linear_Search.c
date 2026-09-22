//Linear Search Algorithm in C

#include <stdio.h>
#include <stdlib.h>

void arrayInput(int n, int *arr){
    printf("Enter array elements :");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
}

void arrayDisplay(int n, int *arr){
    if(n == 0){
        printf("Array is empty\n");
        return;
    }
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void linearSearch(int key, int n, int *arr){
     for(int i=0; i<n; i++){
        if(arr[i] == key){
            printf("Key found at index %d\n", i);
            return;
        }
    }
    printf("Key not found\n");
    return;
}

int main(){
    int choice, n =0, key;
    int arr[100];

    while(1){
        printf("---Array Operations---\n");
        printf("1. Input\n");
        printf("2. Output\n");
        printf("3. Search Element\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                printf("Enter array size : ");
                scanf("%d", &n);
                arrayInput(n, arr);
                break;
            }
            case 2:{
                arrayDisplay(n, arr);
                break;
            }
            case 3:{
                printf("Enter key to search : ");
                scanf("%d", &key);
                linearSearch(key, n, arr);
                break;
            }
            default:   
        }
    }
    return 0;
}