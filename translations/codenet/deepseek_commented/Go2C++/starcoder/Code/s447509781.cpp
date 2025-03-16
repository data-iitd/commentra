
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n; cin >> n;
  vector<int> s(n);
  for (int i=0;i<n;i++) cin >> s[i];
  int m = 0;
  for (int c=1;c<n-1;c++) {
    int f = 0;
    for (int k=0;c<n-1-k*c;k++) {
      bool u[n];
      fill(u,u+n,false);
      u[k*c] = true;
      if (u[n-1-k*c]) break;
      f += s[n-1-k*c]+s[k*c];
      if (m < f) m = f;
    }
  }
  cout << m << endl;
}

