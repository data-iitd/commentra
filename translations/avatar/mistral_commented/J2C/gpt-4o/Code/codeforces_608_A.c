#include <stdio.h> // Including standard input/output library
#include <stdlib.h> // Including standard library for memory allocation and conversions

int main() {
    int n; // Variable to store the number of test cases
    scanf("%d", &n); // Reading the number of test cases

    int max = 0; // Initializing the maximum sum to zero

    while (n-- > 0) { // Processing each test case
        int f, t; // Variables to store the two numbers
        scanf("%d %d", &f, &t); // Reading the two numbers

        if (max < f + t) { // Checking if the sum of the current numbers is greater than the current maximum sum
            max = f + t; // Updating the maximum sum if it is
        }
    }

    printf("%d\n", max); // Writing the maximum sum to the output
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
