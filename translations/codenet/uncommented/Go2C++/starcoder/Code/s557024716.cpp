
#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;

  vector<vector<int>> patterns;
  patterns = DuplicatePatterns({0, 1, 2, 3}, k);

  for (auto P : patterns) {
    int r = a, g = b, b = c;
    for (int i = 0; i < P.size(); i++) {
      if (P[i] == 0) {
        continue;
      } else if (P[i] == 1) {
        r *= 2;
      } else if (P[i] == 2) {
        g *= 2;
      } else if (P[i] == 3) {
        b *= 2;
      }
    }

    if (g > r && b > g) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;

  return 0;
}

// DuplicatePatterns returns all patterns of n^k of elems([]int).
vector<vector<int>> DuplicatePatterns(vector<int> elems, int k) {
  return dupliRec(vector<int>(), elems, k);
}

// DFS function for DuplicatePatterns.
vector<vector<int>> dupliRec(vector<int> pattern, vector<int> elems, int k) {
  if (pattern.size() == k) {
    return {pattern};
  }

  vector<vector<int>> res;
  for (auto e : elems) {
    vector<int> newPattern = pattern;
    newPattern.push_back(e);

    res = res + dupliRec(newPattern, elems, k);
  }

  return res;
}

