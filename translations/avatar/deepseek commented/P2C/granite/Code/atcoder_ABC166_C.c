
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

    // Step 4: Create a dictionary (hp) mapping positions to heights
    int **hp = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        hp[i] = (int *)malloc(sizeof(int));
        *hp[i] = h[i];
    }

    // Step 5: Initialize a dictionary (path) to store the adjacency list of the graph
    int ***path = (int ***)malloc(n * sizeof(int **));
    for (int i = 0; i < n; i++) {
        path[i] = (int **)malloc(n * sizeof(int *));
        for (int j = 0; j < n; j++) {
            path[i][j] = (int *)malloc(sizeof(int));
            *path[i][j] = 0;
        }
    }

    // Step 6: Input the edges of the graph and populate the adjacency list
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        *path[a - 1][b - 1] = 1;
        *path[b - 1][a - 1] = 1;
    }

    // Step 7: Count the number of nodes that are the highest in their neighborhoods
    int c = 0;
    for (int i = 0; i < n; i++) {
        int f = 0;
        for (int j = 0; j < n; j++) {
            if (i!= j && *path[i][j] == 1 && *hp[i] <= *hp[j]) {
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

    // Free memory
    for (int i = 0; i < n; i++) {
        free(hp[i]);
        for (int j = 0; j < n; j++) {
            free(path[i][j]);
        }
        free(path[i]);
    }
    free(hp);
    free(path);
    free(p);
    free(h);

    return 0;
}
