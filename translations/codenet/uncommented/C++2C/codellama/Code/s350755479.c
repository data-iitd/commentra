#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define maxn 100005

typedef struct {
    int x, y, id;
}Node;

typedef struct {
    int u, v, val;
}Edge;

int par[maxn];
int n;

bool cmp1(const Node *a, const Node *b) {
    return a->x < b->x;
}

bool cmp2(const Node *a, const Node *b) {
    return a->y < b->y;
}

void init() {
    for (int i = 0; i <= n; i ++)
        par[i] = i;
}

int findpar(int x) {
    return par[x] = (par[x] == x ? x : findpar(par[x]));
}

void unite(int x, int y) {
    x = findpar(x), y = findpar(y);
    if (x == y) return;
    par[x] = y;
}

int main(int argc, char const *argv[]) {
    
    scanf("%d", &n);

    init();

    Node *node = (Node *)malloc(sizeof(Node) * (n + 1));
    for (int i = 1; i <= n; i ++) {
        scanf("%d%d", &node[i].x, &node[i].y);
        node[i].id = i;
    }

    Edge *e = (Edge *)malloc(sizeof(Edge) * (n * 2));
    int cnt = 0;
    for (int i = 2; i <= n; i ++)
        e[cnt ++] = (Edge){node[i - 1].id, node[i].id, node[i].x - node[i - 1].x};
    
    qsort(node + 1, n, sizeof(Node), (int (*)(const void *, const void *))cmp1);
    for (int i = 2; i <= n; i ++)
        e[cnt ++] = (Edge){node[i - 1].id, node[i].id, node[i].y - node[i - 1].y};

    qsort(e, cnt, sizeof(Edge), (int (*)(const void *, const void *))cmp2);

    long long ans = 0;
    for (int i = 0; i < cnt; i ++) {
        int u = e[i].u, v = e[i].v, val = e[i].val;
        if (findpar(u) == findpar(v)) continue;
        unite(u, v);
        ans += val;
    }

    printf("%lld\n", ans);

    return 0;
}

