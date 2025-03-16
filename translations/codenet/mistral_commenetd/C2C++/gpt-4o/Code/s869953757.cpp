#include <iostream>
#include <vector>
#include <queue>

#define M 100
#define whi 0
#define gra 1
#define bla 2

int n;
int T[M][M];
int color[M], d[M;

// Breadth First Search Algorithm
void bfs(int s) {
    // Initialize all vertices with white color and infinite distance
    for (int i = 0; i < n; i++) {
        color[i] = whi;
        d[i] = 1000000;
    }

    // Initialize source vertex with gray color and zero distance
    color[s] = gra;
    d[s] = 0;
    std::queue<int> Q; // Queue for BFS algorithm
    Q.push(s); // Enqueue source vertex

    // Traverse the queue until it is empty
    while (!Q.empty()) {
        int u = Q.front(); // Dequeue a vertex
        Q.pop();
        for (int v = 0; v < n; v++) { // Iterate through all adjacent vertices
            if (T[u][v] == 1 && color[v] == whi) { // If the adjacent vertex is unvisited
                color[v] = gra; // Mark it as visited
                d[v] = d[u] + 1; // Update its distance
                Q.push(v); // Enqueue the adjacent vertex
            }
        }
        color[u] = bla; // Mark the current vertex as black
    }
}

// Main function
int main() {
    int u, k, v; // u is a vertex, k is the number of neighbors, and v is a neighbor

    // Read the number of vertices
    std::cin >> n;

    // Initialize the adjacency matrix with zeros
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            T[i][j] = 0;
        }
    }

    // Read the edges and add them to the adjacency matrix
    for (int i = 0; i < n; i++) {
        std::cin >> u >> k;
        u--; // Decrease the index of the source vertex by 1
        for (int j = 0; j < k; j++) {
            std::cin >> v;
            v--; // Decrease the index of the neighbor vertex by 1
            T[u][v] = 1; // Add an edge between the vertices
        }
    }

    // Perform BFS algorithm starting from the source vertex 0
    bfs(0);

    // Print the results
    for (int i = 0; i < n; i++) {
        if (d[i] == 1000000) d[i] = -1; // Set the distance to -1 if it is unreachable
        std::cout << i + 1 << " " << d[i] << std::endl; // Print the vertex index and its distance from the source
    }

    return 0;
}

// <END-OF-CODE>
