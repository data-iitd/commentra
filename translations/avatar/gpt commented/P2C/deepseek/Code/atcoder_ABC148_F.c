#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000
#define INF 1e9

int n, ta, ao;
int g[MAX_N][MAX_N];
int ta_dist[MAX_N];
int ao_dist[MAX_N];

void dfs(int node, int dist[], int visited[]) {
    visited[node] = 1;
    dist[node] = dist[node] == -1 ? 0 : dist[node] + 1;
    for (int i = 0; i < n; i++) {
        if (g[node][i] && !visited[i]) {
            dfs(i, dist, visited);
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &ta, &ao);
    ta--; ao--;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = 0;
        }
        ta_dist[i] = -1;
        ao_dist[i] = -1;
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        g[a][b] = 1;
        g[b][a] = 1;
    }

    int visited[MAX_N];
    memset(visited, 0, sizeof(visited));
    ao_dist[ao] = 0;
    dfs(ao, ao_dist, visited);

    memset(visited, 0, sizeof(visited));
    ta_dist[ta] = 0;
    dfs(ta, ta_dist, visited);

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (ta_dist[i] <= ao_dist[i]) {
            res = res > ao_dist[i] ? res : ao_dist[i];
        }
    }

    printf("%d\n", res - 1);
    return 0;
}
