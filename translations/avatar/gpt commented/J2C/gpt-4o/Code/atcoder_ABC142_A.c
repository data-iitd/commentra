#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Variable to hold the input
    double input;
    
    // Read a line of input and parse it as a double
    if (scanf("%lf", &input) != 1) {
        // Handle input error
        fprintf(stderr, "Invalid input\n");
        return 1;
    }
    
    // Calculate the count of odd numbers based on the input
    double countOdd = round(input / 2);
    
    // Calculate the result of the division
    double result = countOdd / input;
    
    // Print the result to the console with 10 decimal places
    printf("%.10f\n", result);
    
    return 0;
}

// <END-OF-CODE>
