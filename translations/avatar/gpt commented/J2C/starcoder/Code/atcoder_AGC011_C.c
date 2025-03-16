#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <ctype.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <ctype.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    // Adjacency list representation of the graph
    int n, m;
    scanf("%d %d", &n, &m);
    int graph[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            graph[i][j] = 0;
        }
    }

    // Read edges and populate the graph
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u - 1][v - 1] = 1;
        graph[v - 1][u - 1] = 1;
    }

    // Initialize visited and color arrays
    bool visited[n];
    int color[n];
    for (int i = 0; i < n; ++i) {
        visited[i] = false;
        color[i] = -1;
    }

    // Initialize counters
    int one = 0;
    int bipartite = 0;
    int count = 0;

    // Iterate through all nodes to find connected components
    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue; // Skip already visited nodes
        count++; // Increment component count
        bool mujun = false; // Reset bipartite flag
        int kind = dfs(i, 0, graph, visited, color, mujun); // Perform DFS starting from node i

        // Update counters based on the results of DFS
        if (kind == 1) one++;
        else if (!mujun) bipartite++;
    }

    // Calculate the total based on the counts of components
    int total = one * (2 * n - one);
    total += (count - one) * (count - one);
    total += bipartite * bipartite;

    // Output the final result
    printf("%d\n", total);
}

