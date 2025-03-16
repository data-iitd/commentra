

#include <stdio.h>
#include <stdlib.h>

// min function returns the minimum value from a variable number of integer arguments.
// It panics if no arguments are provided.
int min(int n,...) {
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
  int H, N, A, B;
  scanf("%d %d", &H, &N);
  
  int *dp = (int *)malloc(sizeof(int) * (H + 10001));
  for (int l = 1; l < H + 10001; l++) {
    dp[l] = 2100000000; // Represents a large value (infinity)
  }
  
  int amax = 0; // Variable to track the maximum height of items
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &A, &B);
    if (A >= amax) {
      amax = A;
    }
    dp[A] = min(dp[A], B);
    for (int j = A + 1; j <= H + amax + 1; j++) {
      dp[j] = min(dp[j], dp[j-A] + B); // Calculate the minimum cost for height j
    }
  }
  
  printf("%d\n", min(H + amax + 1 - A, dp[H] - B));
  free(dp);
}

