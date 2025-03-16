#include <iostream>
#include <vector>
#include <limits>

#define MAX 100
#define INF std::numeric_limits<int>::max()
#define NIL -1
#define WHITE 0
#define BLACK 2

// Function prototype for Prim's algorithm
int prim();

int n;
int G[MAX][MAX];

int main() {
    // Read the number of vertices in the graph
    std::cin >> n;

    // Read the adjacency matrix representation of the graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> G[i][j];
        }
    }

    // Call Prim's algorithm and print the total weight of the minimum spanning tree
    std::cout << prim() << std::endl;

    return 0;
}

int prim() {
    int u, mincost, sum = 0;
    std::vector<int> d(n, INF), pi(n, NIL), color(n, WHITE);

    // Initialize the distance for the first vertex
    d[0] = 0;

    // Main loop to find the minimum spanning tree
    while (true) {
        mincost = INF;

        // Find the vertex with the minimum cost edge that is not yet included in the MST
        for (int i = 0; i < n; i++) {
            if (color[i] != BLACK && d[i] < mincost) {
                mincost = d[i];
                u = i; // Update the vertex to be included in the MST
            }
        }

        // If no vertex is found, break the loop
        if (mincost == INF) break;

        // Mark the selected vertex as BLACK (included in the MST)
        color[u] = BLACK;

        // Update the distances and parents for the adjacent vertices
        for (int v = 0; v < n; v++) {
            // If the vertex is not yet included in the MST and the edge weight is less than the current known distance
            if (color[v] != BLACK && G[u][v] < d[v] && G[u][v] != -1) {
                pi[v] = u;    // Update the parent of vertex v
                d[v] = G[u][v]; // Update the distance to vertex v
            }
        }
    }

    // Calculate the total weight of the minimum spanning tree
    for (int i = 0; i < n; i++) {
        if (d[i] != INF) sum += d[i]; // Sum up the distances of included vertices
    }

    // Return the total weight of the minimum spanning tree
    return sum;
}

// <END-OF-CODE>
