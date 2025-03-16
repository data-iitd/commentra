#include <stdio.h> // Include standard input-output library

int main() { // Entry point of the program
    int t; // Variable to hold the number of test cases
    scanf("%d", &t); // Read the number of test cases from standard input

    // Initialize a counter variable to keep track of the number of valid cases
    int count = 0;

    // Process each test case in a while loop
    while (t-- > 0) {
        int a, b, c; // Variables to hold the three integers
        scanf("%d %d %d", &a, &b, &c); // Read the three integers from standard input

        // Check if any of the given integers are equal to 1. If so, increment the counter.
        if ((a == 1 && b == 1) || (a == 1 && c == 1) || (b == 1 && c == 1) || (a == 1 && b == 1 && c == 1)) {
            count++; // Increment the counter if any of the given integers are equal to 1
        }
    }

    // Print the value of the counter to the standard output
    printf("%d\n", count); // Output the count

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
