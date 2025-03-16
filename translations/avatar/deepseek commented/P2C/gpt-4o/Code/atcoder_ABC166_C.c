#include <stdio.h>
#include <stdlib.h>

int main() {
    // Step 1: Input the number of nodes (n) and the number of edges (m)
    int n, m;
    scanf("%d %d", &n, &m);

    // Step 2: Create a list of positions (p) from 1 to n
    int *p = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
    }

    // Step 3: Input the heights (h) of the nodes
    int *h = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }

    // Step 4: Create an array (hp) mapping positions to heights
    int *hp = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n; i++) {
        hp[p[i] - 1] = h[i]; // Store heights in hp based on positions
    }

    // Step 5: Initialize an adjacency list for the graph
    int **path = (int **)malloc((n + 1) * sizeof(int *));
    int *path_size = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) {
        path[i] = (int *)malloc(n * sizeof(int)); // Allocate maximum size
        path_size[i] = 0; // Initialize size of each adjacency list
    }

    // Step 6: Input the edges of the graph and populate the adjacency list
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        path[a][path_size[a]] = b; // Add b to the adjacency list of a
        path_size[a]++;
        path[b][path_size[b]] = a; // Add a to the adjacency list of b
        path_size[b]++;
    }

    // Step 7: Count the number of nodes that are the highest in their neighborhoods
    int c = 0;
    for (int i = 1; i <= n; i++) {
        int f = 0;
        for (int j = 0; j < path_size[i]; j++) {
            int neighbor = path[i][j];
            if (hp[i - 1] <= hp[neighbor - 1]) {
                f = 1;
                break;
            }
        }
        if (f == 0) {
            c++;
        }
    }

    // Step 8: Output the count of such nodes
    printf("%d\n", c);

    // Free allocated memory
    for (int i = 1; i <= n; i++) {
        free(path[i]);
    }
    free(path);
    free(path_size);
    free(p);
    free(h);
    free(hp);

    return 0;
}

// <END-OF-CODE>
