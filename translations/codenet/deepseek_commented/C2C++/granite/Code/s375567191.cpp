
#include <iostream>

#define MAX 101
#define WHITE 0
#define BLACK 2
#define GRAY 1

int time, n, g[MAX][MAX] = {0};
int d[MAX], f[MAX], color[MAX] = {WHITE};

// The visit function performs a depth-first search on the graph.
void visit(int u) {
  int i;

  color[u] = GRAY;  // Set the color of the current node to gray.
  d[u] = ++time;    // Record the discovery time.

  for (i = 0; i < n; i++) {
    if (g[u][i] == 0)
      continue;  // Skip if there is no edge between u and i.
    if (color[i] == WHITE)
      visit(i);  // Recursively visit adjacent white nodes.
  }

  color[u] = BLACK;  // Set the color of the current node to black.
  f[u] = ++time;     // Record the finishing time.
}

// The dfs function initializes the time and iterates through all nodes.
void dfs(void) {
  int i;
  time = 0;  // Initialize the time.

  for (i = 0; i < n; i++)
    if (color[i] == WHITE)
      visit(i);  // Call visit for any white node.

  for (i = 0; i < n; i++)
    std::cout << i + 1 << " " << d[i] << " " << f[i] << std::endl;  // Print the discovery and finishing times of each node.
}

int main() {
  int i, j, x, y, z;

  std::cin >> n;  // Read the number of nodes.

  for (i = 0; i < n; i++) {
    std::cin >> x >> y;
    for (j = 0; j < y; j++) {
      std::cin >> z;
      g[x - 1][z - 1] = 1;  // Populate the adjacency matrix.
    }
  }

  dfs();  // Call the dfs function to compute and print the discovery and finishing times.
  return 0;
}

