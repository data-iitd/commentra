#include <stdio.h> // Standard input/output library
#include <stdlib.h> // Standard library for memory allocation
#include <stdbool.h> // Standard library for boolean type
#include <string.h> // Standard library for string manipulation

#define MAX_N 100005 // Maximum number of nodes

int N, M; // Number of nodes and edges
int H[MAX_N]; // Heights of the nodes
int G[MAX_N][MAX_N]; // Adjacency matrix to represent the graph
int degree[MAX_N]; // Array to keep track of the degree of each node

int main() {
    scanf("%d %d", &N, &M); // Read the number of nodes and edges
    for (int i = 0; i < N; i++) {
        scanf("%d", &H[i]); // Read the heights of the nodes
        degree[i] = 0; // Initialize degree of each node
    }
    
    // Initialize the adjacency matrix
    memset(G, 0, sizeof(G));

    for (int i = 0; i < M; i++) { // Iterate through each edge
        int u, v;
        scanf("%d %d", &u, &v); // Read the endpoints of the edge
        u--; v--; // Convert to 0-indexing
        G[u][degree[u]] = v; // Add an edge from node u to node v
        G[v][degree[v]] = u; // Add a reciprocal edge from node v to node u
        degree[u]++; // Increment the degree of node u
        degree[v]++; // Increment the degree of node v
    }

    long long ans = 0; // Initialize answer variable
    for (int u = 0; u < N; u++) { // Iterate through each node
        bool flag = true; // Assume that the node has a higher height than its neighbors
        for (int i = 0; i < degree[u]; i++) {
            int v = G[u][i]; // Get the neighbor node
            if (H[u] <= H[v]) flag = false; // If not, update the flag
        }
        if (flag) ans++; // If the node has a higher height than its neighbors, increment the answer
    }
    
    printf("%lld\n", ans); // Print the answer
    return 0; // Return success
}

// <END-OF-CODE>
