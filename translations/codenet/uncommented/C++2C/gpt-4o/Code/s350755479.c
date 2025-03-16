#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

struct Node {
    int x, y, id;
} node[MAXN];

struct Edge {
    int u, v, val;
} e[MAXN << 1];

int par[MAXN];
int n;

int cmp1(const void *a, const void *b) {
    return ((struct Node *)a)->x - ((struct Node *)b)->x;
}

int cmp2(const void *a, const void *b) {
    return ((struct Node *)a)->y - ((struct Node *)b)->y;
}

void init() {
    for (int i = 0; i <= n; i++)
        par[i] = i;
}

int findpar(int x) {
    if (par[x] != x) {
        par[x] = findpar(par[x]);
    }
    return par[x];
}

void unite(int x, int y) {
    x = findpar(x);
    y = findpar(y);
    if (x != y) {
        par[x] = y;
    }
}

int main() {
    scanf("%d", &n);

    init();

    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &node[i].x, &node[i].y);
        node[i].id = i;
    }

    qsort(node + 1, n, sizeof(struct Node), cmp1);

    int cnt = 0;
    for (int i = 2; i <= n; i++)
        e[cnt++] = (struct Edge){node[i - 1].id, node[i].id, node[i].x - node[i - 1].x};

    qsort(node + 1, n, sizeof(struct Node), cmp2);
    for (int i = 2; i <= n; i++)
        e[cnt++] = (struct Edge){node[i - 1].id, node[i].id, node[i].y - node[i - 1].y};

<<<<<<< HEAD
    qsort(e, cnt, sizeof(struct Edge), (int (*)(const void *, const void *))cmp1);
=======
    qsort(e, cnt, sizeof(struct Edge), cmp1);
>>>>>>> 98c87cb78a (data updated)

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

// <END-OF-CODE>
