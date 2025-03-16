#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Step 1: Input Reading and Initialization
// Read the number of nodes N and the number of edges M
int N, M;
scanf("%d %d", &N, &M);

// Initialize adjacency lists for each node
int** edges = (int**)malloc(N * sizeof(int*));
for (int i = 0; i < N; i++) {
    edges[i] = (int*)malloc(N * sizeof(int));
    for (int j = 0; j < N; j++) {
        edges[i][j] = 0;
    }
}

// Initialize degrees for each node
int* degs = (int*)malloc(N * sizeof(int));
for (int i = 0; i < N; i++) {
    degs[i] = 0;
}

// Initialize parity for each node
int* parity = (int*)malloc(N * sizeof(int));
for (int i = 0; i < N; i++) {
    parity[i] = 0;
}

// Initialize flag to mark visited nodes
bool* flag = (bool*)malloc(N * sizeof(bool));
for (int i = 0; i < N; i++) {
    flag[i] = false;
}

// Step 2: Edge and Degree Calculation
// Read each edge and update adjacency lists and degree lists
for (int i = 0; i < M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    edges[a - 1][b - 1] = 1;
    edges[b - 1][a - 1] = 1;
    degs[a - 1]++;
    degs[b - 1]++;
}

// If the number of edges M is odd, print -1 and exit
if (M % 2 != 0) {
    printf("%d\n", -1);
    return 0;
}

// Step 3: Heap Initialization
// Initialize a heap Q with nodes based on their degrees
int* Q = (int*)malloc(N * sizeof(int));
for (int i = 0; i < N; i++) {
    Q[i] = i;
}

// Step 4: Main Loop
// Process nodes from the heap
while (Q[0] != -1) {
    int u = Q[0];
    Q[0] = -1;
    
    // If the node has already been processed, skip to the next iteration
    if (flag[u]) {
        continue;
    }
    
    // Mark the node as processed
    flag[u] = true;
    
    // For each neighbor of the node, update the adjacency list and degree list
    for (int v = 0; v < N; v++) {
        if (edges[u][v] == 1) {
            edges[v][u] = 0;
            
            // Print the edge in the required format, alternating the direction based on the parity
            if (parity[u] != 0) {
                printf("%d %d\n", u + 1, v + 1);
                parity[u] = 1 - parity[u];
            } else {
                printf("%d %d\n", v + 1, u + 1);
                parity[v] = 1 - parity[v];
            }
            
            // Update the degree and push the updated node back into the heap
            degs[v]--;
            for (int i = 0; i < N; i++) {
                if (Q[i] == v) {
                    Q[i] = -1;
                    break;
                }
            }
            for (int i = 0; i < N; i++) {
                if (Q[i] == -1) {
                    Q[i] = v;
                    break;
                }
            }
        }
    }
}

// Step 5: Output
// The code prints the edges in the required format, alternating the direction based on the parity

