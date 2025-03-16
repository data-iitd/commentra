
#include <math.h>  // Include the math library to use mathematical functions
#include <stdio.h>  // Include the standard input/output library

int main() {
    int n, x = 1;  // Declare and initialize variables n and x
    scanf("%d", &n);  // Read an integer input from the user

    // Continue looping while n is not a power of 2
    while (log2(n)!= (int)log2(n)) {
        x++;  // Increment the counter for each iteration
        // Subtract the largest power of 2 less than or equal to n from n
        n -= pow(2, (int)log2(n));
    }

    // Print the final count of iterations
    printf("%d", x);

    return 0;  // Return 0 to indicate successful execution
}
