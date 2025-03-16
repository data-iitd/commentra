
#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int k;
  cin >> k;

  vector<vector<int>> patterns;
  for (int i = 0; i < (1 << k); i++) {
    vector<int> pattern;
    for (int j = 0; j < k; j++) {
      pattern.push_back(i & (1 << j));
    }
    patterns.push_back(pattern);
  }

  for (auto pattern : patterns) {
    int r = a, g = b, b_ = c;
    for (int i = 0; i < k; i++) {
      if (pattern[i] == 0) {
        continue;
      } else if (pattern[i] == 1) {
        r *= 2;
      } else if (pattern[i] == 2) {
        g *= 2;
      } else if (pattern[i] == 3) {
        b_ *= 2;
      }
    }

    if (g > r && b_ > g) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;

  return 0;
}

