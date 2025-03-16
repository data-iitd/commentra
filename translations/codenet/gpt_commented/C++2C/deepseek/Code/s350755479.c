#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn 100005

typedef struct {
    int x, y, id;
} Node;

typedef struct {
    int u, v, val;
} Edge;

Node node[maxn];
Edge e[maxn << 1];
int par[maxn];
int n;

int cmp1(const void *a, const void *b) {
    Node *nodeA = (Node *)a;
    Node *nodeB = (Node *)b;
    return nodeA->x - nodeB->x;
}

int cmp2(const void *a, const void *b) {
    Node *nodeA = (Node *)a;
    Node *nodeB = (Node *)b;
    return nodeA->y - nodeB->y;
}

void init() {
    for (int i = 0; i <= n; i++)
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

int main() {
    scanf("%d", &n);
    init();
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &node[i].x, &node[i].y);
        node[i].id = i;
    }
    qsort(node + 1, n, sizeof(Node), cmp1);
    int cnt = 0;
    for (int i = 2; i <= n; i++)
        e[cnt++] = (Edge){node[i - 1].id, node[i].id, node[i].x - node[i - 1].x};
    qsort(node + 1, n, sizeof(Node), cmp2);
    for (int i = 2; i <= n; i++)
        e[cnt++] = (Edge){node[i - 1].id, node[i].id, node[i].y - node[i - 1].y};
    qsort(e, cnt, sizeof(Edge), (int (*)(const void *, const void *))cmp);
    long long ans = 0;
    for (int i = 0; i < cnt; i++) {
        int u = e[i].u, v = e[i].v, val = e[i].val;
        if (findpar(u) == findpar(v)) continue;
        unite(u, v);
        ans += val;
    }
    printf("%lld\n", ans);
    return 0;
}
