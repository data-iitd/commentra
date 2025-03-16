#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// min function returns the minimum value from a variable number of integer arguments.
// It exits the program if no arguments are provided.
int min(int n, ...) {
  if (n == 0) {
    fprintf(stderr, "Error: No arguments provided to min function\n");
    exit(1);
  }
  va_list args;
  va_start(args, n);
  int r = va_arg(args, int);
  for (int i = 1; i < n; i++) {
    int current = va_arg(args, int);
    if (current < r) {
      r = current;
    }
  }
  va_end(args);
  return r;
}

int main() {
  int H, N, A, B;
  // Read the total height H and the number of items N from input
  scanf("%d %d", &H, &N);
  
  // Initialize a dynamic programming array to store the minimum cost for each height
  int dp[H + 10001];
  // Set initial values to a large number (infinity) for all heights
  for (int l = 1; l < H + 10001; l++) {
    dp[l] = INT_MAX; // Represents a large value (infinity)
  }
  
  int amax = 0; // Variable to track the maximum height of items
  // Process each item
  for (int i = 0; i < N; i++) {
    // Read the height A and cost B of the current item
    scanf("%d %d", &A, &B);
    // Update amax if the current item's height is greater
    if (A >= amax) {
      amax = A;
    }
    // Update the minimum cost for achieving height A
    dp[A] = min(dp[A], B);
    // Update the minimum cost for all heights from A+1 to H+A+1
    for (int j = A + 1; j <= H + amax + 1; j++) {
      dp[j] = min(dp[j], dp[j-A] + B); // Calculate the minimum cost for height j
    }
  }
  
  // Print the minimum cost to achieve height H considering all possible heights up to amax
  int result = INT_MAX;
  for (int i = H; i <= H + amax; i++) {
    result = min(result, dp[i]);
  }
  printf("%d\n", result);
  return 0;
}
