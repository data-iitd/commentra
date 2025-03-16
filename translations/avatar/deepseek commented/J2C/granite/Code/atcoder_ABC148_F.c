

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void dfs(int u, int *d, int **edges, int N) {
    for (int i = 0; i < N; i++) {
        if (d[i] == INT_MAX) {
            d[i] = d[u] + 1;
            dfs(i, d, edges, N);
        }
    }
}

int main() {
    // Step 1: Read the input values for N, u, and v
    int N, u, v;
    scanf("%d %d %d", &N, &u, &v);

    // Step 2: Initialize the adjacency list for the graph
    int **edges = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        edges[i] = (int *)malloc(N * sizeof(int));
    }

    // Step 3: Read the edges of the graph and populate the adjacency list
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        edges[a - 1][b - 1] = 1;
        edges[b - 1][a - 1] = 1;
    }

    // Step 4: Initialize the distance array for the first DFS traversal starting from node u
    int *d = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        d[i] = INT_MAX;
    }
    d[u - 1] = 0;

    // Step 5: Perform DFS from node u to populate the distance array d
    dfs(u - 1, d, edges, N);

    // Step 6: Initialize the distance array for the second DFS traversal starting from node v
    int *e = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        e[i] = INT_MAX;
    }
    e[v - 1] = 0;

    // Step 7: Perform DFS from node v to populate the distance array e
    dfs(v - 1, e, edges, N);

    // Step 8: Find the maximum value of e[i] where d[i] < e[i]
    int q = -1;
    for (int i = 0; i < N; i++) {
        if (d[i] < e[i]) {
            if (e[i] > q) {
                q = e[i];
            }
        }
    }

    // Step 9: Print the result based on the maximum value found
    if (q <= 0) {
        printf("0\n");
    } else {
        printf("%d\n", q - 1);
    }

    // Step 10: Free the allocated memory
    for (int i = 0; i < N; i++) {
        free(edges[i]);
    }
    free(edges);
    free(d);
    free(e);

    return 0;
}
