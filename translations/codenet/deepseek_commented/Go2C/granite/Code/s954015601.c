
#include <stdio.h>
#include <stdlib.h>

// Deepth-first search
void dfs(int N, int **edges, int *colors, int *q, int *qi, int *qj, int *usedColor, int *parentNode) {
    int node = q[qi[0]];
    int color = 1;
    for (int i = 0; i < edges[node][0]; i++) {
        int childNode = edges[node][i+1];
        if (childNode == parentNode[node]) {
            continue;
        }
        if (color == usedColor[node]) {
            color++;
        }
        colors[node*N+childNode] = color;
        q[qi[0]+1] = childNode;
        qi[0]++;
        usedColor[childNode] = color;
        parentNode[childNode] = node;
        color++;
    }
}

int main() {
    // Read the number of nodes from standard input.
    int N = 0;
    scanf("%d", &N);

    // Initialize a slice to store edges and an adjacency list for the graph.
    int **edges = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++) {
        edges[i] = (int *)malloc(sizeof(int) * (N+1));
        edges[i][0] = 0;
    }
    int *colors = (int *)malloc(sizeof(int) * N * N);
    int *q = (int *)malloc(sizeof(int) * (N+1));
    int *qi = (int *)malloc(sizeof(int));
    int *qj = (int *)malloc(sizeof(int));
    int *usedColor = (int *)malloc(sizeof(int) * N);
    int *parentNode = (int *)malloc(sizeof(int) * N);

    for (int i = 0; i < N-1; i++) {
        // Read edge information and populate the adjacency list.
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        edges[a][0]++;
        edges[b][0]++;
        edges[a][edges[a][0]] = b;
        edges[b][edges[b][0]] = a;
    }

    // Initialize a map to store the color of each edge and a queue for DFS traversal.
    qi[0] = 0;
    qj[0] = 0;
    q[0] = 0;
    usedColor[0] = 0;
    parentNode[0] = -1;
    for (int i = 1; i < N; i++) {
        usedColor[i] = 0;
        parentNode[i] = -1;
    }

    // Perform DFS traversal to determine the colors of the edges.
    dfs(N, edges, colors, q, qi, qj, usedColor, parentNode);

    // Determine the maximum degree of any node in the graph.
    int K = 0;
    for (int i = 0; i < N; i++) {
        if (edges[i][0] > K) {
            K = edges[i][0];
        }
    }
    printf("%d\n", K);

    // Output the colors of the edges.
    for (int i = 0; i < N-1; i++) {
        printf("%d\n", colors[i]);
    }

    // Free memory.
    for (int i = 0; i < N; i++) {
        free(edges[i]);
    }
    free(edges);
    free(colors);
    free(q);
    free(qi);
    free(qj);
    free(usedColor);
    free(parentNode);

    return 0;
}

