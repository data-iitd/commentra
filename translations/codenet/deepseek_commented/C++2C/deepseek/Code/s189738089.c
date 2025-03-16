#include <stdio.h>
#include <stdlib.h>
#define rep(i, k, n) for (int i = k; i < n; ++i)

void chmin(int *a, int b) {
  if (*a > b) *a = b;
}

const int INF = 1 << 30;

int main() {
  // Initialization of the dp array
  int dp[101000];
  for (int i = 0; i < 101000; ++i) {
    dp[i] = INF;
  }
  dp[0] = 0;

  // input
  int N, K;
  scanf("%d %d", &N, &K);
  int h[N];
  for (int i = 0; i < N; ++i) {
    scanf("%d", &h[i]);
  }

  // Dynamic Programming Loop
  rep(i, 0, N) {
    rep(j, 1, K + 1) {
      if (i + j < N) {
        chmin(&dp[i + j], dp[i] + abs(h[i] - h[i + j]));
      }
    }
  }

  // Output
  printf("%d\n", dp[N - 1]);
  return 0;
}
