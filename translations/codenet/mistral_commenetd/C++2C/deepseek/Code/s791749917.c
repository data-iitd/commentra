#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main() {
  // Initialize variables
  long long H, W;
  scanf("%lld %lld", &H, &W);

  // Initialize answer variable
  long long ans;

  // Check if the grid has only one cell
  if (H == 1 || W == 1) {
    ans = 1; // The answer is 1 in this case
  } else {
    // Calculate the total number of cells in the grid
    long long m = H * W;

    // Check if the total number of cells is even
    if (m % 2 == 0) {
      ans = m / 2; // The answer is half of the total number of cells if it's even
    } else {
      ans = m / 2 + 1; // The answer is half of the total number of cells plus one if it's odd
    }
  }

  // Output the answer
  printf("%lld\n", ans);

  // Return 0 to indicate successful execution
  return 0;
}
