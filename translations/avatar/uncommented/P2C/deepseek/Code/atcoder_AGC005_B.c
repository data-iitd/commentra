#include <stdio.h>
#include <stdlib.h>

int *par, *rank, *size;

int root(int x) {
    while (par[x] != x) {
        x = par[x];
    }
    return x;
}

int same(int x, int y) {
    return root(x) == root(y);
}

void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y) {
        if (rank[x] < rank[y]) {
            par[x] = y;
            size[y] += size[x];
        } else {
            par[y] = x;
            size[x] += size[y];
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }
}

int main() {
    int n, *a, *b, c = 0;
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    b = (int *)malloc(n * sizeof(int));
    par = (int *)malloc(n * sizeof(int));
    rank = (int *)malloc(n * sizeof(int));
    size = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        par[i] = i;
        rank[i] = 1;
        size[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        b[a[i] - 1] = i;
    }

    for (int k = n - 1; k >= 0; k--) {
        int l = 1, r = 1;
        if (k > 0 && a[k - 1] > a[k]) {
            l += size[root(k - 1)];
            unite(k - 1, k);
        }
        if (k < n - 1 && a[k + 1] > a[k]) {
            r += size[root(k + 1)];
            unite(k + 1, k);
        }
        c += l * r * a[k];
    }

    printf("%d\n", c);

    free(a);
    free(b);
    free(par);
    free(rank);
    free(size);

    return 0;
}
