#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define rep(i, k, n) for (int i = k; i < n; ++i)

void chmin(int *a, int b) {
    // Minimum update function
    if (*a > b) *a = b;
}

const int INF = 1 << 30;

int main() {
    // Initialize dynamic programming array dp with initial value INF for all indices
    int dp[101000];
    rep(i, 0, 101000) dp[i] = INF;
    dp[0] = 0;

    // Read input
    int N, K; // Number of elements in the array and the size of the window
    scanf("%d %d", &N, &K);
    int h[N]; // Array of heights
    rep(i, 0, N) scanf("%d", &h[i]); // Read each height from the input

    // Dynamic programming calculation
    rep(i, 0, N) { // Iterate through all indices i
        rep(j, 1, K + 1) { // Iterate through all window sizes j
            if (i + j < N) { // Ensure we do not go out of bounds
                chmin(&dp[i + j], dp[i] + abs(h[i] - h[i + j]));
            }
        }
    }

    // Output the result
    printf("%d\n", dp[N - 1]); // Print the minimum cost to reach the last index with window size K
    return 0;
}

// <END-OF-CODE>
