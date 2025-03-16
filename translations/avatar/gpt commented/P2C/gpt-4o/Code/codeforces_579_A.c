#include <stdio.h>
#include <math.h>  // Include the math library for mathematical functions

int main() {
    // Read an integer input from the user
    int n;
    scanf("%d", &n);

    // Initialize a counter variable to track the number of iterations
    int x = 1;

    // Continue looping while n is not a power of 2
    while (log2(n) - (int)log2(n) != 0) {
        x++;  // Increment the counter for each iteration
        // Subtract the largest power of 2 less than or equal to n from n
        n -= (int)pow(2, (int)log2(n));
    }

    // Print the final count of iterations
    printf("%d\n", x);

    return 0;
}
