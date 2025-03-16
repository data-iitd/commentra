#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100000

// Function prototypes
void dfs(int u, int *d, int **edges, int N);

int main() {
    int N;
    scanf("%d", &N);
    
    int u, v;
    scanf("%d %d", &u, &v);
    u--; // Convert to 0-based index
    v--; // Convert to 0-based index

    // Initialize the adjacency lists for the graph
    int **edges = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        edges[i] = (int *)malloc(N * sizeof(int));
    }
    int *edge_count = (int *)calloc(N, sizeof(int)); // To keep track of the number of edges for each node

    // Read the edges of the graph and add them to the adjacency lists
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; // Convert to 0-based index
        b--; // Convert to 0-based index
        
        edges[a][edge_count[a]++] = b;
        edges[b][edge_count[b]++] = a;
    }

    // Initialize the distance arrays d and e for depth-first search
    int *d = (int *)malloc(N * sizeof(int));
    int *e = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        d[i] = INT_MAX;
        e[i] = INT_MAX;
    }

    // Perform depth-first search from nodes u and v
    d[u] = 0;
    dfs(u, d, edges, N);
    
    e[v] = 0;
    dfs(v, e, edges, N);

    // Find the maximum difference between the distances of any node from u and v
    int q = -1;
    for (int i = 0; i < N; i++) {
        if (d[i] < e[i]) {
            if (e[i] > q) {
                q = e[i];
            }
        }
    }

    // Print the result: the maximum difference between the distances of any node from u and v
    if (q <= 0) {
        printf("0\n");
    } else {
        printf("%d\n", q - 1);
    }

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(edges[i]);
    }
    free(edges);
    free(edge_count);
    free(d);
    free(e);

    return 0;
}

// Depth-first search recursive helper function
void dfs(int u, int *d, int **edges, int N) {
    for (int i = 0; i < N; i++) {
        if (edges[u][i] != 0) { // Check if there is an edge
            int nu = edges[u][i];
            if (d[nu] == INT_MAX) {
                // Mark the current node as visited and update the distance of its neighbors
                d[nu] = d[u] + 1;
                dfs(nu, d, edges, N);
            }
        }
    }
}
