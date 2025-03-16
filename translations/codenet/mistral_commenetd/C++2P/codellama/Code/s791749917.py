
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#define rep(i, n) for (int i = 0; i < (n); ++i) // Macro for a for loop, iterates from 0 to n-1
#define rep1(i, n) for (int i = 1; i < (n); ++i) // Macro for a for loop, iterates from 1 to n-1
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001; // Large constant value used as a default value for uninitialized variables

int main() {
  # Initialize variables
  H, W = map(int, input().split())

  # Initialize answer variable
  ans = 0

  # Check if the grid has only one cell
  if H == 1 or W == 1:
    ans = 1 # The answer is 1 in this case
  else:
    # Calculate the total number of cells in the grid
    m = H*W

    # Check if the total number of cells is even
    if m % 2 == 0:
      ans = m/2 # The answer is half of the total number of cells if it's even
    else:
      ans = m/2+1 # The answer is half of the total number of cells plus one if it's odd

  # Output the answer
  print(ans)

  # Return 0 to indicate successful execution
  return 0

# 