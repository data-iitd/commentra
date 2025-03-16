#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;

int main() {
  ll H, W;
  cin >> H >> W; // Step 1: Reading the values of H and W from the standard input.

  ll ans;
  if (H == 1 || W == 1) {
    ans = 1; // Step 2: Handling the special case where either H or W is 1.
  } else {
    ll m = H*W; // Step 3: Calculating the total area of the grid.
    if (m % 2 == 0) ans = m/2; // Step 4: If the area is even, half of it is the answer.
    else ans = m/2+1; // Step 5: If the area is odd, half of it plus one is the answer.
  }
  cout << ans << endl; // Step 6: Outputting the calculated minimum number of cells to be painted.
  return 0;
}
