
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  vector<int> D(N, -1);
  D[0] = 0;
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()) {
    int q = Q.front();
    Q.pop();
    for (int j = 0; j < N; j++) {
      if (S[q][j] == '0') {
        continue;
      }
      if (D[j] == -1) {
        D[j] = D[q] + 1;
        Q.push(j);
      } else if (D[j] % 2 == D[q] % 2) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  vector<vector<int>> G(N, vector<int>(N, 1e9));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) {
        continue;
      }
      if (S[i][j] == '0') {
        G[i][j] = 1e9;
      }
    }
  }
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      ans = max(ans, G[i][j]);
    }
  }
  cout << ans + 1 << endl;
  return 0;
}

