#include <stdio.h>
#include <stdlib.h>

// Function to return the absolute value of an integer
int abs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

// Function to return the minimum of two integers
int min(int a, int b) {
    if (a > b) {
        return b;
    }
    return a;
}

int main() {
    int N, K;
    // Read two integers from input
    scanf("%d %d", &N, &K);

    // Calculate N modulo K
    int x = N % K;

    // Get the absolute value of x if it's negative
    x = abs(x);

    // Find the minimum between x and abs(x-K)
    x = min(abs(x - K), x);

    // Print the result
    printf("%d\n", x);

    return 0;
}
