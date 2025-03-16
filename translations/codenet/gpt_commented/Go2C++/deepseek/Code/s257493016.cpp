#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// min function returns the minimum value from a variable number of integer arguments.
// It panics if no arguments are provided.
int min(int n, ...) {
  va_list args;
  va_start(args, n);
  int r = n; // Initialize the result with the first argument
  // Iterate through the remaining arguments to find the minimum
  while (true) {
    int current = va_arg(args, int);
    if (current == INT_MAX) break; // End of arguments
    if (current < r) {
      r = current; // Update the result if a smaller value is found
    }
  }
  va_end(args);
  return r; // Return the minimum value found
}

int main() {
  int H, N, A, B;
  // Read the total height H and the number of items N from input
  cin >> H >> N;
  
  // Initialize a dynamic programming array to store the minimum cost for each height
  vector<int> dp(H + 10001, INT_MAX);
  // Set initial values to a large number (infinity) for all heights
  dp[0] = 0; // Cost to achieve height 0 is 0
  
  int amax = 0; // Variable to track the maximum height of items
  // Process each item
  for (int i = 0; i < N; i++) {
    // Read the height A and cost B of the current item
    cin >> A >> B;
    // Update amax if the current item's height is greater
    if (A >= amax) {
      amax = A;
    }
    // Update the minimum cost for achieving height A
    dp[A] = min(dp[A], B);
    // Update the minimum cost for all heights from A+1 to H+A+1
    for (int j = A + 1; j <= H + amax + 1; j++) {
      dp[j] = min(dp[j], dp[j-A] + B); // Calculate the minimum cost for height j
    }
  }
  
  // Print the minimum cost to achieve height H considering all possible heights up to amax
  cout << *min_element(dp.begin() + H, dp.begin() + H + amax + 1) << endl;
}

