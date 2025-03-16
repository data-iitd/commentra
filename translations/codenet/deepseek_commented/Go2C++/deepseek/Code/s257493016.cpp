#include <iostream>
#include <vector>
#include <climits>
#include <stdexcept>

// Function to find the minimum value among a variable number of integers
int min(std::vector<int> n) {
  if (n.empty()) {
    throw std::invalid_argument("Vector is empty"); // Throw an exception if the vector is empty
  }
  int r = n[0]; // Initialize result with the first element
  for (size_t i = 1; i < n.size(); i++) {
    if (n[i] < r) { // Update result if a smaller element is found
      r = n[i];
    }
  }
  return r; // Return the minimum value
}

int main() {
  int H, N, A, B; // Declare variables to store input values
  std::cin >> H >> N; // Read the values of H and N from standard input
  std::vector<int> dp(H + 10001, INT_MAX); // Create a vector for dynamic programming with a large initial value
  dp[0] = 0; // Initialize the cost for health 0 to 0
  int amax = 0; // Initialize variable to keep track of the maximum attack value
  for (int i = 0; i < N; i++) {
    std::cin >> A >> B; // Read the attack value A and the cost B for each attack
    if (A > amax) {
      amax = A; // Update amax if the current attack value is greater than the current amax
    }
    for (int j = A; j <= H; j++) {
      dp[j] = std::min(dp[j], dp[j - A] + B); // Update the cost for all possible health values using the current attack
    }
  }
  int result = INT_MAX; // Initialize result to a large value
  for (int i = H; i <= H + amax; i++) {
    result = std::min(result, dp[i]); // Find the minimum cost to reduce health H to zero or below
  }
  std::cout << result << std::endl; // Print the minimum cost
  return 0;
}

