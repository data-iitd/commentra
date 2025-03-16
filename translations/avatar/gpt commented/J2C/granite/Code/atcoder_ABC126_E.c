
#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct {
    int *par;
    int *rank;
} UnionFindTree;

UnionFindTree *createUnionFindTree(int n) {
    UnionFindTree *utf = (UnionFindTree *)malloc(sizeof(UnionFindTree));
    utf->par = (int *)malloc(sizeof(int) * n);
    utf->rank = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        utf->par[i] = i;
        utf->rank[i] = 0;
    }
    return utf;
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
    if (utf->rank[x] < utf->rank[y]) {
        utf->par[x] = y;
    } else {
        utf->par[y] = x;
        if (utf->rank[x] == utf->rank[y]) {
            utf->rank[x]++;
        }
    }
}

bool same(UnionFindTree *utf, int x, int y) {
    return find(utf, x) == find(utf, y);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    UnionFindTree *utf = createUnionFindTree(n);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        unite(utf, x - 1, y - 1);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (utf->par[i] == i) {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
