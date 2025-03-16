#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void dfs(int u, int *d, int **edges, int *edges_count) {
    for (int i = 0; i < edges_count[u]; i++) {
        int nu = edges[u][i];
        if (d[nu] == INT_MAX) {
            d[nu] = d[u] + 1;
            dfs(nu, d, edges, edges_count);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    
    int u, v;
    scanf("%d %d", &u, &v);
    u--; // Convert to 0-based index
    v--; // Convert to 0-based index

    // Step 2: Initialize the adjacency list for the graph
    int **edges = (int **)malloc(N * sizeof(int *));
    int *edges_count = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        edges[i] = (int *)malloc((N - 1) * sizeof(int)); // Maximum possible edges
        edges_count[i] = 0;
    }

    // Step 3: Read the edges of the graph and populate the adjacency list
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; // Convert to 0-based index
        b--; // Convert to 0-based index
        edges[a][edges_count[a]++] = b;
        edges[b][edges_count[b]++] = a;
    }

    // Step 4: Initialize the distance array for the first DFS traversal starting from node u
    int *d = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        d[i] = INT_MAX;
    }
    d[u] = 0;

    // Step 5: Perform DFS from node u to populate the distance array d
    dfs(u, d, edges, edges_count);

    // Step 6: Initialize the distance array for the second DFS traversal starting from node v
    int *e = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        e[i] = INT_MAX;
    }
    e[v] = 0;

    // Step 7: Perform DFS from node v to populate the distance array e
    dfs(v, e, edges, edges_count);

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

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(edges[i]);
    }
    free(edges);
    free(edges_count);
    free(d);
    free(e);

    return 0;
}

// <END-OF-CODE>
