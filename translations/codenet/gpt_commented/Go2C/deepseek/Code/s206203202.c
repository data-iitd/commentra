#include <stdio.h>
#include <stdlib.h>

// Abs function returns the absolute value of an integer x.
int Abs(int x) {
    if (x < 0) {
        return -x; // If x is negative, return its negation.
    }
    return x; // If x is non-negative, return x itself.
}

// min function returns the smaller of two integers a and b.
int min(int a, int b) {
    if (a > b) {
        return b; // If a is greater than b, return b.
    }
    return a; // Otherwise, return a.
}

int main() {
    int N, K;
    // Read two integers N and K from standard input.
    scanf("%d %d", &N, &K);

    // Calculate the remainder of N divided by K.
    int x = N % K;
    // Determine the minimum between the absolute difference of (x - K) and x.
    x = min(Abs(x - K), x);
    // Print the final result.
    printf("%d\n", x);

    return 0;
}

