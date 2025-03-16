
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <random>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const ll MOD = 100000007;
const int INF = 100000000;
const ll LINF = 1ll<<50;
template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}
template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  ll N, d, x; cin >> N >> d >> x;
  ll ret = 0;
  while(N) {
    ret += d + (N - 0.5) * x;
    d = d + d / N + 5 * x / (2 * N);
    x += 2 * x / N;
    N--;
  }
  cout << ret << endl;
  return 0;
}
