
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the next line from standard input
char* NextLine() {
  int c;
  char* line = NULL;
  size_t len = 0;
  while ((c = getchar())!= '\n' && c!= EOF) {
    line = (char*)realloc(line, len + 1);
    if (!line) {
      return NULL;
    }
    line[len++] = (char)c;
  }
  if (c == EOF) {
    return NULL;
  }
  line = (char*)realloc(line, len + 1);
  if (!line) {
    return NULL;
  }
  line[len] = '\0';
  return line;
}

// Function to read the next integer from standard input
int NextInt() {
  int n;
  scanf("%d", &n);
  return n;
}

// Function to write output to standard output
void Write(int n) {
  printf("%d\n", n);
}

// Function to check if the graph is bipartite
int Bipartite(char** S, int N) {
  int* D = (int*)malloc(sizeof(int) * N);
  int* Q = (int*)malloc(sizeof(int) * N);
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
  free(D);
  free(Q);
  return ret;
}

// Function to perform the Floyd-Warshall algorithm to find the longest shortest path
int WarshallFloyd(char** S, int N) {
  int** G = (int**)malloc(sizeof(int*) * N);
  for (int i = 0; i < N; i++) {
    G[i] = (int*)malloc(sizeof(int) * N);
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
  for (int i = 0; i < N; i++) {
    free(G[i]);
  }
  free(G);
  return ans + 1;
}

// Main function to execute the program
int main() {
  int N = NextInt();
  char** S = (char**)malloc(sizeof(char*) * N);
  for (int i = 0; i < N; i++) {
    S[i] = NextLine();
  }
  int ret = Bipartite(S, N);
  if (!ret) {
    Write(-1);
  } else {
    Write(WarshallFloyd(S, N));
  }
  return 0;
}

