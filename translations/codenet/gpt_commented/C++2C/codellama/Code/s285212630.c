#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <assert.h>

// Define long long as int for convenience
#define int long long
typedef struct P {
  int _1;
  int _2;
} P;

// Macros for loop and container operations
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define _1 first
#define _2 second
#define pb push_back

// Constants for maximum levels, infinity, and modulo
#define INF 1145141919
#define MOD 1000000007
#define MAX_L 22

// Global variables
int N; // Number of nodes in the tree
P *G[100000]; // Adjacency list representation of the tree
int U[MAX_L][100000], R[100000]; // U for storing ancestors, R for depth
long long L[100000]; // L for storing the distance from the root

// Depth-first search to initialize ancestor and depth information
void dfs(int x, int p, int r, long long l) {
  U[0][x] = p; // Set the parent of the current node
  R[x] = r; // Set the depth of the current node
  L[x] = l; // Set the distance from the root to the current node
  for (P *pp = G[x]; pp != NULL; pp = pp->_1) { // Iterate through all adjacent nodes
    int t = pp->_1; // Get the adjacent node
    if (t == p) continue; // Skip the parent node to avoid cycles
    dfs(t, x, r+1, l+pp->_2); // Recursive DFS call for the child node
  }
}

// Function to find the lowest common ancestor (LCA) of two nodes
int lca(int a, int b) {
  if (R[a] > R[b]) swap(a, b); // Ensure a is the deeper node
  for (int k=0; k<MAX_L; k++) { // Adjust b to the same depth as a
    if ((R[a] - R[b]) >> k & 1) b = U[k][b];
  }
  if (a == b) return a; // If both nodes are the same, return a
  for (int k=MAX_L-1; k>=0; k--) { // Find the LCA using binary lifting
    if (U[k][a] != U[k][b]) {
      a = U[k][a];
      b = U[k][b];
    }
  }
  return U[0][a]; // Return the parent of a, which is the LCA
}

// Function to calculate the distance between two nodes
long long dist(int x, int y) {
  int g = lca(x, y); // Find the LCA of x and y
  return L[x] + L[y] - 2LL*L[g]; // Calculate the distance using LCA
}

int main() {
  // Optimize input/output
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  
  // Read the number of nodes
  scanf("%d", &N);
  
  // Allocate memory for the adjacency list
  G = malloc(N * sizeof(P*));
  rep(i, N) G[i] = NULL;
  
  // Read the edges of the tree
  rep(i, N-1) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    a--, b--; // Convert to 0-based indexing
    // Add edge to the adjacency list
    G[a] = realloc(G[a], (i+2) * sizeof(P));
    G[a][i] = (P){b, c};
    G[a][i+1] = NULL;
    G[b] = realloc(G[b], (i+2) * sizeof(P));
    G[b][i] = (P){a, c};
    G[b][i+1] = NULL;
  }
  
  // Initialize the ancestor table with -1
  rep(i, MAX_L) rep(j, N) U[i][j] = -1;
  
  // Perform DFS from the root to fill ancestor and depth information
  dfs(0, -1, 0, 0);
  
  // Precompute ancestors for binary lifting
  for (int i=0; i<MAX_L-1; i++) {
    for (int v=0; v<N; v++) {
      if (U[i][v] == -1) U[i+1][v] = -1; // If no ancestor, set to -1
      U[i+1][v] = U[i][U[i][v]]; // Set the 2^(i+1) ancestor
    }
  }
  
  int Q, K; // Number of queries and a specific node K
  scanf("%d %d", &Q, &K); // Read number of queries and node K
  K--; // Convert K to 0-based indexing
  
  // Process each query
  rep(i, Q) {
    int x, y; // Nodes for which distance is to be calculated
    scanf("%d %d", &x, &y); // Read the nodes
    x--, y--; // Convert to 0-based indexing
    // Output the total distance from x to K and K to y
    printf("%lld\n", dist(x, K) + dist(K, y));
  }
  
  // Free memory
  rep(i, N) free(G[i]);
  free(G);
  
  return 0; // End of the program
}

