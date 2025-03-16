
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_N 100000

typedef struct {
    int n;
    int par[MAX_N];
    int rank[MAX_N];
} UnionFindTree;

void init_union_find_tree(UnionFindTree *utf, int n) {
    utf->n = n;
    for (int i = 0; i < n; i++) {
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
    if (utf->rank[x] < utf->rank[y]) {
        utf->par[x] = y;
    } else {
        utf->par[y] = x;
        if (utf->rank[x] == utf->rank[y]) utf->rank[x]++;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    UnionFindTree utf;
    init_union_find_tree(&utf, n);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        x--;
        y--;
        if (z == 0) {
            unite(&utf, x, y);
        } else {
            if (find(&utf, x) == find(&utf, y)) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        }
    }
    return 0;
}

