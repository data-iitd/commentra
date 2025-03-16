#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000
#define MAX_M 100000

// Bipartite checks if a graph is bipartite
int bipartite(char **S, int N) {
  int D[MAX_N]; // Distance array
  int Q[MAX_N]; // Queue for BFS
  int ret = 1; // Return value
  int pos = 0; // Position in the queue
  D[0] = 1; // Start from the first vertex
  Q[pos] = 0;
  pos++;
  for (int i = 0; i < N; i++) {
    if (!ret) { break; }
    int q = Q[i];
    for (int j = 0; j < N; j++) {
      if (S[q][j] == '0') {
        continue;
      }
      if (D[j] == 0) {
        D[j] = D[q] + 1;
        Q[pos] = j;
        pos++;
        continue;
      }
      if (D[j] % 2 == D[q] % 2) {
        ret = 0;
        break;
      }
    }
  }
  return ret;
}

// WarshallFloyd computes the shortest paths between all pairs of vertices
int warshallFloyd(char **S, int N) {
  int G[MAX_N][MAX_N];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) { continue; }
      if (S[i][j] == '0') {
        G[i][j] = MAX_N; // Set distance to a large number
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

// Main function to execute the program
int main() {
  int N;
  scanf("%d", &N);
  char **S = (char **)malloc(N * sizeof(char *));
  for (int i = 0; i < N; i++) {
    S[i] = (char *)malloc(N * sizeof(char));
    scanf("%s", S[i]);
  }
  if (!bipartite(S, N)) {
    printf("-1\n"); // If not bipartite, write -1
  } else {
    printf("%d\n", warshallFloyd(S, N)); // Otherwise, compute and write the result
  }
  return 0;
}

