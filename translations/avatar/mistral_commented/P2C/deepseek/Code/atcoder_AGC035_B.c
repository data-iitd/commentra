#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100000

// Structure to represent a vertex in the graph
typedef struct {
    int degree;
    int index;
} Vertex;

// Function to compare two vertices based on their degrees
int compare(const void *a, const void *b) {
    Vertex *v1 = (Vertex *)a;
    Vertex *v2 = (Vertex *)b;
    return v1->degree - v2->degree;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // Initialize empty sets for each vertex representing its adjacent vertices
    int edges[MAX_N][MAX_N] = {0};
    int degs[MAX_N] = {0};
    int parity[MAX_N] = {0};
    bool flag[MAX_N] = {false};

    // Read edges from input and add them to their respective sets and update their degrees
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        // Add edge between vertices a and b in both their sets
        edges[a-1][degs[a-1]++] = b-1;
        edges[b-1][degs[b-1]++] = a-1;
    }

    // Check if number of edges is even, if not print -1 and exit
    if (M % 2 != 0) {
        printf("-1\n");
        return 0;
    }

    // Initialize empty list Q to store vertices based on their degrees
    Vertex Q[MAX_N];
    for (int i = 0; i < N; i++) {
        Q[i].degree = degs[i];
        Q[i].index = i;
    }

    // Sort Q based on degrees
    qsort(Q, N, sizeof(Vertex), compare);

    // Iterate through Q until it is empty
    for (int i = 0; i < N; i++) {
        int u = Q[i].index;
        // Skip if vertex is already visited
        if (flag[u]) {
            continue;
        }
        // Mark vertex as visited
        flag[u] = true;
        // Iterate through all adjacent vertices and print their edges and update their parity
        for (int j = 0; j < degs[u]; j++) {
            int v = edges[u][j];
            // Skip if vertex is already visited
            if (flag[v]) {
                continue;
            }
            // Print edge and update parity of both vertices
            if (parity[u] != 0 && j == 0) {
                printf("%d %d\n", u+1, v+1);
                parity[u] = 1 - parity[u];
            } else {
                printf("%d %d\n", v+1, u+1);
                parity[v] = 1 - parity[v];
            }
            // Decrease degree of adjacent vertex and add it to Q
            degs[v]--;
            break; // Assuming each vertex has at least one edge
        }
    }

    return 0;
}
