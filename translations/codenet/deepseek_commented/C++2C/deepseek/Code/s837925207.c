#include <stdio.h> // Include the stdio library for input and output operations.
#include <string.h> // Include the string library for string operations.
#include <stdlib.h> // Include the stdlib library for various functions.
#include <math.h>   // Include the math library for mathematical operations.

int h[6], w[6]; // Declare two global arrays of size 6.

int main() { // The main function is the entry point of the program.
    int x, ans = 0; // Declare an integer variable x and initialize ans to 0.

    scanf("%d", &x); // Read an integer from the standard input and store it in x.

    ans = x + x*x + x*x*x; // Calculate the result by adding x, x*x, and x*x*x.

    printf("%d\n", ans); // Print the result to the standard output.

    return 0; // Return 0 to indicate successful execution.
}
