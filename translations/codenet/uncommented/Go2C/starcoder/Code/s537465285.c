#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 100000

int main() {
  int N;
  scanf("%d", &N);
  char S[MAX_N][MAX_N];
  for (int i = 0; i < N; i++) {
    scanf("%s", S[i]);
  }
  if (Bipartite(S, N)) {
    printf("%d\n", WarshallFloyd(S, N));
  } else {
    printf("-1\n");
  }
  return 0;
}

bool Bipartite(char S[MAX_N][MAX_N], int N) {
  int D[MAX_N];
  int Q[MAX_N];
  bool ret = true;
  int pos = 0;
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
        ret = false;
        break;
      }
    }
  }
  return ret;
}

int WarshallFloyd(char S[MAX_N][MAX_N], int N) {
  int G[MAX_N][MAX_N];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) { continue; }
      if (S[i][j] == '0') {
        G[i][j] = N;
      } else {
        G[i][j] = 1;
      }
    }
  }
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (G[i][k] + G[k][j] < G[i][j]) {
          G[i][j] = G[i][k] + G[k][j];
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (ans < G[i][j]) { ans = G[i][j]; }
    }
  }
  return ans + 1;
}

