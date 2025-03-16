

#include <stdio.h>
#include <stdlib.h>
#define rep(i, k, n) for (int i = k; i < n; ++i)

int min(int a, int b) {
  // Minimum update function
  if (a > b) return b;
  else return a;
}

int main(){
  // Initialize dynamic programming vector dp with initial value INT_MAX for all indices
  int N = 101000;
  int K = 1000;
  int dp[N];
  for (int i = 0; i < N; ++i) dp[i] = INT_MAX;
  dp[0] = 0;

  // Read input
  int h[N]; // Array of heights
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

