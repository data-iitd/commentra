#include <stdio.h>

int min(int n, ...) {
  int r = n;
  va_list args;
  va_start(args, n);
  for (int i = 0; i < n; i++) {
    int x = va_arg(args, int);
    if (x <= r) {
      r = x;
    }
  }
  va_end(args);
  return r;
}

int main() {
  int H, N, A, B, amax;
  scanf("%d %d", &H, &N);
  int dp[H+10001];
  for (int l = 1; l < H+10001; l++) {
    dp[l] = 2100000000;
  }
  amax = 0;
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &A, &B);
    if (A >= amax) {
      amax = A;
    }
    dp[A] = min(dp[A], B);
    for (int j = A+1; j <= H+A+1; j++) {
      dp[j] = min(dp[j], dp[j-A] + B);
    }
  }
  printf("%d\n", min(dp[H:H+amax+1]...));
  return 0;
}

