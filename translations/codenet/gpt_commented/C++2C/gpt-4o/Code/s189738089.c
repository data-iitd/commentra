#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define rep(i, k, n) for (int i = k; i < n; ++i)

// Function to update the minimum value
void chmin(int *a, int b) {
    if (*a > b) *a = b;
}

int main() {
    // Initialize a dp array to store the minimum cost to reach each step
    int dp[101000];
    for (int i = 0; i < 101000; ++i) {
        dp[i] = INT_MAX; // Set initial values to infinity
    }
    dp[0] = 0; // Base case: cost to reach the first step is 0

    // Input the number of steps (N) and the maximum jump distance (K)
    int N, K;
    scanf("%d %d", &N, &K);
    int h[N]; // Array to store the heights of the steps
    rep(i, 0, N) scanf("%d", &h[i]); // Read the heights of the steps

    // Dynamic programming to calculate the minimum cost to reach each step
    rep(i, 0, N) {
        // Check possible jumps from the current step
        rep(j, 1, K + 1) {
            if (i + j < N) { // Ensure we do not go out of bounds
                chmin(&dp[i + j], dp[i] + abs(h[i] - h[i + j]));
            }
        }
    }

    // Output the minimum cost to reach the last step
    printf("%d\n", dp[N - 1]);
    return 0;
}

// <END-OF-CODE>
