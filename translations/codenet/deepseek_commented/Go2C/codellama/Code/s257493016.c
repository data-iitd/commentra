
#include <stdio.h>
#include <stdlib.h>

// Function to find the minimum value among a variable number of integers
int min(int n, ...) {
  va_list args;
  va_start(args, n);
  int r = va_arg(args, int);
  for (int i = 1; i < n; i++) {
    int x = va_arg(args, int);
    if (x <= r) {
      r = x;
    }
  }
  va_end(args);
  return r;
}

int main() {
  int H, N, A, B, amax = 0;
  scanf("%d %d", &H, &N);
  int *dp = (int *)malloc((H + 10001) * sizeof(int));
  for (int l = 1; l < H + 10001; l++) {
    dp[l] = 2100000000;
  }
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
  printf("%d\n", min(dp + H, dp + H + amax + 1));
  free(dp);
  return 0;
}

