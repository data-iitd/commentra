
#include <bits/stdc++.h>

using namespace std;

// Function to find the minimum value among a variable number of integers
int min(int n,...) {
  va_list args;
  va_start(args, n);
  int r = va_arg(args, int); // Initialize result with the first element
  for (int i = 1; i < n; i++) {
    if (va_arg(args, int) <= r) { // Update result if a smaller element is found
      r = va_arg(args, int);
    }
  }
  va_end(args);
  return r; // Return the minimum value
}

int main() {
  int H, N, A, B; // Declare variables to store input values
  cin >> H >> N; // Read the values of H and N from standard input
  vector<int> dp(H + 10001, 2100000000); // Create a vector for dynamic programming with a large initial value
  int amax = 0; // Initialize variable to keep track of the maximum attack value
  for (int i = 0; i < N; i++) {
    cin >> A >> B; // Read the attack value A and the cost B for each attack
    if (A >= amax) {
      amax = A; // Update amax if the current attack value is greater than or equal to the current amax
    }
    dp[A] = min(dp[A], B); // Update the cost for attack value A
    for (int j = A + 1; j <= H + A + 1; j++) {
      dp[j] = min(dp[j], dp[j - A] + B); // Update the cost for all possible health values using the current attack
    }
  }
  cout << min(dp.begin() + H, dp.begin() + H + amax + 1, [](int a, int b) { return a < b; }) - dp.begin(); // Print the minimum cost to reduce health H to zero or below
}

