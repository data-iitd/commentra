#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

// Macro definitions for loop iterations
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)

int main() {
  long long H, W; // Declare variables for height and width
  scanf("%lld %lld", &H, &W); // Input the height and width from the user

  long long ans; // Variable to store the final answer
  // Check if either height or width is 1
  if (H == 1 || W == 1) {
    ans = 1; // If either dimension is 1, the answer is 1
  } else {
    long long m = H * W; // Calculate the total number of cells (H * W)
    // Check if the total number of cells is even or odd
    if (m % 2 == 0) 
      ans = m / 2; // If even, half of the cells can be filled
    else 
      ans = m / 2 + 1; // If odd, half plus one cell can be filled
  }
  
  printf("%lld\n", ans); // Output the final answer
  return 0; // Return 0 to indicate successful execution
}

