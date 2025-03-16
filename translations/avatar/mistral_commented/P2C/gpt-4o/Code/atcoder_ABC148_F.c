#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100000
#define INF 1e9

int n, ta, ao;
int g[MAX_NODES][MAX_NODES];
int g_size[MAX_NODES];
int ta_dist[MAX_NODES];
int ao_dist[MAX_NODES];

void ta_dfs(int node) {
    for (int i = 0; i < g_size[node]; i++) {
        int v = g[node][i];
        if (ta_dist[v] != -1) continue;
        ta_dist[v] = ta_dist[node] + 1;
        ta_dfs(v);
    }
}

void ao_dfs(int node) {
    for (int i = 0; i < g_size[node]; i++) {
        int v = g[node][i];
        if (ao_dist[v] != -1) continue;
        ao_dist[v] = ao_dist[node] + 1;
        ao_dfs(v);
    }
}

int main() {
    // Input the number of nodes, starting and ending nodes
    scanf("%d %d %d", &n, &ta, &ao);
    ta--; ao--; // Convert to 0-based indexing

    // Initialize adjacency list
    for (int i = 0; i < n; i++) {
        g_size[i] = 0;
    }

    // Read edges and add them to the graph
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--; // Convert to 0-based indexing
        g[a][g_size[a]++] = b;
        g[b][g_size[b]++] = a;
    }

    // Initialize distance arrays for both nodes
    for (int i = 0; i < n; i++) {
        ta_dist[i] = -1;
        ao_dist[i] = -1;
    }

    // Initialize distances for starting and ending nodes
    ta_dist[ta] = 0;
    ao_dist[ao] = 0;

    // Perform Depth First Search from starting and ending nodes
    ao_dfs(ao);
    ta_dfs(ta);

    // Calculate the answer
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (ta_dist[i] == -1 || ao_dist[i] == -1 || ta_dist[i] > ao_dist[i]) continue;
        res = (ao_dist[i] > res) ? ao_dist[i] : res;
    }

    // Print the answer
    printf("%d\n", res - 1);

    return 0;
}

// <END-OF-CODE>
