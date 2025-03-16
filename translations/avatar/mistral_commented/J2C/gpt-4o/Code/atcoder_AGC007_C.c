#include <stdio.h>      // Including standard input-output library
#include <math.h>      // Including math library for mathematical operations
#include <stdlib.h>    // Including standard library for memory allocation and other utilities

// Function to format the output to 20 decimal places
void printFormatted(double value) {
    printf("%.20f\n", value); // Printing the value with 20 decimal places
}

int main() {
    double N, d, x; // Declaring variables for N, d, and x

    // Reading input values from the user
    scanf("%lf %lf %lf", &N, &d, &x);

    double ans = 0.0; // Initializing an answer variable with zero value

    // Calculating the answer using the given formula
    while (N > 0.5) {
        double adnum = d + x * (N - 0.5); // Calculating the next term of the sum
        ans += adnum; // Adding the next term to the answer

        // Updating the values of d and x for the next iteration
        d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N);
        x = (1.0 + (2.0 / N)) * x;

        --N; // Decreasing the value of N by 1 for the next iteration
    }

    // Printing the final answer with 20 decimal places
    printFormatted(ans);

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
