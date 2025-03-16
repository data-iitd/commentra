#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100000

// Step 2: Define global variables
// G is a vector of vectors representing the graph.
<<<<<<< HEAD
int G[MAX_NODES][MAX_NODES]; // Adjacency list representation
int G_size[MAX_NODES]; // To keep track of the number of edges for each node
// used is an array to keep track of visited nodes.
=======
int G[MAX_NODES][MAX_NODES];
int G_size[MAX_NODES]; // To keep track of the number of neighbors for each node
// used is a boolean array to keep track of visited nodes.
>>>>>>> 98c87cb78a (data updated)
int used[MAX_NODES];
// grundy is an array to store the Grundy number of each node.
int grundy[MAX_NODES];

// Step 3: Define the dfs function
// The function dfs is used to perform a depth-first search on the graph.
void dfs(int v) {
    // It marks the current node as visited.
    used[v] = 1;
    // It initializes the Grundy number of the current node to 0.
    grundy[v] = 0;
    // It iterates through all the neighbors of the current node.
    for (int i = 0; i < G_size[v]; i++) {
        int neighbor = G[v][i];
        // If a neighbor has not been visited, it recursively calls dfs on that neighbor.
        if (!used[neighbor]) {
            dfs(neighbor);
            // It updates the Grundy number of the current node by performing the XOR operation with (grundy[neighbor] + 1).
            grundy[v] ^= (grundy[neighbor] + 1);
        }
    }
}

// Step 4: Main function
int main() {
    // It reads the number of nodes N.
    int N;
    scanf("%d", &N);
    // It reads the edges of the graph and constructs the adjacency list.
    for (int i = 0; i < N - 1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--; y--; // Convert to 0-based index
        G[x][G_size[x]++] = y;
        G[y][G_size[y]++] = x;
    }
    // It calls the dfs function starting from node 0.
    dfs(0);
    // It checks the Grundy number of the root node (node 0).
    if (grundy[0] != 0) {
        // It prints "Alice" if the Grundy number is not 0, otherwise it prints "Bob".
        printf("Alice\n");
    } else {
        printf("Bob\n");
    }
    
    return 0;
}

// <END-OF-CODE>
