#include <stdio.h>
#include <stdlib.h>

// min function returns the minimum value from a variable number of integer arguments.
// It panics if no arguments are provided.
int min(int n, ...) {
  int r = n; // Initialize the result with the first argument
  // Iterate through the remaining arguments to find the minimum
  for (int i = 1; i < n; i++) {
    int arg = va_arg(n, int);
    if (arg <= r) {
      r = arg; // Update the result if a smaller value is found
    }
  }
  return r; // Return the minimum value found
}

int main() {
  int H, N, A, B;
  // Read the total height H and the number of items N from input
  scanf("%d %d", &H, &N);
  
  // Initialize a dynamic programming array to store the minimum cost for each height
  int *dp = (int *)malloc((H+10001) * sizeof(int));
  // Set initial values to a large number (infinity) for all heights
  for (int l = 1; l < H+10001; l++) {
    dp[l] = 2100000000; // Represents a large value (infinity)
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
  printf("%d\n", min(dp[H:H+amax+1]));
  return 0;
}

