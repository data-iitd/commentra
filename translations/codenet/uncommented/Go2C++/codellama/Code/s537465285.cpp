#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  if (!Bipartite(&S)) {
    cout << -1 << endl;
  } else {
    cout << WarshallFloyd(&S) << endl;
  }
  return 0;
}

bool Bipartite(vector<string> *S) {
  int N = S->size();
  vector<int> D(N, 0);
  D[0] = 1;
  queue<int> Q;
  Q.push(0);
  bool ret = true;
  while (!Q.empty()) {
    int q = Q.front();
    Q.pop();
    for (int j = 0; j < N; j++) {
      if ((*S)[q][j] == '0') {
        continue;
      }
      if (D[j] == 0) {
        D[j] = D[q] + 1;
        Q.push(j);
        continue;
      }
      if (D[j] % 2 == D[q] % 2) {
        ret = false;
        break;
      }
    }
  }
  return ret;
}

int WarshallFloyd(vector<string> *S) {
  int N = S->size();
  vector<vector<int>> G(N, vector<int>(N, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) { continue; }
      if ((*S)[i][j] == '0') {
        G[i][j] = N;
      } else {
        G[i][j] = 1;
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
  return ans + 1;
}

