#include <stdio.h>    // Include the standard input-output library
#include <stdlib.h>   // Include the standard library for general utilities
#include <limits.h>   // Include the limits library for integer limits

// Define a macro for the maximum function
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    long long a, b; // Declare two long long integers a and b
    scanf("%lld %lld", &a, &b); // Read values for a and b from standard input

    // Calculate the maximum of the sum, difference, and product of a and b
    printf("%lld\n", MAX(a + b, MAX(a - b, a * b))); // Output the maximum value

    return 0; // Return 0 to indicate successful execution
}
