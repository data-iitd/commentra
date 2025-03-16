
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll readInt() {
  ll x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x*10+ch-48;
    ch = getchar();
  }
  return x*f;
}

void solve() {
  ll n = readInt();
  vector<ll> t(n), a(n);
  for (int i = 0; i < n; i++) {
    t[i] = readInt();
    a[i] = readInt();
  }
  ll T = t[0], A = a[0];
  for (int i = 1; i < n; i++) {
    ll r = max((T+t[i]-1)/t[i], (A+a[i]-1)/a[i]);
    T = t[i]*r;
    A = a[i]*r;
  }
  cout << T+A << endl;
}

int main() {
  solve();
  return 0;
}

