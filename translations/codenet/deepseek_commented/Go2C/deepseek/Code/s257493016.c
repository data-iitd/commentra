#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the minimum value among a variable number of integers
int min(int n, ...) {
  if (n == 0) {
    fprintf(stderr, "len == 0\n"); // Print error message if no arguments are provided
    exit(EXIT_FAILURE); // Exit the program with a failure status
  }
  va_list args;
  va_start(args, n); // Initialize the argument list
  int r = va_arg(args, int); // Initialize result with the first argument
  for (int i = 1; i < n; i++) {
    int current = va_arg(args, int); // Get the next argument
    if (current < r) { // Update result if a smaller element is found
      r = current;
    }
  }
  va_end(args); // Clean up the argument list
  return r; // Return the minimum value
}

int main() {
  int H, N, A, B; // Declare variables to store input values
  scanf("%d %d", &H, &N); // Read the values of H and N from standard input
  int dp[H + 10001]; // Create an array for dynamic programming with a large initial value
  for (int l = 1; l < H + 10001; l++) {
    dp[l] = INT_MAX; // Initialize the array with a large value
  }
  int amax = 0; // Initialize variable to keep track of the maximum attack value
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &A, &B); // Read the attack value A and the cost B for each attack
    if (A >= amax) {
      amax = A; // Update amax if the current attack value is greater than or equal to the current amax
    }
    dp[A] = min(2, dp[A], B); // Update the cost for attack value A
    for (int j = A + 1; j <= H + A + 1; j++) {
      dp[j] = min(3, dp[j], dp[j - A] + B); // Update the cost for all possible health values using the current attack
    }
  }
  printf("%d\n", min(H + amax + 1, dp, NULL)); // Print the minimum cost to reduce health H to zero or below
  return 0;
}

