#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define rep(i, k, n) for (int i = k; i < n; ++i)

#define MAX_N 101000
#define MAX_K 100000

int main(){
  // Initialization of the dp array
  int dp[MAX_N];
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  // input
  int N, K;
  scanf("%d %d", &N, &K);
  int h[MAX_N];
  rep(i, 0, N) scanf("%d", &h[i]);

  // Dynamic Programming Loop
  rep(i, 0, N) {
    rep(j, 1, K + 1) {
      dp[i + j] = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
    }
  }

  // Output
  printf("%d\n", dp[N - 1]);
  return 0;
}
