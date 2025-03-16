#include <stdio.h> // Include the standard input/output library for input and output
#include <string.h> // Include the string library for string manipulations (not used in this code)
#include <stdlib.h> // Include the standard library for various functions (not used in this code)
#include <math.h> // Include the math library for mathematical functions (not used in this code)
#define ll long long int // Define 'll' as a shorthand for 'long long int'

// Declare arrays to hold height and width values (not used in this code)
int h[6], w[6];

int main() {
    int x, ans = 0; // Declare variables x for input and ans for the result

    // Read an integer input from the user
    scanf("%d", &x);

    // Calculate the result as the sum of x, x squared, and x cubed
    ans = x + x*x + x*x*x;

    // Output the calculated result to the console
    printf("%d\n", ans);

    return 0; // Return 0 to indicate successful completion of the program
}

