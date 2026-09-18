//Basic code for pointer
#include <stdio.h>
int main()
{
    int c;
    int *pc;
    c = 5;
    pc = &c;
    *pc = 1;
    printf("\n%d",*pc); //output: 1
    printf("\n%d",c); //output: 1
}
