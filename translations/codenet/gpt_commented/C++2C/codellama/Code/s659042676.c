#include <stdio.h> // Include stdio for input and output
#include <stdlib.h> // Include stdlib for mathematical functions
#include <string.h> // Include string for string manipulations
#include <math.h> // Include math for mathematical functions

int main() {
    int a, b; // Declare two integer variables to store input values

    // Read two integer values from standard input
    scanf("%d %d", &a, &b);

    // Calculate and output the result of the expression (6 - a - b)
    // This assumes that a and b are part of a game or problem where their sum should not exceed 6
    printf("%d\n", 6 - a - b);

    return 0; // Return 0 to indicate successful completion of the program
}

