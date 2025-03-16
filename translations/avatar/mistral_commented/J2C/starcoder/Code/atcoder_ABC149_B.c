
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long A, B, K; // Declaring variables A, B, and K of type long
    long x, y; // Declaring variables x and y of type long

    scanf("%ld %ld %ld", &A, &B, &K); // Reading the first line of input and storing the values of A, B, and K in the corresponding variables

    x = A; // Assigning the value of A to x
    y = B; // Assigning the value of B to y

    x = A - K; // Subtracting K from A and assigning the result to x

    if (x < 0) { // Checking if x is negative
        y = B + x; // If x is negative, adding the absolute value of x to B and assigning the result to y
        x = 0; // Setting x to zero
    }

    if (y < 0) { // Checking if y is negative
        y = 0; // If y is negative, setting it to zero
    }

    printf("%ld %ld\n", x, y); // Printing the values of x and y separated by a space character

    return 0;
}

