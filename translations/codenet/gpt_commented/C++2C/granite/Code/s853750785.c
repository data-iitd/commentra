
#include <stdio.h>

int main() {
    // Read number of nodes (N) and edges (M)
    int N, M;
    scanf("%d %d", &N, &M);

    // Read heights of each node
    int H[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &H[i]);
    }

    // Read edges and build the graph
    int G[N][N]; // Adjacency matrix for the graph
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--; // Convert to 0-based indexing
        G[u][v] = 1;
        G[v][u] = 1;
    }

    int ans = 0; // Variable to count the number of nodes that are taller than all their neighbors

    // Iterate through each node to check if it is taller than all its neighbors
    for (int u = 0; u < N; u++) {
        bool flag = true; // Flag to check if the current node is taller
        for (int v = 0; v < N; v++) {
            if (G[u][v] == 1 && H[u] <= H[v]) flag = false; // If any neighbor is taller or equal, set flag to false
        }
        if (flag) ans++; // If the flag is still true, increment the answer
    }

    // Output the result
    printf("%d\n", ans);

    return 0;
}
