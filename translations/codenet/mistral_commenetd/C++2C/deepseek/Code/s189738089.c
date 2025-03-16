#include <stdio.h>
#include <stdlib.h>
#define rep(i, k, n) for (int i = k; i < n; ++i)

void chmin(int *a, int b) {
  // Minimum update function
  if (*a > b) *a = b;
  return;
}

const int INF = 1 << 30;

// Main function
int main(){
  // Initialize dynamic programming vector dp with initial value INF for all indices
  int dp[101000];
  for (int i = 0; i < 101000; ++i) {
    dp[i] = INF;
  }
  dp[0] = 0;

  // Read input
  int N, K; // Number of elements in the array and the size of the window
  scanf("%d %d", &N, &K);
  int h[N]; // Array of heights
  for (int i = 0; i < N; ++i) {
    scanf("%d", &h[i]); // Read each height from the input
  }

  // Dynamic programming calculation
  rep(i, 0, N) { // Iterate through all indices i
    rep(j, 1, K + 1) { // Iterate through all window sizes j
      // Update dp[i + j] with the minimum cost to reach this index with window size j
      if (i + j < N) {
        chmin(&dp[i + j], dp[i] + abs(h[i] - h[i + j]));
      }
    }
  }

  // Output the result
  printf("%d\n", dp[N - 1]); // Print the minimum cost to reach the last index with window size K
  return 0;
}
