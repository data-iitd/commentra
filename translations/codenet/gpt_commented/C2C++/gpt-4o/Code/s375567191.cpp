#include <iostream>
#include <vector>
#define MAX 101          // Define the maximum number of vertices
#define WHITE 0          // Color constant for unvisited nodes
#define BLACK 2          // Color constant for fully explored nodes
#define GRAY 1           // Color constant for nodes currently being explored

int time, n; // Global variables: time counter and number of vertices
int d[MAX], f[MAX], color[MAX] = {WHITE}; // Arrays for discovery time, finish time, and color of nodes
std::vector<std::vector<int>> g(MAX, std::vector<int>(MAX, 0)); // Adjacency matrix

// Function to perform DFS visit on a node
void visit(int u) {
    color[u] = GRAY; // Mark the node as being explored
    d[u] = ++time;   // Set the discovery time for the node

    // Explore all adjacent nodes
    for(int i = 0; i < n; i++) {
        if(g[u][i] == 0) // If there is no edge to node i, skip
            continue;
        if(color[i] == WHITE) // If the adjacent node is unvisited
            visit(i); // Recursively visit the adjacent node
    }

    color[u] = BLACK; // Mark the node as fully explored
    f[u] = ++time;    // Set the finish time for the node
}

// Function to perform Depth-First Search on the graph
void dfs() {
    time = 0; // Initialize time counter

    // Visit all nodes in the graph
    for(int i = 0; i < n; i++)
        if(color[i] == WHITE) // If the node is unvisited
            visit(i); // Start a DFS visit

    // Print the discovery and finish times for each node
    for(int i = 0; i < n; i++)
        std::cout << i + 1 << " " << d[i] << " " << f[i] << std::endl; // Output: node index, discovery time, finish time
}

int main() {
    int x, y, z;

    // Read the number of vertices
    std::cin >> n;

    // Read the graph edges
    for(int i = 0; i < n; i++) {
        std::cin >> x >> y; // Read the node and the number of edges
        for(int j = 0; j < y; j++) {
            std::cin >> z; // Read each adjacent node
            g[x - 1][z - 1] = 1; // Update the adjacency matrix
        }
    }

    // Perform DFS on the graph
    dfs();
    return 0; // Exit the program
}

// <END-OF-CODE>
