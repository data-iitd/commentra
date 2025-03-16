#include <iostream>
#include <vector>
#include <queue>

#define M 100
#define whi 0
#define gra 1
#define bla 2

int n; // Number of nodes in the graph
int T[M][M]; // Adjacency matrix to represent the graph
int color[M], d[M]; // Arrays to keep track of colors and distances

// Function to perform Breadth-First Search (BFS) starting from node s
void bfs(int s) {
    int u, v;

    // Initialize all nodes to white, set distance to infinity
    for (int i = 0; i < n; i++) {
        color[i] = whi;
        d[i] = 1000000;
    }

    // Set the color and distance of the source node
    color[s] = gra;
    d[s] = 0;
    std::queue<int> Q; // Queue for BFS
    Q.push(s); // Enqueue the source node

    // Continue BFS until the queue is empty
    while (!Q.empty()) {
        u = Q.front(); // Get the front node
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
    int u, k, v;

    std::cin >> n; // Read the number of nodes

    // Initialize the adjacency matrix with zeros
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            T[i][j] = 0;
        }
    }

    // Read the edges and construct the adjacency matrix
    for (int i = 0; i < n; i++) {
        std::cin >> u >> k;
        u--; // Convert to 0-based index
        for (int j = 0; j < k; j++) {
            std::cin >> v;
            v--; // Convert to 0-based index
            T[u][v] = 1; // Set the edge in the adjacency matrix
        }
    }

    bfs(0); // Execute BFS starting from node 0

    // Print the distances from the source node to all other nodes
    for (int i = 0; i < n; i++) {
        if (d[i] == 1000000) d[i] = -1; // If unreachable, set distance to -1
        std::cout << i + 1 << " " << d[i] << std::endl; // Print node number and distance
    }

    return 0;
}

// <END-OF-CODE>
