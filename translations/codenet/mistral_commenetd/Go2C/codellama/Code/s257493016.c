#include <stdio.h>
#include <stdlib.h>

// Function to find minimum number in a slice
int min(int n, int *arr) {
  if (n == 0) {
    // Panic if the slice is empty
    printf("len == 0\n");
    exit(1);
  }
  int r = arr[0];
  // Initialize minimum value with first element of the slice
  for (int i = 1; i < n; i++) {
    // Compare current element with minimum value and update minimum value if current element is smaller
    if (arr[i] <= r) {
      r = arr[i];
    }
  }
  // Return the minimum value
  return r;
}

// Main function
int main() {
  // Initialize variables for number of floors H, number of jumps N, and variables A and B for each jump
  int H, N, A, B;
  scanf("%d %d", &H, &N);

  // Initialize a slice dp of size H+10001 with initial value 2100000000
  int *dp = (int *)malloc((H+10001) * sizeof(int));
  for (int l = 1; l < H+10001; l++) {
    dp[l] = 2100000000;
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
    dp[A] = min(dp[A], B);

    // Iterate through floors from A+1 to H+A and update dp[j] with minimum of current dp[j] and dp[j-A]+B
    for (int j = A + 1; j <= H+A+1; j++) {
      dp[j] = min(dp[j], dp[j-A]+B);
    }
  }

  // Print the minimum number of jumps required to reach the last floor
  printf("%d\n", min(H+amax+1, dp+H));

  // End of code
  return 0;
}


