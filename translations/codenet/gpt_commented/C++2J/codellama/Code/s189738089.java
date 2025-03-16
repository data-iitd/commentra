#include <iostream>
#include <vector>
#define rep(i, k, n) for (int i = k; i < n; ++i)
using namespace std;

// Function to update the minimum value
template<class T> inline void chmin(T &a, T b) {if (a > b) a = b; return;}
const int INF = 1 << 30; // Define a constant for infinity

int main(){
  // Initialize a dp vector to store the minimum cost to reach each step
  vector<int> dp(101000, INF);
  dp.at(0) = 0; // Base case: cost to reach the first step is 0

  // Input the number of steps (N) and the maximum jump distance (K)
  int N, K;
  cin >> N >> K;
  vector<int> h(N); // Vector to store the heights of the steps
  rep(i, 0, N) cin >> h[i]; // Read the heights of the steps

  // Dynamic programming to calculate the minimum cost to reach each step
  rep(i, 0, N) {
    // Check possible jumps from the current step
    rep(j, 1, K + 1) {
      // Update the minimum cost to reach step i + j
      chmin(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
    }
  }

  // Output the minimum cost to reach the last step
  cout << dp[N - 1] << endl;
  return 0;
}

