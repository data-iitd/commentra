

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

typedef struct Node {
    int x, y, id;
} Node;

typedef struct Edge {
    int u, v, val;
} Edge;

int par[100005];

int cmp1(const void *a, const void *b) {
    return ((Node *)a)->x - ((Node *)b)->x;
}

int cmp2(const void *a, const void *b) {
    return ((Node *)a)->y - ((Node *)b)->y;
}

void init() {
    for (int i = 0; i <= n; i ++)
        par[i] = i;
}

int findpar(int x) {
    return par[x] = (par[x] == x? x : findpar(par[x]));
}

void unite(int x, int y) {
    x = findpar(x), y = findpar(y);
    if (x == y) return;
    par[x] = y;
}

int main(int argc, char const *argv[]) {
    
    int n;
    scanf("%d", &n);

    init();

    Node *node = (Node *)malloc(sizeof(Node) * (n + 1));
    for (int i = 1; i <= n; i ++) {
        scanf("%d%d", &node[i].x, &node[i].y);
        node[i].id = i;
    }

    qsort(node + 1, n, sizeof(Node), cmp1);

    Edge *e = (Edge *)malloc(sizeof(Edge) * (2 * n - 1));
    int cnt = 0;
    for (int i = 2; i <= n; i ++) {
        e[cnt++] = (Edge){node[i - 1].id, node[i].id, node[i].x - node[i - 1].x};
    }

    qsort(node + 1, n, sizeof(Node), cmp2);
    for (int i = 2; i <= n; i ++) {
        e[cnt++] = (Edge){node[i - 1].id, node[i].id, node[i].y - node[i - 1].y};
    }

    qsort(e, cnt, sizeof(Edge), [](const void *a, const void *b) {
        return ((Edge *)a)->val - ((Edge *)b)->val;
    });

    long long ans = 0;
    for (int i = 0; i < cnt; i ++) {
        int u = e[i].u, v = e[i].v, val = e[i].val;
        if (findpar(u) == findpar(v)) continue;
        unite(u, v);
        ans += val;
    }

    printf("%lld\n", ans);

    free(node);
    free(e);

    return 0;
}

