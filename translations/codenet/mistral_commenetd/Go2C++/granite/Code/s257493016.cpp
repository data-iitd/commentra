
#include <iostream>
#include <vector>
#include <algorithm>

// Function to find minimum number in a vector
int min(std::vector<int> n) {
  if (n.empty()) {
    // Panic if the vector is empty
    throw std::runtime_error("len == 0");
  }
  int r = n[0];
  // Initialize minimum value with first element of the vector
  for (int i = 1; i < n.size(); i++) {
    // Compare current element with minimum value and update minimum value if current element is smaller
    if (n[i] <= r) {
      r = n[i];
    }
  }
  // Return the minimum value
  return r;
}

int main() {
  // Initialize variables for number of floors H, number of jumps N, and variables A and B for each jump
  int H, N, A, B;
  std::cin >> H >> N;

  // Initialize a vector dp of size H+10001 with initial value 21000000000
  std::vector<int> dp(H+10001, 21000000000);
  // Initialize maximum reachable floor amax to 0
  int amax = 0;
  // Iterate through each jump
  for (int i = 0; i < N; i++) {
    // Read floor A and number of floors B that can be jumped from floor A
    std::cin >> A >> B;

    // If the maximum reachable floor is less than A, update maximum reachable floor
    if (A >= amax) {
      amax = A;
    }

    // Update dp[A] with minimum of current dp[A] and B
    dp[A] = std::min(dp[A], B);

    // Iterate through floors from A+1 to H+A and update dp[j] with minimum of current dp[j] and dp[j-A]+B
    for (int j = A + 1; j <= H+A+1; j++) {
      dp[j] = std::min(dp[j], dp[j-A]+B);
    }
  }

  // Print the minimum number of jumps required to reach the last floor
  std::cout << min(std::vector<int>(dp.begin()+H, dp.begin()+H+amax+1)) << std::endl;

  // End of code
}

