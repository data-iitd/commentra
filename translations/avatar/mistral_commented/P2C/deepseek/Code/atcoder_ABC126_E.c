#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define INF 1e18

// Define a custom input function
char* input() {
    char* line = NULL;
    size_t size = 0;
    if (getline(&line, &size, stdin) == -1) {
        free(line);
        return NULL;
    }
    return line;
}

// Define the main function
void main() {
    // Read input values for N and M
    int N, M;
    scanf("%d %d", &N, &M);
    getchar(); // Consume the newline character

    // Initialize an empty list for edge
    int** edge = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        edge[i] = (int*)malloc(N * sizeof(int));
        memset(edge[i], 0, N * sizeof(int));
    }

    // Read edges and add them to the edge list
    for (int i = 0; i < M; i++) {
        int X, Y, Z;
        scanf("%d %d %d", &X, &Y, &Z);
        getchar(); // Consume the newline character
        X--; Y--; // Convert to 0-based index
        edge[X][Y] = 1;
        edge[Y][X] = 1;
    }

    // Initialize a list of boolean values for used nodes
    bool* used = (bool*)malloc(N * sizeof(bool));
    memset(used, false, N * sizeof(bool));

    // Initialize a variable for answer
    int ans = 0;

    // Iterate through all nodes
    for (int i = 0; i < N; i++) {
        // If the current node is not used
        if (!used[i]) {
            // Increment the answer
            ans++;
            // Initialize a queue for BFS traversal
            int queue[N];
            int front = 0, rear = 0;
            // Add the current node to the queue
            queue[rear++] = i;
            // Traverse through the graph using BFS
            while (front < rear) {
                // Get the next node from the queue
                int node = queue[front++];
                // Mark the current node as used
                used[node] = true;
                // Traverse through the neighbors of the current node
                for (int nextnode = 0; nextnode < N; nextnode++) {
                    // If the neighbor is not used and there is an edge
                    if (edge[node][nextnode] == 1 && !used[nextnode]) {
                        // Add the neighbor to the queue
                        queue[rear++] = nextnode;
                    }
                }
            }
        }
    }

    // Print the answer
    printf("%d\n", ans);

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(edge[i]);
    }
    free(edge);
    free(used);
}
