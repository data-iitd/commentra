
#include <stdio.h>
#include <stdlib.h>

// Function to find the minimum value among a variable number of integers
int min(int n,...) {
  va_list args;
  int i, r;
  va_start(args, n); // Initialize the argument list
  r = va_arg(args, int); // Get the first argument
  for (i = 1; i < n; i++) {
    if (va_arg(args, int) <= r) { // Update result if a smaller element is found
      r = va_arg(args, int);
    }
  }
  va_end(args); // Clean up the argument list
  return r; // Return the minimum value
}

int main() {
  int H, N, A, B, amax; // Declare variables to store input values
  scanf("%d %d", &H, &N); // Read the values of H and N from standard input
  int *dp = (int *)malloc(sizeof(int) * (H + 10001)); // Create a slice for dynamic programming with a large initial value
  for (int l = 1; l < H + 10001; l++) {
    dp[l] = 2100000000; // Initialize the slice with a large value
  }
  amax = 0; // Initialize variable to keep track of the maximum attack value
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &A, &B); // Read the attack value A and the cost B for each attack
    if (A >= amax) {
      amax = A; // Update amax if the current attack value is greater than or equal to the current amax
    }
    dp[A] = min(dp[A], B); // Update the cost for attack value A
    for (int j = A + 1; j <= H + A + 1; j++) {
      dp[j] = min(dp[j], dp[j - A] + B); // Update the cost for all possible health values using the current attack
    }
  }
  printf("%d", min(H - amax, dp[H] - dp[H - amax])); // Print the minimum cost to reduce health H to zero or below
  free(dp); // Free the memory allocated to the slice
  return 0;
}

