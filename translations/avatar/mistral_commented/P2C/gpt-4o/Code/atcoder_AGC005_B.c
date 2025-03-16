#include <stdio.h>
#include <stdlib.h>

int *par, *rank, *size, *b;

int root(int x) {
    return par[x] == x ? x : (par[x] = root(par[x])); // Path compression
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
    int n;
    scanf("%d", &n);
    
    int *a = (int *)malloc(n * sizeof(int));
    par = (int *)malloc(n * sizeof(int));
    rank = (int *)malloc(n * sizeof(int));
    size = (int *)malloc(n * sizeof(int));
    b = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        par[i] = i; // Initialize parent
        rank[i] = 1; // Initialize rank
        size[i] = 1; // Initialize size
    }

    for (int i = 0; i < n; i++) {
        b[a[i] - 1] = i; // Store indices of elements
    }

    long long c = 0; // Use long long to avoid overflow

    for (int k = n - 1; k >= 0; k--) {
        int l = 1, r = 1;

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

    printf("%lld\n", c); // Print the result

    // Free allocated memory
    free(a);
    free(par);
    free(rank);
    free(size);
    free(b);

    return 0;
}

// <END-OF-CODE>
