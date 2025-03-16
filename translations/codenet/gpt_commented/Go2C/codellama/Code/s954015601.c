
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 深さ優先探索

// genid generates a unique identifier for an edge between two nodes a and b
// by ensuring a is less than b and combining them into a single integer.
int genid(int a, int b) {
    if (b < a) {
        a = b;
        b = a;
    }
    return a * 100000 + b;
}

int main() {
    // Read the number of nodes in the graph
    int N = 0;
    scanf("%d", &N);

    // Initialize a slice to hold the edges and an adjacency list for the graph
    int ab[N - 1][2];
    int **edges = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        edges[i] = (int *)malloc(N * sizeof(int));
    }

    // Read edges from input and populate the adjacency list
    for (int i = 0; i < N - 1; i++) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        a--; // Convert to zero-based index
        b--; // Convert to zero-based index
        ab[i][0] = a;
        ab[i][1] = b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }

    // Map to store colors assigned to edges
    int *colors = (int *)malloc(N * (N - 1) * sizeof(int));
    for (int i = 0; i < N * (N - 1); i++) {
        colors[i] = 0;
    }
    // Stack for depth-first search (DFS) with current node, used color, and parent node
    int *q = (int *)malloc(N * sizeof(int));
    q[0] = 0; // Start DFS from node 0 with no used color and no parent

    // Perform DFS to assign colors to edges
    for (int i = 0; i < N; i++) {
        int currentNode = q[i];
        int usedColor = -1;
        int parentNode = -1;
        int color = 1; // Start coloring from color 1

        // Iterate through child nodes of the current node
        for (int j = 0; j < N; j++) {
            if (edges[currentNode][j] == 1 && j != parentNode) {
                if (color == usedColor) {
                    color++; // Skip the color that was used by the parent
                }
                // Assign color to the edge between currentNode and childNode
                colors[genid(currentNode, j)] = color;
                // Push the child node onto the stack for further exploration
                q[i + 1] = j;
                color++; // Move to the next color for the next edge
            }
        }
    }

    // Find the maximum degree of any node in the graph
    int K = -1;
    for (int i = 0; i < N; i++) {
        int t = 0;
        for (int j = 0; j < N; j++) {
            if (edges[i][j] == 1) {
                t++; // Degree of the current node
            }
        }
        if (t > K) {
            K = t; // Update maximum degree if current node's degree is greater
        }
    }
    printf("%d\n", K); // Print the maximum degree

    // Print the colors assigned to each edge
    for (int i = 0; i < N - 1; i++) {
        printf("%d\n", colors[genid(ab[i][0], ab[i][1])]);
    }

    return 0;
}

