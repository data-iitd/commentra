
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// Bipartite checks if a graph is bipartite
bool Bipartite(vector<string> S) {
  int N = S.size();
  vector<int> D(N); // Distance array
  D[0] = 1; // Start from the first vertex
  queue<int> Q; // Queue for BFS
  bool ret = true; // Return value
  int pos = 1; // Position in the queue
  for (int i = 0; i < N; i++) {
    if (!ret) { break; }
    int q = Q.front();
    Q.pop();
    for (int j = 0; j < N; j++) {
      if (S[q][j] == '0') {
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

// WarshallFloyd computes the shortest paths between all pairs of vertices
int WarshallFloyd(vector<string> S) {
  int N = S.size();
  vector<vector<int>> G(N);
  for (int i = 0; i < N; i++) {
    G[i] = vector<int>(N);
    for (int j = 0; j < N; j++) {
      if (i == j) { continue; }
      if (S[i][j] == '0') {
        G[i][j] = N; // Set distance to a large number
      } else {
        G[i][j] = 1; // Direct edge weight
      }
    }
  }
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (G[i][k] + G[k][j] < G[i][j]) {
          G[i][j] = G[i][k] + G[k][j]; // Update shortest path
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (ans < G[i][j]) { ans = G[i][j]; } // Find the maximum distance
    }
  }
  return ans + 1; // Return the result
}

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  if (!Bipartite(S)) {
    cout << -1 << endl; // If not bipartite, write -1
  } else {
    cout << WarshallFloyd(S) << endl; // Otherwise, compute and write the result
  }
  return 0;
}

