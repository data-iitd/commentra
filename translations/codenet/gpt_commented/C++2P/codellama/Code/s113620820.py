
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
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

using namespace std;

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
  cin >> n; // Read the number of items

  # <START-OF-CODE>
  # Initialize prefix sums
  wsums[0] = 0; # Base case for prefix sums
  for i in range(n):
    cin >> wis[i]; # Read the weight of each item
    wsums[i + 1] = wsums[i] + wis[i]; # Calculate prefix sums
  # Initialize the dynamic programming and split point tables
  for i in range(n):
    for j in range(n + 1): dp[i][j] = LINF, ks[i][j] = -1; # Set initial values to LINF and -1
    dp[i][i + 1] = 0; # Base case: no cost to combine a single item
    ks[i][i + 1] = i; # Base case: the split point is the item itself
  # Fill the dynamic programming table
  for l in range(2, n + 1): # Iterate over lengths of segments
    for i in range(0, n - l + 1): # Iterate over starting index i
      j = i + l; # Calculate ending index j
      mind = LINF; # Initialize minimum cost for this segment
      wsum = wsums[j] - wsums[i]; # Calculate the total weight of the segment
      mink = -1; # Initialize the best split point
      for k in range(ks[i][j - 1], ks[i + 1][j] + 1): # Iterate over possible split points
        d = dp[i][k] + dp[k][j] + wsum; # Calculate the cost of this split
        if mind > d: mind = d, mink = k; # Update minimum cost and best split point
      dp[i][j] = mind; # Store the minimum cost for segment (i, j)
      ks[i][j] = mink; # Store the best split point for segment (i, j)
  # Output the minimum cost to combine all items
  printf("%lld\n", dp[0][n]); # Print the result
  return 0; # Exit the program
  # 