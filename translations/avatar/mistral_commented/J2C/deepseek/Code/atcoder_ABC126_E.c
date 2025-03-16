#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct {
    int n;
    int *par;
    int *rank;
} UnionFindTree;

UnionFindTree* createUnionFindTree(int n) {
    UnionFindTree *utf = (UnionFindTree *)malloc(sizeof(UnionFindTree));
    utf->n = n;
    utf->par = (int *)malloc(n * sizeof(int));
    utf->rank = (int *)malloc(n * sizeof(int));
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
        if (utf->rank[x] == utf->rank[y]) utf->rank[x]++;
    }
}

int same(UnionFindTree *utf, int x, int y) {
    return find(utf, x) == find(utf, y);
}

int main() {
    int n, m;
    scanf("%d", &n);
    UnionFindTree *utf = createUnionFindTree(n);
    scanf("%d", &m);

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

    free(utf->par);
    free(utf->rank);
    free(utf);

    return 0;
}
