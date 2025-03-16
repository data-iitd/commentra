#include <iostream>
#include <vector>
#include <limits>

#define MAX 100
#define INF 999999
#define NIL -1
#define WHITE 0
#define BLACK 2

int prim(); // Function to implement Prim's Algorithm

int n; // Number of vertices
int G[MAX][MAX]; // Adjacency matrix

int main() {
    std::cin >> n; // Read the number of vertices from the user
    for (int i = 0; i < n; i++) { // Initialize the 2D array G with input values
        for (int j = 0; j < n; j++) {
            std::cin >> G[i][j];
        }
    }

    std::cout << prim() << std::endl; // Call the prim function and print the result

    return 0;
}

int prim() { // Function to implement Prim's Algorithm
    int u, mincost, sum = 0;
    std::vector<int> d(n, INF), pi(n, NIL), color(n, WHITE); // Declare and initialize vectors

    d[0] = 0; // Set the initial distance of the first vertex to 0

    while (true) { // The main loop of Prim's Algorithm
        mincost = INF; // Initialize mincost to the maximum possible value

        for (int i = 0; i < n; i++) { // Find the unvisited vertex with the minimum distance
            if (color[i] != BLACK && d[i] < mincost) {
                mincost = d[i];
                u = i;
            }
        }

        if (mincost == INF) break; // If all vertices have been visited, break the loop

        color[u] = BLACK; // Mark the current vertex as visited

        for (int v = 0; v < n; v++) { // Update the distances of adjacent vertices
            if (color[v] != BLACK && G[u][v] < d[v] && G[u][v] != -1) {
                pi[v] = u;
                d[v] = G[u][v];
            }
        }
    }

    for (int i = 0; i < n; i++) { // Calculate and print the total weight of the MST
        if (d[i] != INF) sum += d[i];
    }

    return sum;
}

// <END-OF-CODE>
