#include <stdio.h>  // Include the standard input/output library
#include <math.h>  // Include the math library

// Read an integer input from the user
int main() {
    int n;
    scanf("%d", &n);

    // Initialize a counter variable to track the number of iterations
    int x = 1;

    // Continue looping while n is not a power of 2
    while (log2(n) % 1) {
        x += 1;  // Increment the counter for each iteration
        // Subtract the largest power of 2 less than or equal to n from n
        n -= 2 ** (int)(log2(n));
    }

    // Print the final count of iterations
    printf("%d", x);

    return 0;
}
