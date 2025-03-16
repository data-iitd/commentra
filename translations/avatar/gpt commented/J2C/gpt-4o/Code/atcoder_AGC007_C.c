#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Read three double values from the user: N, d, and x
    double N, d, x;
    scanf("%lf %lf %lf", &N, &d, &x);
    
    // Initialize a variable to store the accumulated answer
    double ans = 0.0;
    
    // Loop until N is greater than 0.5
    while (N > 0.5) {
        // Calculate the current term to be added to the answer
        double adnum = d + x * (N - 0.5);
        // Add the current term to the accumulated answer
        ans += adnum;
        
        // Update d using the formula provided
        d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N);
        // Update x using the formula provided
        x = (1.0 + (2.0 / N)) * x;
        
        // Decrement N for the next iteration
        --N;
    }
    
    // Print the result with a precision of 20 decimal places
    printf("%.20f\n", ans);
    
    return 0;
}

// <END-OF-CODE>
