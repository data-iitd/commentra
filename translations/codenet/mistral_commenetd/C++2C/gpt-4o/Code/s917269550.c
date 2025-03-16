#include <stdio.h> // Include stdio.h library for input/output
#include <stdlib.h> // Include stdlib.h library for abs() function

int main() {
    long long x, y; // Declare two long long integers, x and y, to store user inputs

    // Read user inputs from standard input using scanf
    scanf("%lld %lld", &x, &y);

    // Check if the absolute difference between x and y is less than or equal to 1
    if (abs(x - y) <= 1) {
        // If the condition is true, print "Brown" to the standard output
        printf("Brown\n");
    } else {
        // If the condition is false, print "Alice" to the standard output
        printf("Alice\n");
    }

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
