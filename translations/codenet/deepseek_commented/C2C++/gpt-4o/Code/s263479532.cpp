#include <iostream>
#include <vector>
#include <limits>

#define MAX 100
#define INF std::numeric_limits<int>::max()
#define NIL -1
#define WHITE 0
#define BLACK 2

// Include the standard input-output library for input and output operations.
// Define constants for maximum size of the graph, infinity, nil, white, and black respectively.

int prim(int n, int G[MAX][MAX]);

// Declare the function prim which implements Prim's algorithm for finding the Minimum Spanning Tree.

int main() {
    int n;
    int G[MAX][MAX];

    // Read the number of vertices from the input.
    std::cin >> n;

    // Read the adjacency matrix representing the graph from the input.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> G[i][j];
        }
    }

    // Call the prim function and print the result.
    std::cout << prim(n, G) << std::endl;

    return 0;
}

// Main function to execute the program.

int prim(int n, int G[MAX][MAX]) {
    int u, i, v, mincost, d[MAX], pi[MAX], color[MAX], sum = 0;

    // Initialize all distances to infinity, predecessors to nil, and colors to white.
    for (u = 0; u < n; u++) {
        d[u] = INF;
        pi[u] = NIL;
        color[u] = WHITE;
    }

    // Set the distance of the first vertex to 0.
    d[0] = 0;

    while (true) {
        mincost = INF;

        // Find the vertex with the smallest distance that is not yet black.
        for (i = 0; i < n; i++) {
            if (color[i] != BLACK && d[i] < mincost) {
                mincost = d[i];
                u = i;
            }
        }

        // If no more vertices can be reached, break the loop.
        if (mincost == INF) break;

        // Mark the current vertex as black.
        color[u] = BLACK;

        // Update the distances and predecessors for the neighboring vertices that are not black and have a valid edge weight.
        for (v = 0; v < n; v++) {
            if (color[v] != BLACK && G[u][v] < d[v] && G[u][v] != -1) {
                pi[v] = u;
                d[v] = G[u][v];
            }
        }
    }

    // Calculate the total cost of the Minimum Spanning Tree by summing up the distances of all vertices.
    for (i = 0; i < n; i++) {
        if (d[i] != INF) sum += d[i];
    }

    return sum;
}

// <END-OF-CODE>
