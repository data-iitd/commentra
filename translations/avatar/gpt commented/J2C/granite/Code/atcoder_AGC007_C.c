
#include <stdio.h> 
#include <math.h> 

int main() { 
    // Create variables to store the input values
    double N, d, x; 
    // Create a variable to store the accumulated answer
    double ans = 0.0; 
    // Create a variable to store the current term to be added to the answer
    double adnum; 
    // Create a variable to store the formatted result
    char result[21]; 

    // Read three double values from the user: N, d, and x
    scanf("%lf %lf %lf", &N, &d, &x); 

    // Loop until N is greater than 0.5
    while (N > 0.5) { 
        // Calculate the current term to be added to the answer
        adnum = (d + x * (N - 0.5)); 
        // Add the current term to the accumulated answer
        ans += adnum; 

        // Update d using the formula provided
        d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N); 
        // Update x using the formula provided
        x = (1.0 + (2.0 / N)) * x; 

        // Decrement N for the next iteration
        --N; 
    } 

    // Format the result using sprintf and store it in the result variable
    sprintf(result, "%.20f", ans); 
    // Print the formatted result
    printf("%s\n", result); 

    // End the program
    return 0; 
}
