#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <stdint.h>

// Define constant value for INF
#define INF 1000000000

// Define a custom input function
char* input() {
    char* line = NULL;
    size_t size = 0;
    getline(&line, &size, stdin);
    return line;
}

// Define the main function
int main() {
    // Read input values for N and M
    int N, M;
    sscanf(input(), "%d %d", &N, &M);

    // Initialize an empty list for edge
    int** edge = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        edge[i] = (int*)malloc(N * sizeof(int));
        memset(edge[i], -1, N * sizeof(int));
    }

    // Read edges and add them to the edge list
    for (int i = 0; i < M; i++) {
        int X, Y, Z;
        sscanf(input(), "%d %d %d", &X, &Y, &Z);
        edge[X - 1][Y - 1] = Z - 1;
        edge[Y - 1][X - 1] = Z - 1;
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
            // Initialize a queue for DFS traversal
            int* queue = (int*)malloc(N * sizeof(int));
            int head = 0, tail = 0;
            // Add the current node to the queue
            queue[tail++] = i;
            // Traverse through the graph using DFS
            while (head < tail) {
                // Get the next node from the queue
                int node = queue[head++];
                // Mark the current node as used
                used[node] = true;
                // Traverse through the neighbors of the current node
                for (int nextnode = 0; nextnode < N; nextnode++) {
                    // If the neighbor is not used
                    if (!used[nextnode]) {
                        // Add the neighbor to the queue
                        queue[tail++] = nextnode;
                    }
                }
            }
            // Free the queue
            free(queue);
        }
    }

    // Print the answer
    printf("%d\n", ans);

    // Free the edge list
    for (int i = 0; i < N; i++) {
        free(edge[i]);
    }
    free(edge);

    // Free the used list
    free(used);

    return 0;
}

