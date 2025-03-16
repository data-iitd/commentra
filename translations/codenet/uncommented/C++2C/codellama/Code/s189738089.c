#include <stdio.h>
#include <stdlib.h>
#define rep(i, k, n) for (int i = k; i < n; ++i)
const int INF = 1 << 30;

int main(){
  int N, K;
  scanf("%d %d", &N, &K);
  int *h = (int *)malloc(sizeof(int) * N);
  rep(i, 0, N) scanf("%d", &h[i]);

  int *dp = (int *)malloc(sizeof(int) * 101000);
  rep(i, 0, 101000) dp[i] = INF;
  dp[0] = 0;

  rep(i, 0, N) {
    rep(j, 1, K + 1) {
      if (dp[i] + abs(h[i] - h[i + j]) < dp[i + j]) dp[i + j] = dp[i] + abs(h[i] - h[i + j]);
    }
  }

  printf("%d\n", dp[N - 1]);
  return 0;
}

