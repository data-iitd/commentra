#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<queue>

# Macro definitions for loop iterations
rep(i, n) for (int i = 0; i < (n); ++i)
rep1(i, n) for (int i = 1; i < (n); ++i)

using namespace std;
using ll = long long; // Define 'll' as an alias for 'long long'
using P = pair<int, int>; // Define 'P' as an alias for a pair of integers
const int INF = 1001001001; // Define a constant for infinity

int main() {
  ll H, W; // Declare variables for height and width
  cin >> H >> W; // Input the height and width from the user

  ll ans; // Variable to store the final answer
  # Check if either height or width is 1
  if (H == 1 or W == 1):
    ans = 1; # If either dimension is 1, the answer is 1
  else:
    ll m = H * W; # Calculate the total number of cells (H * W)
    # Check if the total number of cells is even or odd
    if (m % 2 == 0):
      ans = m / 2; # If even, half of the cells can be filled
    else:
      ans = m / 2 + 1; # If odd, half plus one cell can be filled
  
  print(ans) # Output the final answer
  return 0; # Return 0 to indicate successful execution
}

