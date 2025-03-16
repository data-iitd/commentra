#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define INF 1000000000

int n, ta, ao;
int g[MAX_N][MAX_N]; // Adjacency list representation
int g_size[MAX_N]; // Size of each adjacency list
int ta_dist[MAX_N];
int ao_dist[MAX_N];

void ta_dfs(int node) {
    for (int i = 0; i < g_size[node]; i++) {
        int v = g[node][i];
        if (ta_dist[v] != -1) continue; // If already visited, skip
        ta_dist[v] = ta_dist[node] + 1; // Update distance
        ta_dfs(v); // Recursively visit neighbors
    }
}

void ao_dfs(int node) {
    for (int i = 0; i < g_size[node]; i++) {
        int v = g[node][i];
        if (ao_dist[v] != -1) continue; // If already visited, skip
        ao_dist[v] = ao_dist[node] + 1; // Update distance
        ao_dfs(v); // Recursively visit neighbors
    }
}

int main() {
    // Read the number of nodes, starting node for Ta, and starting node for Ao
    scanf("%d %d %d", &n, &ta, &ao);
    
    // Adjust indices to be zero-based
    ta--;
    ao--;

    // Initialize the graph
    for (int i = 0; i < n; i++) {
        g_size[i] = 0;
    }

    // Read edges to construct the graph
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; // Adjust to zero-based index
        b--; // Adjust to zero-based index
        g[a][g_size[a]++] = b; // Append the neighbor
        g[b][g_size[b]++] = a; // Append the neighbor
    }

    // Initialize distance arrays to -1 (unvisited)
    for (int i = 0; i < n; i++) {
        ta_dist[i] = -1;
        ao_dist[i] = -1;
    }
    ta_dist[ta] = 0; // Distance from Ta to Ta is 0
    ao_dist[ao] = 0; // Distance from Ao to Ao is 0

    // Start DFS from Ao to compute distances
    ao_dfs(ao);

    // Start DFS from Ta to compute distances
    ta_dfs(ta);

    // Initialize result variable
    int res = 0;

    // Iterate over all nodes to find the maximum distance where Ta's distance is less than or equal to Ao's distance
    for (int i = 0; i < n; i++) {
        if (ta_dist[i] > ao_dist[i]) continue; // Skip if Ta's distance is greater
        if (ao_dist[i] > res) res = ao_dist[i]; // Update result with the maximum distance
    }

    // Print the result, which is the maximum distance minus one
    printf("%d\n", res - 1);

    return 0;
}

// <END-OF-CODE>
