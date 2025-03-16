#include <iostream>
#include <vector>
#define rep(i, k, n) for (int i = k; i < n; ++i)
using namespace std;

template<class T> inline void chmin(T &a, T b) {if (a > b) a = b; return;}
const int INF = 1 << 30;

int main(){
  // Initialization of the dp array
  vector<int> dp(101000, INF);
  dp.at(0) = 0;
  // input
  int N, K;
  cin >> N >> K;
  vector<int> h(N);
  rep(i, 0, N) cin >> h[i];

  # <START-OF-CODE>
  # Initialize the dp array
  dp = [INF] * 101000
  dp[0] = 0
  # input
  N, K = map(int, input().split())
  h = list(map(int, input().split()))

  # Dynamic Programming Loop
  for i in range(N):
    for j in range(1, K + 1):
      dp[i + j] = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]))
  # Output
  print(dp[N - 1])
  # 