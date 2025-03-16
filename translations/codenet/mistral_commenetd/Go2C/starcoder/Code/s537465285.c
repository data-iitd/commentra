
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <assert.h>

// Function to read a single line from standard input
char* NextLine() {
  char* buffer = NULL;
  size_t len = 0;
  ssize_t read;
  if ((read = getline(&buffer, &len, stdin))!= -1) {
    return buffer;
  }
  free(buffer);
  return NULL;
}

// Function to read an integer from standard input
int NextInt() {
  char* line = NextLine();
  int n = atoi(line);
  free(line);
  return n;
}

// Function to write a value to standard output
void Write(int n) {
  printf("%d\n", n);
}

// Function to check if a given graph is bipartite
bool Bipartite(char** S, int N) {
  // Initialize degree array
  int* D = (int*)malloc(N * sizeof(int));
  D[0] = 1;

  // Initialize queue
  int* Q = (int*)malloc(N * sizeof(int));

  // Initialize result
  bool ret = true;

  // Initialize position in queue
  int pos = 1;

  // Iterate over each vertex
  for (int i = 0; i < N; i++) {
    if (!ret) { break; }

    // Get current vertex
    int q = Q[i];

    // Iterate over each neighbor of the current vertex
    for (int j = 0; j < N; j++) {
      if (S[q][j] == '0') {
        continue;
      }

      // If neighbor is not visited yet
      if (D[j] == 0) {
        // Mark neighbor as visited
        D[j] = D[q] + 1;

        // Add neighbor to queue
        Q[pos] = j;
        pos++;

        // Continue to next neighbor
        continue;
      }

      // If degrees of current and neighbor are different
      if (D[j] % 2!= D[q] % 2) {
        // Graph is not bipartite
        ret = false;
        break;
      }
    }
  }

  // Return result
  return ret;
}

// Function to find the shortest distance between all pairs of vertices using Floyd-Warshall algorithm
int WarshallFloyd(char** S, int N) {
  // Initialize adjacency matrix
  int** G = (int**)malloc(N * sizeof(int*));
  for (int i = 0; i < N; i++) {
    G[i] = (int*)malloc(N * sizeof(int));
    for (int j = 0; j < N; j++) {
      if (i == j) { continue; }
      if (S[i][j] == '0') {
        G[i][j] = INT_MAX;
      } else {
        G[i][j] = 1;
      }
    }
  }

  // Iterate over all vertices k
  for (int k = 0; k < N; k++) {
    // Iterate over all vertices i
    for (int i = 0; i < N; i++) {
      // Iterate over all vertices j
      for (int j = 0; j < N; j++) {
        // Update shortest distance if found
        if (G[i][k] + G[k][j] < G[i][j]) {
          G[i][j] = G[i][k] + G[k][j];
        }
      }
    }
  }

  // Initialize answer as maximum distance
  int ans = 0;

  // Iterate over all vertices i
  for (int i = 0; i < N; i++) {
    // Iterate over all vertices j
    for (int j = 0; j < N; j++) {
      // Update answer if found
      if (ans < G[i][j]) { ans = G[i][j]; }
    }
  }

  // Return answer plus one
  return ans + 1;
}

// Main function
int main() {
  // Read number of vertices
  int N = NextInt();

  // Initialize graph
  char** S = (char**)malloc(N * sizeof(char*));
  for (int i = 0; i < N; i++) {
    S[i] = NextLine();
  }

  // Check if graph is bipartite
  if (!Bipartite(S, N)) {
    // Write -1 if graph is not bipartite
    Write(-1);
  } else {
    // Write shortest distance between all pairs of vertices
    Write(WarshallFloyd(S, N));
  }

  // Free memory
  for (int i = 0; i < N; i++) {
    free(S[i]);
  }
  free(S);

  // Flush writer buffer
  fflush(stdout);
}

