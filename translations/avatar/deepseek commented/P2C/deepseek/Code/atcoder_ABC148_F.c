#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100000

int n, ta, ao;
int g[MAXN][MAXN];
int ta_dist[MAXN], ao_dist[MAXN];
int visited[MAXN];

void dfs(int node, int dist[], int start) {
    visited[node] = 1;
    dist[node] = dist[start] + 1;
    for (int i = 0; i < n; i++) {
        if (g[node][i] && !visited[i]) {
            dfs(i, dist, start);
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &ta, &ao);
    ta--;
    ao--;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = 0;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        g[a][b] = 1;
        g[b][a] = 1;
    }

    memset(ta_dist, -1, sizeof(ta_dist));
    memset(ao_dist, -1, sizeof(ao_dist));
    ta_dist[ta] = 0;
    ao_dist[ao] = 0;

    dfs(ta, ta_dist, ta);
    dfs(ao, ao_dist, ao);

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (ta_dist[i] <= ao_dist[i]) {
            res = (res > ao_dist[i]) ? res : ao_dist[i];
        }
    }

    printf("%d\n", res - 1);
    return 0;
}
