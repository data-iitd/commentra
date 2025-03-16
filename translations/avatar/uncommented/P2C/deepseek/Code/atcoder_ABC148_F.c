#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100000

int n, ta, ao;
int g[MAXN][MAXN];
int ta_dist[MAXN];
int ao_dist[MAXN];

void ta_dfs(int node, int parent) {
    for (int i = 0; i < n; i++) {
        if (g[node][i] == 1 && ta_dist[i] == -1) {
            ta_dist[i] = ta_dist[node] + 1;
            ta_dfs(i, node);
        }
    }
}

void ao_dfs(int node, int parent) {
    for (int i = 0; i < n; i++) {
        if (g[node][i] == 1 && ao_dist[i] == -1) {
            ao_dist[i] = ao_dist[node] + 1;
            ao_dfs(i, node);
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &ta, &ao);
    ta -= 1;
    ao -= 1;
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
        g[a - 1][b - 1] = 1;
        g[b - 1][a - 1] = 1;
    }
    ta_dist[ta] = 0;
    ao_dist[ao] = 0;
    ta_dfs(ta, -1);
    ao_dfs(ao, -1);
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (ta_dist[i] <= ao_dist[i]) {
            res = (ao_dist[i] > res) ? ao_dist[i] : res;
        }
    }
    printf("%d\n", res - 1);
    return 0;
}
