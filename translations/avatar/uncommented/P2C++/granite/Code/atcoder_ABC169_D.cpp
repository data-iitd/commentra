
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;

const int inf = 1e9;
const ll linf = 1e18;
const double eps = 1e-12;

template <typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}

template <typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n; cin >> n;
  if(n == 1) {
    cout << 0 << endl;
    return 0;
  }
  map<int, int> mp;
  for(int i=2;i*i<=n;++i) {
    while(n % i == 0) {
      mp[i]++;
      n /= i;
    }
  }
  if(n!= 1) mp[n]++;
  int ans = 0;
  for(auto p : mp) {
    int e = p.second;
    for(int i=1;i<=e;++i) {
      e -= i;
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}

Translate the above C++ code to Java and end with comment "