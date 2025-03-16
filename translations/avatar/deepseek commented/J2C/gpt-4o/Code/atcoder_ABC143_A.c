#include <stdio.h> // Including standard input-output library

int main() { // Main function where execution begins
    int a, b, c; // Declaring integer variables
    if (scanf("%d %d", &a, &b) != 2) { // Reading two integers from input
        return 1; // Return error if input is not valid
    }
    c = a - b * 2; // Performing a mathematical operation to calculate a result
    if (c < 0) c = 0; // Checking if the result is negative and setting it to 0 if true
    printf("%d\n", c); // Printing the result to the standard output
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
