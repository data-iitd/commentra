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

<<<<<<< HEAD
    // The following block is commented out; it appears to be an alternative approach
    // to find a minimum value based on some conditions involving N and K.
    /*
    int hm[1000000] = {0}; // Create an array to track seen values of N.
    while (1) {
        if (!hm[N]) { // If N has not been seen before,
            hm[N] = 1; // mark it as seen.
            N = Abs(N - K); // Update N to the absolute difference of N and K.
        } else {
            break; // If N has been seen, exit the loop.
        }
    }
    int mini = 999999999; // Initialize mini to a large value.
    for (int k = 0; k < 1000000; k++) { // Iterate over the possible values.
        if (hm[k]) {
            mini = min(mini, k); // Update mini to the minimum value found.
        }
    }
    printf("%d\n", mini); // Print the minimum value found.
    */

    int x;
    // Calculate the remainder of N divided by K.
    x = N % K;
=======
    // Calculate the remainder of N divided by K.
    int x = N % K;
>>>>>>> 98c87cb78a (data updated)
    // Determine the minimum between the absolute difference of (x - K) and x.
    x = min(Abs(x - K), x);
    // Print the final result.
    printf("%d\n", x);

    return 0;
}

// <END-OF-CODE>
