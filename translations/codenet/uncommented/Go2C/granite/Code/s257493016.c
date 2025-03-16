
#include <stdio.h>
#include <stdlib.h>

int min(int n,...) {
  va_list args;
  int r = n;
  va_start(args, n);
  for (int i = 1; i < n; i++) {
    int a = va_arg(args, int);
    if (a <= r) {
      r = a;
    }
  }
  va_end(args);
  return r;
}

int main() {
  int H, N, A, B;
  scanf("%d %d", &H, &N);
  int *dp = (int *)malloc(sizeof(int) * (H + 10001));
  for (int l = 1; l < H + 10001; l++) {
    dp[l] = 2100000000;
  }
  int amax = 0;
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &A, &B);
    if (A >= amax) {
      amax = A;
    }
    dp[A] = min(dp[A], B);
    for (int j = A + 1; j <= H + A + 1; j++) {
      dp[j] = min(dp[j], dp[j - A] + B);
    }
  }
  int ans = 2100000000;
  for (int i = H; i <= H + amax; i++) {
    ans = min(ans, dp[i]);
  }
  printf("%d\n", ans);
  free(dp);
  return 0;
}
