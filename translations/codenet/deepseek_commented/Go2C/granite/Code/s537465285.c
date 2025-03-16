
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
char **S;
int *D;
int *Q;
int pos;
int ret;

void NextLine(char *line) {
  fgets(line, 1000000, stdin);
}

int NextInt() {
  char line[1000000];
  NextLine(line);
  return atoi(line);
}

void Write(int n) {
  printf("%d\n", n);
}

void Output() {
  fflush(stdout);
}

int Bipartite() {
  N = NextInt();
  S = (char **)malloc(sizeof(char *) * N);
  for (int i = 0; i < N; i++) {
    S[i] = (char *)malloc(sizeof(char) * N);
    NextLine(S[i]);
  }
  D = (int *)malloc(sizeof(int) * N);
  Q = (int *)malloc(sizeof(int) * N);
  D[0] = 1;
  Q[0] = 0;
  pos = 1;
  ret = 1;
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

int WarshallFloyd() {
  int ans = 0;
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (D[i][k] + D[k][j] < D[i][j]) {
          D[i][j] = D[i][k] + D[k][j];
        }
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (ans < D[i][j]) { ans = D[i][j]; }
    }
  }
  return ans + 1;
}

int main() {
  if (!Bipartite()) {
    Write(-1);
  } else {
    Write(WarshallFloyd());
  }
  Output();
  return 0;
}

