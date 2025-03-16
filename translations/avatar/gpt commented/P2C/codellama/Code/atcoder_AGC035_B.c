#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Read the number of nodes (N) and edges (M) from input
int N, M;
scanf("%d %d", &N, &M);

// Initialize adjacency list for edges, degree count, parity, and visited flag
int **edges = (int **)malloc(N * sizeof(int *));
int *degs = (int *)malloc(N * sizeof(int));
int *parity = (int *)malloc(N * sizeof(int));
bool *flag = (bool *)malloc(N * sizeof(bool));

// Read edges and populate the adjacency list and degree counts
for (int i = 0; i < M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    edges[a - 1] = (int *)realloc(edges[a - 1], (i + 1) * sizeof(int));
    edges[a - 1][i] = b - 1;  // Add edge from a to b
    edges[b - 1] = (int *)realloc(edges[b - 1], (i + 1) * sizeof(int));
    edges[b - 1][i] = a - 1;  // Add edge from b to a
    degs[a - 1] += 1;         // Increment degree of node a
    degs[b - 1] += 1;         // Increment degree of node b
}

// If the number of edges is odd, it's impossible to pair them
if (M % 2 != 0) {
    printf("-1\n");
    exit(0);
}

// Initialize a priority queue with degrees of nodes
int *Q = (int *)malloc(N * sizeof(int));
for (int i = 0; i < N; i++) {
    Q[i] = degs[i];  // Append degree and node index to the queue
}

// Process the nodes in the priority queue
while (Q[0] != -1) {
    int u = Q[0];        // Get the node with the smallest degree
    Q[0] = -1;           // Remove it from the queue

    // If the node has already been processed, skip it
    if (flag[u]) {
        continue;
    }

    flag[u] = true;  // Mark the node as processed

    // Iterate through the neighbors of the current node
    for (int i = 0; i < N; i++) {
        int v = edges[u][i];
        edges[v] = (int *)realloc(edges[v], (i + 1) * sizeof(int));
        edges[v][i] = u;  // Remove the edge from v to u
        // Check the parity to determine the output format
        if (parity[u] != 0 && i == 0) {
            printf("%d %d\n", u + 1, v + 1);  // Print the edge in one format
            parity[u] = 1 - parity[u];        // Toggle parity for u
        } else {
            printf("%d %d\n", v + 1, u + 1);  // Print the edge in the alternate format
            parity[v] = 1 - parity[v];        // Toggle parity for v
        }

        degs[v] -= 1;  // Decrement the degree of neighbor v
        Q[degs[v]] = v;  // Push updated degree back to the queue
    }
}

// 