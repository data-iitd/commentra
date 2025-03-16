
#include<stdio.h>

int main(void):

    int x, y;

    printf("Enter a number: ");
    scanf("%d",&x);

    y = x * x * x;

    printf("The cube of %d is %d\n", x, y);

    return 0;

