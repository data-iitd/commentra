#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_N 100000

// Reads a line of input
char* NextLine() {
  char* line = NULL;
  size_t len = 0;
  ssize_t read;
  if ((read = getline(&line, &len, stdin)) == -1) {
    exit(EXIT_FAILURE);
  }
  return line;
}

// Reads an integer from input
int NextInt() {
  char* line = NextLine();
  int n = atoi(line);
  free(line);
  return n;
}

// Prints a line to output
void Write(int n) {
  printf("%d\n", n);
}

// Flushes the output
void Output() {
  fflush(stdout);
}

// Checks if a graph is bipartite
bool Bipartite(char** S, int N) {
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

// Computes the shortest paths between all pairs of vertices
int WarshallFloyd(char** S, int N) {
  int G[MAX_N][MAX_N];
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
}

// Main function to execute the program
int main() {
  int N = NextInt();
  char* S[MAX_N];
  for (int i = 0; i < N; i++) {
    S[i] = NextLine();
  }
  if (!Bipartite(S, N)) {
    Write(-1); // If not bipartite, write -1
  } else {
    Write(WarshallFloyd(S, N)); // Otherwise, compute and write the result
  }
  Output(); // Flush the writer
  return 0;
}

