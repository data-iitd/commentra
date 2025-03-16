
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

int main() {
    int N;
    scanf("%d", &N);
    int u, v;
    scanf("%d %d", &u, &v);
    u--;
    v--;
    int edges[MAX_N][2];
    for (int i = 0; i < N; i++) {
        edges[i][0] = -1;
        edges[i][1] = -1;
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        if (edges[a][0] == -1) {
            edges[a][0] = b;
        } else {
            int tmp = edges[a][0];
            edges[a][0] = b;
            edges[b][0] = tmp;
        }
        if (edges[a][1] == -1) {
            edges[a][1] = b;
        } else {
            int tmp = edges[a][1];
            edges[a][1] = b;
            edges[b][1] = tmp;
        }
    }
    int d[MAX_N];
    for (int i = 0; i < N; i++) {
        d[i] = 1000000000;
    }
    int e[MAX_N];
    for (int i = 0; i < N; i++) {
        e[i] = 1000000000;
    }
    dfs(u, d, edges);
    dfs(v, e, edges);
    int q = -1;
    for (int i = 0; i < N; i++) {
        if (d[i] < e[i]) {
            if (e[i] > q) {
                q = e[i];
            }
        }
    }
    if (q <= 0) {
        printf("0\n");
    } else {
        printf("%d\n", q - 1);
    }
    return 0;
}

void dfs(int u, int d[MAX_N], int edges[MAX_N][2]) {
    if (edges[u][0]!= -1) {
        if (d[edges[u][0]] == 1000000000) {
            d[edges[u][0]] = d[u] + 1;
            dfs(edges[u][0], d, edges);
        }
        if (edges[u][1]!= -1) {
            if (d[edges[u][1]] == 1000000000) {
                d[edges[u][1]] = d[u] + 1;
                dfs(edges[u][1], d, edges);
            }
        }
    }
}

