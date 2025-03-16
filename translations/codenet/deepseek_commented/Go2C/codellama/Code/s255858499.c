#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a, b;
    char str[100];

    // Reading the first integer input
    scanf("%d", &a);

    // Reading the second integer input
    scanf("%d", &b);

    // Checking if the product of a and b is odd or even and printing the result
    if (a*b % 2 != 0)
    {
        printf("Odd\n");
    }
    else
    {
        printf("Even\n");
    }

    return 0;
}

