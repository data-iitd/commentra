#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min(int n, int m) {
  if (n <= m) {
    return n;
  } else {
    return m;
  }
}

int main() {
  int H, N, A, B;
  cin >> H >> N;
  vector<int> dp(H+10001, 2100000000);
  int amax = 0;
  for (int i = 0; i < N; i++) {
    cin >> A >> B;
    if (A >= amax) {
      amax = A;
    }
    dp[A] = min(dp[A], B);
    for (int j = A+1; j <= H+A+1; j++) {
      dp[j] = min(dp[j], dp[j-A] + B);
    }
  }
  cout << min(dp[H:H+amax+1]...) << endl;
  return 0;
}

