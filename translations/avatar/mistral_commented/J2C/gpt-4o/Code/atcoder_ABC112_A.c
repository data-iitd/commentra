#include <stdio.h>  // Importing required C standard I/O library
#include <stdlib.h> // Importing required C standard library for memory allocation and conversions

int main() {
    int n; // Declaring an integer variable 'n' to store the number of test cases

    // Reading the first line of input which contains the number of test cases
    scanf("%d", &n);

    // Checking if the number of test cases is equal to 1
    if (n == 1) {
        // If yes, printing "Hello World" as output
        printf("Hello World\n");
    } else {
        int num1, num2; // Declaring two integer variables to store the input integers

        // Reading the next two integers from input
        scanf("%d %d", &num1, &num2);

        // Printing the sum of the two integers as output
        printf("%d\n", num1 + num2);
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
