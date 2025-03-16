#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Abs(int a) {
    return a < 0 ? -a : a;
}

int Min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int N;
    scanf("%d", &N); // Read the number of elements

    int *h = (int *)malloc(N * sizeof(int)); // Allocate memory for heights
    for (int i = 0; i < N; i++) {
        scanf("%d", &h[i]); // Read the heights into an array
    }

    // Initialize a dynamic programming array to store minimum costs
    int *dp = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        dp[i] = 0; // Set initial values to zero
    }

    // Base case: cost to jump from the first to the second height
    dp[1] = Abs(h[0] - h[1]);

    // Fill the dp array with minimum costs for each position
    for (int i = 2; i < N; i++) {
        dp[i] = Min(dp[i-1] + Abs(h[i] - h[i-1]), // Cost from the previous height
                    dp[i-2] + Abs(h[i] - h[i-2])); // Cost from two heights back
    }

    // Output the minimum cost to reach the last height
    printf("%d\n", dp[N-1]);

    // Free allocated memory
    free(h);
    free(dp);

    return 0;
}

/* <END-OF-CODE> */
