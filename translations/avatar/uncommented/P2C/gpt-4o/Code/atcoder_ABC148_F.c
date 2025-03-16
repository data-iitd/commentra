#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000
#define INF 1e9

int n, ta, ao;
int g[MAX_N][MAX_N];
int g_size[MAX_N];
int ta_dist[MAX_N];
int ao_dist[MAX_N];

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
    scanf("%d %d %d", &n, &ta, &ao);
    ta--; ao--; // Convert to 0-based index

    // Initialize graph
    for (int i = 0; i < n; i++) {
        g_size[i] = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--; // Convert to 0-based index
        g[a][g_size[a]++] = b;
        g[b][g_size[b]++] = a;
    }

    // Initialize distances
    memset(ta_dist, -1, sizeof(ta_dist));
    memset(ao_dist, -1, sizeof(ao_dist));
    ta_dist[ta] = 0;
    ao_dist[ao] = 0;

    // Perform DFS
    ao_dfs(ao);
    ta_dfs(ta);

    // Calculate result
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (ta_dist[i] > ao_dist[i]) continue;
        res = res > ao_dist[i] ? res : ao_dist[i];
    }

    printf("%d\n", res - 1);
    return 0;
}

// <END-OF-CODE>
