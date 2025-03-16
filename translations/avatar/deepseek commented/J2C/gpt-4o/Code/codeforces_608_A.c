#include <stdio.h> // Including standard input-output library
#include <stdlib.h> // Including standard library for memory allocation and conversions

int main() { // Main function is the entry point
    int n, s; // Declaring variables for n and s
    scanf("%d %d", &n, &s); // Reading the first two integers n and s from standard input

    int max = 0; // Initializing max to store the maximum sum of f and t

    while (n-- > 0) { // Looping n times
        int f, t; // Declaring variables for f and t
        scanf("%d %d", &f, &t); // Reading the values of f and t
        if (max < f + t) { // Checking if the sum of f and t is greater than the current max
            max = f + t; // Updating max if the condition is true
        }
    }

    printf("%d\n", (max > s ? max : s)); // Printing the maximum of max and s
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
