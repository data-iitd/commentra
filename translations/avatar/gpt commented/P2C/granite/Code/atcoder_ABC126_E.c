
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Define a constant for infinity
#define INF INT_MAX

// Function to read input from standard input
char input[1024];
void input() {
    fgets(input, sizeof(input), stdin);
}

int main() {
    // Read the number of nodes (N) and edges (M)
    int N, M;
    sscanf(input, "%d %d", &N, &M);
    
    // Initialize an adjacency list to represent the graph
    int **edge = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++) {
        edge[i] = (int *)malloc(sizeof(int) * N);
        for (int j = 0; j < N; j++) {
            edge[i][j] = 0;
        }
    }
    
    // Read each edge and populate the adjacency list
    for (int i = 0; i < M; i++) {
        int X, Y, Z;
        sscanf(input, "%d %d %d", &X, &Y, &Z);
        edge[X - 1][Y - 1] = 1;
        edge[Y - 1][X - 1] = 1;
    }
    
    // Array to track visited nodes
    bool *used = (bool *)malloc(sizeof(bool) * N);
    for (int i = 0; i < N; i++) {
        used[i] = false;
    }
    
    // Variable to count the number of connected components
    int ans = 0;
    
    // Iterate through each node to find connected components
    for (int i = 0; i < N; i++) {
        if (!used[i]) {  // If the node has not been visited
            ans++;  // Increment the count of connected components
            int *queue = (int *)malloc(sizeof(int) * N);
            int front = 0, rear = 0;
            queue[rear++] = i;  // Start BFS from the current node
            
            // Perform BFS to mark all reachable nodes from the current node
            while (front < rear) {
                int node = queue[front++];  // Dequeue a node
                used[node] = true;  // Mark the node as visited
                
                // Explore all adjacent nodes
                for (int nextnode = 0; nextnode < N; nextnode++) {
                    if (edge[node][nextnode] == 1 &&!used[nextnode]) {  // If the adjacent node has not been visited
                        queue[rear++] = nextnode;  // Enqueue the adjacent node
                    }
                }
            }
            free(queue);
        }
    }
    
    // Output the number of connected components found
    printf("%d\n", ans);
    
    // Free memory allocated for the adjacency list and visited array
    for (int i = 0; i < N; i++) {
        free(edge[i]);
    }
    free(edge);
    free(used);
    
    return 0;
}

