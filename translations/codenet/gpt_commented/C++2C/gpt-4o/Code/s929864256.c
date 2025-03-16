#include <stdio.h>    // Include the standard input-output library

<<<<<<< HEAD
long long max(long long x, long long y) { // Function to find the maximum of two long long integers
    return (x > y) ? x : y; // Return the greater of x and y
}

=======
>>>>>>> 98c87cb78a (data updated)
int main() {
    long long a, b; // Declare two long long integers a and b
    scanf("%lld %lld", &a, &b); // Read values for a and b from standard input

    // Calculate the maximum of the sum, difference, and product of a and b
<<<<<<< HEAD
    printf("%lld\n", max(a + b, max(a - b, a * b))); // Output the maximum value
=======
    long long max_value = a + b; // Initialize max_value with the sum
    if (a - b > max_value) {
        max_value = a - b; // Update max_value if the difference is greater
    }
    if (a * b > max_value) {
        max_value = a * b; // Update max_value if the product is greater
    }

    printf("%lld\n", max_value); // Output the maximum value
>>>>>>> 98c87cb78a (data updated)

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
