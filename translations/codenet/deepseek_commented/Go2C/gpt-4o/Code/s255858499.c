#include <stdio.h>  // Importing the standard I/O library
#include <stdlib.h> // Importing the standard library for conversions

int main() {
    int a, b; // Declaring two integer variables

    // Reading the first integer input
    scanf("%d", &a);
    // Reading the second integer input
    scanf("%d", &b);

    // Checking if the product of a and b is odd or even and printing the result
    if ((a * b) % 2 != 0) {
        printf("Odd\n");
    } else {
        printf("Even\n");
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
