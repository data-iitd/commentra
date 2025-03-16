#include <stdio.h>

// Function to compute the Greatest Common Divisor (GCD) using Euclid's algorithm
long long Euclid(long long x, long long y) {
    long long tmp;

    // Ensure x is the larger number
    if (x < y) {
        tmp = x; // Store the smaller number in tmp
        x = y;   // Assign the larger number to x
        y = tmp; // Assign the smaller number to y
    }

    // If y divides x evenly, y is the GCD
    if (!(x % y)) return y;

    // Recursively call Euclid with y and the remainder of x divided by y
    return Euclid(y, x % y);
}

int main() {
    long long A, B; // Declare variables to hold the two input numbers
    scanf("%lld %lld", &A, &B);  // Read input values for A and B

    // Calculate and output the Least Common Multiple (LCM) using the formula LCM(A, B) = (A * B) / GCD(A, B)
    printf("%lld\n", (A * B) / Euclid(A, B));

    return 0; // Indicate that the program ended successfully
}

