#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the absolute difference
int Abs(int a) {
    return a < 0 ? -a : a;
}

// Function to calculate the minimum of two integers
int Min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int N;
    // Read the number of test cases N from standard input
    scanf("%d", &N);

    // Read an array h of N integers from standard input
    int *h = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &h[i]);
    }

    // Initialize a dp array of size N
    int *dp = (int *)malloc(N * sizeof(int));
    dp[0] = 0; // The first element is 0 (not used)
    dp[1] = Abs(h[0] - h[1]); // Set the first element of dp

    // Iterate over the array h from the second element to the last
    for (int i = 2; i < N; i++) {
        dp[i] = Min(dp[i - 1] + Abs(h[i] - h[i - 1]), 
                     dp[i - 2] + Abs(h[i] - h[i - 2]));
    }

    // Print the last element of dp, which is the minimum number of jumps required to reach the last index of h
    printf("%d\n", dp[N - 1]);

    // Free allocated memory
    free(h);
    free(dp);

    return 0;
}

// <END-OF-CODE>
