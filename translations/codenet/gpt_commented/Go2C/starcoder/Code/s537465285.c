

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

// Function to read the next line from standard input
char* NextLine() {
  char* buffer = NULL;
  size_t len = 0;
  ssize_t read;
  if ((read = getline(&buffer, &len, stdin)) == -1) {
    exit(EXIT_FAILURE);
  }
  return buffer;
}

// Function to read the next integer from standard input
int NextInt() {
  char* line = NextLine();
  int n = atoi(line);
  free(line);
  return n;
}

// Function to write output to standard output
void Write(int n) {
  printf("%d\n", n);
}

// Function to check if the graph is bipartite
bool Bipartite(char** S, int N) {
  int* D = (int*) malloc(N * sizeof(int)); // Distance array to store levels of nodes
  D[0] = 1; // Start with the first node at level 1
  int* Q = (int*) malloc(N * sizeof(int)); // Queue for BFS
  bool ret = true; // Variable to track if the graph is bipartite
  int pos = 1; // Position in the queue

  // Perform BFS to check for bipartiteness
  for (int i = 0; i < N; i++) {
    if (!ret) { break; } // Exit if already determined not bipartite
    int q = Q[i]; // Current node
    for (int j = 0; j < N; j++) {
      if (S[q][j] == '0') {
        continue; // Skip if there is no edge
      }
      if (D[j] == 0) {
        // Assign level to the adjacent node
        D[j] = D[q] + 1;
        Q[pos] = j; // Add to queue
        pos++;
        continue;
      }
      // Check if the adjacent node has the same level
      if (D[j] % 2 == D[q] % 2) {
        ret = false; // Not bipartite
        break;
      }
    }
  }
  free(D);
  free(Q);
  return ret; // Return the result of bipartiteness check
}

// Function to perform the Floyd-Warshall algorithm to find the longest shortest path
int WarshallFloyd(char** S, int N) {
  int* G = (int*) malloc(N * sizeof(int*)); // Initialize the graph matrix

  // Initialize the graph with distances
  for (int i = 0; i < N; i++) {
    G[i] = (int*) malloc(N * sizeof(int));
    for (int j = 0; j < N; j++) {
      if (i == j) { continue; } // Skip self-loops
      if (S[i][j] == '0') {
        G[i][j] = N; // No edge, set to a large value
      } else {
        G[i][j] = 1; // Edge exists, set distance to 1
      }
    }
  }

  // Floyd-Warshall algorithm to find shortest paths
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (G[i][k] + G[k][j] < G[i][j]) {
          G[i][j] = G[i][k] + G[k][j]; // Update shortest path
        }
      }
    }
  }

  // Find the maximum distance in the graph
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (ans < G[i][j]) { ans = G[i][j]; } // Update maximum distance
    }
  }
  free(G);
  return ans + 1; // Return the maximum distance found
}

// Main function to execute the program
int main() {
  int N = NextInt(); // Read the number of nodes
  char** S = (char**) malloc(N * sizeof(char*)); // Initialize the adjacency matrix
  for (int i = 0; i < N; i++) {
    S[i] = NextLine(); // Read each line of the adjacency matrix
  }
  
  // Check if the graph is bipartite and process accordingly
  if (!Bipartite(S, N)) {
    Write(-1); // Output -1 if not bipartite
  } else {
    Write(WarshallFloyd(S, N)); // Output the longest shortest path if bipartite
  }
  
  return 0;
}

