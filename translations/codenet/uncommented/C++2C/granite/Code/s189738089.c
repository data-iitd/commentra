
#include <stdio.h>
#include <stdlib.h>
#define rep(i, k, n) for (int i = k; i < n; ++i)

int main(){
  int *dp = (int *)malloc(sizeof(int) * 101000);
  rep(i, 0, 101000) dp[i] = 1 << 30;
  dp[0] = 0;
  // input
  int N, K;
  scanf("%d %d", &N, &K);
  int *h = (int *)malloc(sizeof(int) * N);
  rep(i, 0, N) scanf("%d", &h[i]);

  //dp
  rep(i, 0, N) {
    rep(j, 1, K + 1) {
      if (dp[i + j] > dp[i] + abs(h[i] - h[i + j])) {
        dp[i + j] = dp[i] + abs(h[i] - h[i + j]);
      }
    }
  }

  // output
  printf("%d\n", dp[N - 1]);
  free(dp);
  free(h);
  return 0;
}
