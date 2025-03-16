

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<string> ans(n);

  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;

    for (int j = 0; j < m; j++) {
      if (str[j] == '-') {
        ans[i] += "-";
      } else {
        if ((i + j) % 2 == 1) {
          ans[i] += "W";
        } else {
          ans[i] += "B";
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}

