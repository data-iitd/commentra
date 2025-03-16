

#include <iostream>
#include <vector>
#include <algorithm>

// Function to find the minimum value among a variable number of integers
int min(std::vector<int> n) {
  if (n.empty()) {
    throw std::invalid_argument("n is empty"); // Throw an exception if n is empty
  }
  int r = n[0]; // Initialize result with the first element
  for (int i = 1; i < n.size(); i++) {
    if (n[i] <= r) { // Update result if a smaller element is found
      r = n[i];
    }
  }
  return r; // Return the minimum value
}

int main() {
  int H, N, A, B; // Declare variables to store input values
  std::cin >> H >> N; // Read the values of H and N from standard input
  std::vector<int> dp(H + 10001, 21000000000); // Create a vector for dynamic programming with a large initial value
  int amax = 0; // Initialize variable to keep track of the maximum attack value
  for (int i = 0; i < N; i++) {
    std::cin >> A >> B; // Read the attack value A and the cost B for each attack
    if (A >= amax) {
      amax = A; // Update amax if the current attack value is greater than or equal to the current amax
    }
    dp[A] = std::min(dp[A], B); // Update the cost for attack value A
    for (int j = A + 1; j <= H + A + 1; j++) {
      dp[j] = std::min(dp[j], dp[j - A] + B); // Update the cost for all possible health values using the current attack
    }
  }
  std::cout << min(std::vector<int>(dp.begin() + H, dp.begin() + H + amax + 1)) << std::endl; // Print the minimum cost to reduce health H to zero or below
  return 0;
}

These comments provide a clear explanation of each part of the code, making it easier to understand the logic and purpose of each block.