
#include <iostream>
#include <vector>
#include <algorithm>

// min function returns the minimum value from a variable number of integer arguments.
// It panics if no arguments are provided.
int min(int n,...) {
  va_list args;
  va_start(args, n);
  int r = va_arg(args, int);
  for (int i = 1; i < n; i++) {
    int v = va_arg(args, int);
    if (v <= r) {
      r = v;
    }
  }
  va_end(args);
  return r;
}

int main() {
  int H, N, A, B;
  std::cin >> H >> N;

  std::vector<int> dp(H + 10001, 21000000000); // Initialize dynamic programming array
  int amax = 0; // Variable to track the maximum height of items

  for (int i = 0; i < N; i++) {
    std::cin >> A >> B;
    if (A >= amax) {
      amax = A;
    }
    dp[A] = std::min(dp[A], B); // Update the minimum cost for height A
    for (int j = A + 1; j <= H + amax + 1; j++) {
      dp[j] = std::min(dp[j], dp[j - A] + B); // Calculate the minimum cost for height j
    }
  }

  int ans = 21000000000; // Initialize the minimum cost to a large value (infinity)
  for (int i = H; i <= H + amax; i++) {
    ans = std::min(ans, dp[i]); // Update the minimum cost to achieve height H considering all possible heights up to amax
  }

  std::cout << ans << std::endl; // Print the minimum cost to achieve height H considering all possible heights up to amax

  return 0;
}

