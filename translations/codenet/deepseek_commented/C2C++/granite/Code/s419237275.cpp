
#include <iostream>

#define N 200  // Maximum number of nodes in the graph
#define SHIRO 0  // Color representing unvisited nodes
#define HAI 1  // Color representing nodes currently in the recursion stack
#define KURO 2  // Color representing nodes fully processed

// Function prototypes
void aaaaa();
void bbbbb(int);

int n, A[N][N];  // n: number of nodes, A: adjacency matrix
int color[N], d[N], f[N];  // color: color of each node, d: discovery time, f: finish time
int TT;  // Time counter

int main() {
  int u, k, v;  // u: current node, k: number of edges from u, v: adjacent node
  int i, j;  // Loop variables

  // Read the number of nodes
  std::cin >> n;

  // Initialize the adjacency matrix to zero
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      A[i][j] = 0;
    }
  }

  // Read the edges for each node and update the adjacency matrix
  for (i = 0; i < n; i++) {
    std::cin >> u >> k;
    u--;  // Adjust for 0-based indexing
    for (j = 0; j < k; j++) {
      std::cin >> v;
      v--;  // Adjust for 0-based indexing
      A[u][v] = 1;
    }
  }

  // Perform DFS and print the results
  aaaaa();

  return 0;
}

// Depth-First Search (DFS) function
void aaaaa() {
  int u, i;  // u: current node, i: loop variable

  // Initialize all nodes to "SHIRO" (unvisited)
  for (i = 0; i < n; i++) {
    color[i] = SHIRO;
  }

  // Set the time counter to zero
  TT = 0;

  // Iterate over all nodes and perform DFS if the node is "SHIRO"
  for (u = 0; u < n; u++) {
    if (color[u] == SHIRO) {
      bbbbb(u);
    }
  }

  // Print the discovery and finish times for each node
  for (i = 0; i < n; i++) {
    std::cout << i + 1 << " " << d[i] << " " << f[i] << std::endl;
  }
}

// Recursive DFS function
void bbbbb(int k) {
  int v;  // v: adjacent node

  // Set the current node's color to "HAI" (currently in the recursion stack)
  color[k] = HAI;
  // Increment the time counter and record the discovery time
  TT++;
  d[k] = TT;

  // Iterate over all nodes and perform DFS recursively if an adjacent node is "SHIRO"
  for (v = 0; v < n; v++) {
    if (A[k][v] == 0) continue;  // Skip if no edge between k and v
    if (color[v] == SHIRO) {
      bbbbb(v);
    }
  }

  // Set the current node's color to "KURO" (fully processed)
  color[k] = KURO;
  // Record the finish time
  f[k] = ++TT;
}

