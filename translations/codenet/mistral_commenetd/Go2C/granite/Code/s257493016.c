
#include <stdio.h>
#include <stdlib.h>

// Function to find minimum number in a slice
int min(int n,...) {
  va_list args;
  int r = va_arg(args, int);
  for (int i = 1; i < n; i++) {
    int x = va_arg(args, int);
    if (x <= r) {
      r = x;
    }
  }
  return r;
}

int main() {
  // Initialize variables for number of floors H, number of jumps N, and variables A and B for each jump
  int H, N, A, B;
  scanf("%d %d", &H, &N);

  // Initialize a slice dp of size H+10001 with initial value 21000000000
  int dp[H+10001];
  for (int l = 1; l < H+10001; l++) {
    dp[l] = 21000000000;
  }

  // Initialize maximum reachable floor amax to 0
  int amax = 0;
  // Iterate through each jump
  for (int i = 0; i < N; i++) {
    // Read floor A and number of floors B that can be jumped from floor A
    scanf("%d %d", &A, &B);

    // If the maximum reachable floor is less than A, update maximum reachable floor
    if (A >= amax) {
      amax = A;
    }

    // Update dp[A] with minimum of current dp[A] and B
    dp[A] = min(1, dp[A], B);

    // Iterate through floors from A+1 to H+A and update dp[j] with minimum of current dp[j] and dp[j-A]+B
    for (int j = A + 1; j <= H+A+1; j++) {
      dp[j] = min(2, dp[j], dp[j-A]+B);
    }
  }

  // Print the minimum number of jumps required to reach the last floor
  printf("%d\n", min(H-amax, dp[H:H+amax+1]));

  // End of code
}
