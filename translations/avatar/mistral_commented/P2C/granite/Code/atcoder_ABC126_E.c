
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Define constant value for INF
#define INF INT_MAX

// Define a custom input function
int input() {
    int x;
    scanf("%d", &x);
    return x;
}

// Define the main function
int main() {
    // Read input values for N and M
    int N = input(), M = input();

    // Initialize an empty list for edge
    int **edge = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++) {
        edge[i] = (int *)malloc(sizeof(int) * N);
        for (int j = 0; j < N; j++) {
            edge[i][j] = 0;
        }
    }

    // Read edges and add them to the edge list
    for (int i = 0; i < M; i++) {
        int X = input() - 1, Y = input() - 1, Z = input();
        edge[X][Y] = edge[Y][X] = 1;
    }

    // Initialize a list of boolean values for used nodes
    bool *used = (bool *)malloc(sizeof(bool) * N);
    for (int i = 0; i < N; i++) {
        used[i] = false;
    }

    // Initialize a variable for answer
    int ans = 0;

    // Iterate through all nodes
    for (int i = 0; i < N; i++) {
        // If the current node is not used
        if (!used[i]) {
            // Increment the answer
            ans++;
            // Initialize a stack for DFS traversal
            int stack[N];
            int top = 0;
            // Add the current node to the stack
            stack[top++] = i;
            // Traverse through the graph using DFS
            while (top > 0) {
                // Get the next node from the stack
                int node = stack[--top];
                // Mark the current node as used
                used[node] = true;
                // Traverse through the neighbors of the current node
                for (int nextnode = 0; nextnode < N; nextnode++) {
                    if (edge[node][nextnode] &&!used[nextnode]) {
                        // Add the neighbor to the stack
                        stack[top++] = nextnode;
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

    return 0;
}

// Translate the above C code to Java and end with comment "