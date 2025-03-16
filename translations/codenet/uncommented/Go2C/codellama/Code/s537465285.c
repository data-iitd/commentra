#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000
#define MAX_M 100000

int N;
char S[MAX_N][MAX_M];
int D[MAX_N];
int Q[MAX_N];

int NextInt() {
  int n;
  scanf("%d", &n);
  return n;
}

int NextLine() {
  char line[MAX_M];
  scanf("%s", line);
  return line;
}

int Bipartite(char S[][MAX_M]) {
  int N = strlen(S[0]);
  int ret = 1;
  int pos = 1;
  D[0] = 1;
  Q[0] = 0;
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

int WarshallFloyd(char S[][MAX_M]) {
  int N = strlen(S[0]);
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

int main() {
  N = NextInt();
  for (int i = 0; i < N; i++) {
    strcpy(S[i], NextLine());
  }
  if (!Bipartite(S)) {
    printf("%d\n", -1);
  } else {
    printf("%d\n", WarshallFloyd(S));
  }
  return 0;
}
