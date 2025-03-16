

#include <iostream>
#include <queue>
#include <vector>

#define M 100
#define whi 0
#define gra 1
#define bla 2

using namespace std;

int n; // Number of nodes in the graph
vector<int> T[M]; // Adjacency list to represent the graph
int color[M], d[M]; // Arrays to keep track of colors and distances
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
    Q.pop();
    // Explore all adjacent nodes
    for (i = 0; i < T[u].size(); i++) {
      v = T[u][i];
      if (color[v] == whi) {
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

  // Initialize the adjacency list with empty vectors
  for (i = 0; i < n; i++) {
    T[i] = vector<int>();
  }

  // Read the edges and construct the adjacency list
  for (i = 0; i < n; i++) {
    cin >> u >> k;
    u--; // Convert to 0-based index
    for (j = 0; j < k; j++) {
      cin >> v;
      v--; // Convert to 0-based index
      T[u].push_back(v); // Add the edge to the adjacency list
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

