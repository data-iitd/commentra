
###
# Code
###

# Include necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Define maximum number of nodes
#define MAX_NODES 100000

// Function to perform Breadth First Search (BFS)
int bfs(int v, int N, int G[MAX_NODES][2], int E[MAX_NODES][2], int color[MAX_NODES]) {
    // Initialize visited array and queue
    bool visited[N];
    int queue[N];
    int front = 0, rear = 0;

    // Initialize variables for coloring nodes
    int K = -1;
    int node2color[N];

    // Add starting node to the queue and mark it as visited
    queue[rear++] = v;
    visited[v] = true;

    // BFS algorithm
    while (front < rear) {
        // Dequeue the next node from the queue
        int q = queue[front++];

        // Initialize color for the current node
        int color_count = 0;

        // Traverse through all neighbors of the current node
        for (int i = 0; i < G[q][0]; i++) {
            int nex = G[q][i+1];

            // Skip if the neighbor is already visited
            if (visited[nex]) {
                continue;
            }

            // Mark the neighbor as visited and assign it a color
            visited[nex] = true;
            color_count++;

            // If the color of the current node is same as its neighbor, assign a new color to the neighbor
            if (color_count == color[q]) {
                color_count++;
            }

            // Update node2color and E array with the new color
            node2color[nex] = color_count;
            E[nex][0] = q;
            E[nex][1] = color_count;

            // Add the neighbor to the queue
            queue[rear++] = nex;
        }

        // Update the maximum color found so far
        K = max(K, color_count);
    }

    // Return the maximum color
    return K;
}

// Main function to read input and call bfs function
int main() {
    // Read number of nodes from the input
    int N;
    scanf("%d", &N);

    // Initialize graph as a 2D array and empty array for edges
    int G[N][MAX_NODES];
    int E[N][2];
    int color[N];

    // Read edges from the input and add them to the graph
    for (int i = 0; i < N-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a-1][G[a-1][0]] = b-1;
        G[b-1][G[b-1][0]] = a-1;
        G[a-1][0]++;
        G[b-1][0]++;
        E[i][0] = a-1;
        E[i][1] = 0;
    }

    // Call bfs function and print the result
    int K = bfs(0, N, G, E, color);
    printf("%d\n", K);

    // Print colors of all edges
    for (int i = 0; i < N-1; i++) {
        printf("%d\n", E[i][1]);
    }

    return 0;
}

Translate the above C code to Java and end with comment "