#include <stdio.h>    // Include the input-output stream library
#include <stdlib.h>   // Include the standard library for max function
#include <math.h>     // Include the math library for pow function

int main() {
    long long a, b; // Declare two long long integers a and b
    scanf("%lld %lld", &a, &b); // Read values for a and b from standard input

    // Calculate the maximum of the sum, difference, and product of a and b
    printf("%lld\n", max(a + b, max(a - b, a * b))); // Output the maximum value

    return 0; // Return 0 to indicate successful execution
}

