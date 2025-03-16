#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define M 100
#define whi 0
#define gra 1
#define bla 2

int n; // Number of nodes in the graph
vector<vector<int>> T(M, vector<int>(M, 0)); // Adjacency matrix to represent the graph
vector<int> color(M), d(M); // Arrays to keep track of colors and distances
queue<int> Q; // Queue for BFS

// Function to perform Breadth-First Search (BFS) starting from node s
void bfs(int s) {
  int i, u, v;

  // Initialize all nodes to white, set distance to infinity
  for (i = 0; i < n; i++) {
    color[i] = whi;
    d[i] = 1000000;
  }

  // Set the color and distance of the source node
  color[s] = gra;
  d[s] = 0;
  Q.push(s);

  // Continue BFS until the queue is empty
  while (!Q.empty()) {
    u = Q.front(); // Dequeue the front node
    Q.pop(); // Dequeue the front node
    // Explore all adjacent nodes
    for (v = 0; v < n; v++) {
      if (T[u][v] == 1 && color[v] == whi) {
        color[v] = gra; // Mark as gray
        d[v] = d[u] + 1; // Update distance
        Q.push(v); // Enqueue the node
      }
    }
    color[u] = bla; // Mark as black
  }
}

// Main function to read the graph, execute BFS, and print distances
int main() {
  int i, j;
  int u, k, v;

  cin >> n; // Read the number of nodes

  // Read the edges and construct the adjacency matrix
  for (i = 0; i < n; i++) {
    cin >> u >> k;
    u--; // Convert to 0-based index
    for (j = 0; j < k; j++) {
      cin >> v;
      v--; // Convert to 0-based index
      T[u][v] = 1; // Set the edge in the adjacency matrix
    }
  }

  bfs(0); // Execute BFS starting from node 0

  // Print the distances from the source node to all other nodes
  for (i = 0; i < n; i++) {
    if (d[i] == 1000000) d[i] = -1; // If unreachable, set distance to -1
    cout << i + 1 << " " << d[i] << endl; // Print node number and distance
  }

  return 0;
}
