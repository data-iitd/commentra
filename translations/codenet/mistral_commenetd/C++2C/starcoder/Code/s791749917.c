
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i) // Macro for a for loop, iterates from 0 to n-1
#define rep1(i, n) for (int i = 1; i < (n); ++i) // Macro for a for loop, iterates from 1 to n-1
int main() {
  // Initialize variables
  ll H, W;
  scanf("%lld%lld", &H, &W);

  // Initialize answer variable
  ll ans;

  // Check if the grid has only one cell
  if (H == 1 || W == 1) {
    ans = 1; // The answer is 1 in this case
  } else {
    // Calculate the total number of cells in the grid
    ll m = H*W;

    // Check if the total number of cells is even
    if (m % 2 == 0) {
      ans = m/2; // The answer is half of the total number of cells if it's even
    } else {
      ans = m/2+1; // The answer is half of the total number of cells plus one if it's odd
    }
  }

  // Output the answer
  printf("%lld\n", ans);

  // Return 0 to indicate successful execution
  return 0;
}

