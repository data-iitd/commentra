
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min(vector<int> n) {
  if (n.size() == 0) {
    throw "len == 0";
  }
  int r = n[0];
  for (int i = 1; i < n.size(); i++) {
    if (n[i] <= r) {
      r = n[i];
    }
  }
  return r;
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
    dp[A] = min({dp[A], B});
    for (int j = A+1; j <= H+A+1; j++) {
      dp[j] = min(dp[j], dp[j-A] + B);
    }
  }
  cout << min(dp.begin()+H, dp.begin()+H+amax+1) << endl;
}

