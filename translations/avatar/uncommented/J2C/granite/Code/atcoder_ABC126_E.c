
#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007

typedef struct {
    int par[100000];
    int rank[100000];
} UnionFindTree;

void init(UnionFindTree *utf, int n) {
    int i;
    for (i = 0; i < n; i++) {
        utf->par[i] = i;
        utf->rank[i] = 0;
    }
}

int find(UnionFindTree *utf, int x) {
    if (utf->par[x] == x) {
        return x;
    } else {
        return utf->par[x] = find(utf, utf->par[x]);
    }
}

void unite(UnionFindTree *utf, int x, int y) {
    x = find(utf, x);
    y = find(utf, y);
    if (x == y) return;
    if (utf->rank[x] < utf->rank[y]) utf->par[x] = y;
    else {
        utf->par[y] = x;
        if (utf->rank[x] == utf->rank[y]) utf->rank[x]++;
    }
}

int main() {
    int n, m, x, y, z, i, cnt;
    UnionFindTree utf;

    scanf("%d", &n);
    init(&utf, n);
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &x, &y, &z);
        unite(&utf, x - 1, y - 1);
    }
    cnt = 0;
    for (i = 0; i < n; i++) {
        if (utf.par[i] == i) cnt++;
    }
    printf("%d\n", cnt);

    return 0;
}
