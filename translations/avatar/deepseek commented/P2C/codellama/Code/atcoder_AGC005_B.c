#include <stdio.h>
#include <stdlib.h>

#define root(x) (x == par[x] ? x : root(par[x]))
#define same(x, y) (root(x) == root(y))

void unite(int x, int y) {
    if (x != y) {
        if (rank[x] < rank[y]) {
            par[x] = y;
            size[y] += size[x];
        } else {
            par[y] = x;
            size[x] += size[y];
            if (rank[x] == rank[y]) rank[x]++;
        }
    }
}

int main() {
    int n, *a, *par, *rank, *size, *b, c, i, k, l, r, t;
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    par = (int *)malloc(n * sizeof(int));
    rank = (int *)malloc(n * sizeof(int));
    size = (int *)malloc(n * sizeof(int));
    b = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &t);
        a[t - 1] = i;
    }
    for (i = 0; i < n; i++) {
        par[i] = i;
        rank[i] = 1;
        size[i] = 1;
    }
    c = 0;
    for (k = n - 1; k >= 0; k--) {
        l = r = 1;
        if (k > 0 && a[k - 1] > a[k]) {
            l += size[root(k - 1)];
            unite(k - 1, k);
        }
        if (k + 1 < n && a[k + 1] > a[k]) {
            r += size[root(k + 1)];
            unite(k + 1, k);
        }
        c += l * r * a[k];
    }
    printf("%d\n", c);
    free(a);
    free(par);
    free(rank);
    free(size);
    free(b);
    return 0;
}

