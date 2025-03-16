
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn 100005

typedef struct {
    int x, y, id;
}Node;

typedef struct {
    int u, v, val;
}Edge;

int par[maxn];
int n;

int findpar(int x) {
    return par[x] = (par[x] == x ? x : findpar(par[x]));
}

void unite(int x, int y) {
    x = findpar(x), y = findpar(y);
    if (x == y) return;
    par[x] = y;
}

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

int main(int argc, char const *argv[]) {
    
    scanf("%d", &n);

    init();

    Node node[maxn];
    for (int i = 1; i <= n; i ++) {
        scanf("%d%d", &node[i].x, &node[i].y);
        node[i].id = i;
    }

    int cnt = 0;
    Edge e[maxn << 1];
    for (int i = 2; i <= n; i ++) {
        e[cnt++] = (Edge){node[i - 1].id, node[i].id, node[i].x - node[i - 1].x};
    }

    for (int i = 2; i <= n; i ++) {
        e[cnt++] = (Edge){node[i - 1].id, node[i].id, node[i].y - node[i - 1].y};
    }

    qsort(e, cnt, sizeof(Edge), cmp1);

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

