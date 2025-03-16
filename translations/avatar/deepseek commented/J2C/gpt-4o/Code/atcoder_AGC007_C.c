#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Initialize variables
    double N, d, x;
    
    // Read three double values: N, d, and x
    scanf("%lf %lf %lf", &N, &d, &x);
    
    // Initialize a variable to store the result
    double ans = 0.0;

    // Continue the loop until N is greater than 0.5
    while (N > 0.5) {
        // Calculate a value using double for precision
        double adnum = d + x * (N - 0.5);
        ans += adnum;

        // Update the values of d and x based on the current value of N
        d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N);
        x = (1.0 + (2.0 / N)) * x;

        // Decrement N by 1 in each iteration
        --N;
    }

    // Print the result formatted to a specific number of decimal places
    printf("%.20f\n", ans);

    return 0;
}

// <END-OF-CODE>
