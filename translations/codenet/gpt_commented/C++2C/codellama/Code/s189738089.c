#include <stdio.h>
#include <stdlib.h>
#define rep(i, k, n) for (int i = k; i < n; ++i)
const int INF = 1 << 30; // Define a constant for infinity

// Function to update the minimum value
template<class T> inline void chmin(T &a, T b) {if (a > b) a = b; return;}

int main(){
  // Initialize a dp vector to store the minimum cost to reach each step
  int *dp = (int *)malloc(101000 * sizeof(int));
  rep(i, 0, 101000) dp[i] = INF; // Initialize all values to infinity
  dp[0] = 0; // Base case: cost to reach the first step is 0

  // Input the number of steps (N) and the maximum jump distance (K)
  int N, K;
  scanf("%d %d", &N, &K);
  int *h = (int *)malloc(N * sizeof(int)); // Vector to store the heights of the steps
  rep(i, 0, N) scanf("%d", &h[i]); // Read the heights of the steps

  // Dynamic programming to calculate the minimum cost to reach each step
  rep(i, 0, N) {
    // Check possible jumps from the current step
    rep(j, 1, K + 1) {
      // Update the minimum cost to reach step i + j
      chmin(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
    }
  }

  // Output the minimum cost to reach the last step
  printf("%d\n", dp[N - 1]);
  return 0;
}

