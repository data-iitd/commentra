
#include <stdio.h>
#include <stdlib.h>
#define rep(i, k, n) for (int i = k; i < n; ++i)

int main(){
  // Initialization of the dp array
  int dp[101000] = {};
  dp[0] = 0;
  // input
  int N, K;
  scanf("%d %d", &N, &K);
  int h[N];
  rep(i, 0, N) scanf("%d", &h[i]);

  // Dynamic Programming Loop
  rep(i, 0, N) {
    rep(j, 1, K + 1) {
      dp[i + j] = dp[i + j] < dp[i] + abs(h[i] - h[i + j])? dp[i + j] : dp[i] + abs(h[i] - h[i + j]);
    }
  }

  // Output
  printf("%d\n", dp[N - 1]);
  return 0;
}
