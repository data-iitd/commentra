#include <bits/stdc++.h>

using namespace std;

// Reader for input
auto reader = [](char *s, int sz) {
  return scanf("%s", s);
};

// Writer for output
auto writer = [](char *s) {
  printf("%s", s);
};

// NextLine reads a line of input
auto NextLine = [&]() {
  char s[1000000];
  return scanf("%s", s);
};

// NextInt reads an integer from input
auto NextInt = [&]() {
  int n;
  scanf("%d", &n);
  return n;
};

// Write prints a line to the output
auto Write = [](auto &&s) {
  printf("%s\n", s);
};

// Output flushes the writer to ensure all buffered data is written
auto Output = [&]() {
  fflush(stdout);
};

// Bipartite checks if a graph is bipartite
auto Bipartite = [](auto &S) {
  int N = S.size();
  vector<int> D(N, 0); // Distance array
  D[0] = 1; // Start from the first vertex
  queue<int> Q; // Queue for BFS
  bool ret = true; // Return value
  int pos = 1; // Position in the queue
  while (ret && pos > 0) {
    int q = Q.front();
    Q.pop();
    pos--;
    for (int j = 0; j < N; j++) {
      if (!ret) { break; }
      if (D[j] == 0) {
        D[j] = D[q] + 1;
        Q.push(j);
        pos++;
        continue;
      }
      if (D[j] % 2 == D[q] % 2) {
        ret = false;
        break;
      }
    }
  }
  return ret;
};

// WarshallFloyd computes the shortest paths between all pairs of vertices
auto WarshallFloyd = [](auto &S) {
  int N = S.size();
  vector<vector<int>> G(N, vector<int>(N, 0));
  for (int i = 0; i < N; i++) {
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
};

// Main function to execute the program
int main() {
  int N = NextInt();
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    reader(S[i].data(), S[i].size());
  }
  if (!Bipartite(S)) {
    Write(-1); // If not bipartite, write -1
  } else {
    Write(WarshallFloyd(S)); // Otherwise, compute and write the result
  }
  Output(); // Flush the writer
  return 0;
}

