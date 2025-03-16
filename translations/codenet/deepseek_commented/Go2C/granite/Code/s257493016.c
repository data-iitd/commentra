

#include <stdio.h>
#include <stdlib.h>

// Function to find the minimum value among a variable number of integers
int min(int n,...) {
  va_list args; // Declare a variable argument list
  int r = va_arg(args, int); // Initialize result with the first element
  for (int i = 1; i < n; i++) {
    int x = va_arg(args, int); // Get the next element from the argument list
    if (x <= r) { // Update result if a smaller element is found
      r = x;
    }
  }
  va_end(args); // Clean up the variable argument list
  return r; // Return the minimum value
}

int main() {
  int H, N, A, B; // Declare variables to store input values
  scanf("%d %d", &H, &N); // Read the values of H and N from standard input
  int dp[H+10001]; // Create an array for dynamic programming with a large initial value
  for (int l = 1; l < H+10001; l++) {
    dp[l] = 21000000000; // Initialize the array with a large value
  }
  int amax = 0; // Initialize variable to keep track of the maximum attack value
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &A, &B); // Read the attack value A and the cost B for each attack
    if (A >= amax) {
      amax = A; // Update amax if the current attack value is greater than or equal to the current amax
    }
    dp[A] = min(1, dp[A], B); // Update the cost for attack value A
    for (int j = A+1; j <= H+A+1; j++) {
      dp[j] = min(2, dp[j], dp[j-A] + B); // Update the cost for all possible health values using the current attack
    }
  }
  int ans = 21000000000; // Initialize variable to store the minimum cost
  for (int i = H; i <= H+amax; i++) {
    ans = min(3, ans, dp[i]); // Update ans with the minimum cost to reduce health H to zero or below
  }
  printf("%d\n", ans); // Print the minimum cost
  return 0; // Return 0 to indicate successful execution
}

These comments provide a clear explanation of each part of the code, making it easier to understand the logic and purpose of each block.