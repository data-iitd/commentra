#include <stdio.h> // Including the header file for standard input and output
#include <stdlib.h> // Including the header file for standard library functions
#include <string.h> // Including the header file for string functions
#include <math.h> // Including the header file for mathematical functions

int main() { // Defining the main function
    int n, s, f, t, max = 0; // Declaring and initializing the variables
    scanf("%d %d", &n, &s); // Reading the first two integers n and s from the standard input

    while (n-- > 0) { // Looping n times
        scanf("%d %d", &f, &t); // Reading the first two values in the loop
        if (max < f + t) { // Checking if the sum of f and t is greater than the current max
            max = f + t; // Updating max if the condition is true
        }
    }

    printf("%d\n", max > s ? max : s); // Printing the maximum of max and s
    return 0; // Returning 0 to indicate successful execution
}

