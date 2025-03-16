#include <stdio.h>  // Importing standard input/output library
#include <stdlib.h> // Importing standard library for memory allocation and other utilities

// Function to calculate x raised to the power of y modulo mod
int modPower(int x, int y, int mod) {
    int res = 1; // Initializing the result variable to 1
    x %= mod; // Calculating the remainder of x when divided by mod

    if (x == 0) return 0; // If x is 0, the result is 0

    while (y > 0) { // While y is greater than 0
        if (y % 2 == 1) { // If y is odd
            res = (res * x) % mod; // Multiplying the result with x and taking the modulo with mod
        }
        y = y >> 1; // Dividing y by 2
        x = (x * x) % mod; // Squaring x and taking the modulo with mod
    }
    return res; // Returning the final result
}

int main() { // Main function for executing the program
    long a[4]; // Declaring an array of long integers named a with size 4

    // Reading input values into the array a
    for (int i = 0; i < 4; i++) { // Iterating through the elements of the array a
        scanf("%ld", &a[i]); // Reading the next long integer from the input and storing it in the current element of the array
    }

    // Calculating the maximum product of pairs of elements in the array a
    long result = a[0] * a[2];
    if (a[1] * a[3] > result) result = a[1] * a[3];
    if (a[0] * a[3] > result) result = a[0] * a[3];
    if (a[1] * a[2] > result) result = a[1] * a[2];

    printf("%ld\n", result); // Printing the result to the standard output

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
