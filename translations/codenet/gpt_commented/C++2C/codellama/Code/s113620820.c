/*
 * 2415.c: Sashimi
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>

/* constant */
const int MAX_N = 4000; // Maximum number of items

typedef long long ll; // Define ll as a long long type

const ll LINF = 1LL << 60; // Define a large constant for initialization

/* typedef */

/* global variables */
ll wis[MAX_N], wsums[MAX_N + 1], dp[MAX_N][MAX_N + 1]; // Arrays for weights, prefix sums, and dynamic programming table
int ks[MAX_N][MAX_N + 1]; // Array to store optimal split points

/* subroutines */

/* main */
int main() {
  int n; // Number of items
  scanf("%d", &n); // Read the number of items

  // Initialize prefix sums
  wsums[0] = 0; // Base case for prefix sums
  for (int i = 0; i < n; i++) {
    scanf("%lld", &wis[i]); // Read the weight of each item
    wsums[i + 1] = wsums[i] + wis[i]; // Calculate prefix sums
  }

  // Initialize the dynamic programming and split point tables
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= n; j++) dp[i][j] = LINF, ks[i][j] = -1; // Set initial values to LINF and -1
    dp[i][i + 1] = 0; // Base case: no cost to combine a single item
    ks[i][i + 1] = i; // Base case: the split point is the item itself
  }

  // Fill the dynamic programming table
  for (int l = 2; l <= n; l++) // Iterate over lengths of segments
    for (int i = 0, j = l; j <= n; i++, j++) { // Iterate over starting index i and ending index j
      ll mind = LINF; // Initialize minimum cost for this segment
      ll wsum = wsums[j] - wsums[i]; // Calculate the total weight of the segment
      int mink = -1; // Initialize the best split point
      for (int k = ks[i][j - 1]; k <= ks[i + 1][j]; k++) { // Iterate over possible split points
	ll d = dp[i][k] + dp[k][j] + wsum; // Calculate the cost of this split
	if (mind > d) mind = d, mink = k; // Update minimum cost and best split point
      }
      dp[i][j] = mind; // Store the minimum cost for segment (i, j)
      ks[i][j] = mink; // Store the best split point for segment (i, j)
    }

  // Output the minimum cost to combine all items
  printf("%lld\n", dp[0][n]); // Print the result
  return 0; // Exit the program
}

