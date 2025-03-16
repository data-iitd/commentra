
#include <stdio.h>
#include <stdlib.h>
#define rep(i, k, n) for (int i = k; i < n; ++i)

const int INF = 1 << 30;

// Main function
int main(){
  // Initialize dynamic programming vector dp with initial value INF for all indices
  int *dp = (int *) malloc(sizeof(int) * 101000);
  rep(i, 0, 101000) dp[i] = INF;
  dp[0] = 0;

  // Read input
  int N, K; // Number of elements in the array and the size of the window
  scanf("%d %d", &N, &K);
  int *h = (int *) malloc(sizeof(int) * N); // Array of heights
  rep(i, 0, N) scanf("%d", &h[i]); // Read each height from the input

  // Dynamic programming calculation
  rep(i, 0, N) { // Iterate through all indices i
    rep(j, 1, K + 1) { // Iterate through all window sizes j
      // Update dp[i + j] with the minimum cost to reach this index with window size j
      dp[i + j] = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
    }
  }

  // Output the result
  printf("%d\n", dp[N - 1]); // Print the minimum cost to reach the last index with window size K
  return 0;
}

