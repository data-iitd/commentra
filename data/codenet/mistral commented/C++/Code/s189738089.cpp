
#include <iostream>
#include <vector>
#define rep(i, k, n) for (int i = k; i < n; ++i)
using namespace std;

template<class T> inline void chmin(T &a, T b) {
  // Minimum update function
  if (a > b) a = b;
  return;
}

const int INF = 1 << 30;

// Main function
int main(){
  // Initialize dynamic programming vector dp with initial value INF for all indices
  vector<int> dp(101000, INF);
  dp.at(0) = 0;

  // Read input
  int N, K; // Number of elements in the array and the size of the window
  cin >> N >> K;
  vector<int> h(N); // Array of heights
  rep(i, 0, N) cin >> h[i]; // Read each height from the input

  // Dynamic programming calculation
  rep(i, 0, N) { // Iterate through all indices i
    rep(j, 1, K + 1) { // Iterate through all window sizes j
      // Update dp[i + j] with the minimum cost to reach this index with window size j
      chmin(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
    }
  }

  // Output the result
  cout << dp[N - 1] << endl; // Print the minimum cost to reach the last index with window size K
  return 0;
}