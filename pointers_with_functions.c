// Pointers with Functions
#include <stdio.h>

void SwapWithAddress(int *n1, int *n2) 
{
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}
void SwapWithoutAddress(int n1, int n2)
{
    int temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}
int main ()
{
    int num1 = 5, num2 = 10;
    //num1 and num2 are passed by value to the function SwapWithoutAddress
    SwapWithoutAddress(num1, num2);
    printf("After Swaping without address\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n\n", num2);

    //address of num1 and num2 are passed by reference to the function SwapWithAddress
    SwapWithAddress(&num1, &num2);
    printf("After Swaping with address\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);

}