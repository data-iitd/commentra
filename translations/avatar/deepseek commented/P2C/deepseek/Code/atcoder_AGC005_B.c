#include <stdio.h>
#include <stdlib.h>

// Define the root function to find the root of a given element in a disjoint set
int root(int *par, int x) {
    if (par[x] == x) {
        return x;
    } else {
        return root(par, par[x]);
    }
}

// Define the same function to check if two elements are in the same set
int same(int *par, int x, int y) {
    return root(par, x) == root(par, y);
}

// Define the unite function to merge two sets containing the given elements
void unite(int *par, int *rank, int *size, int x, int y) {
    x = root(par, x);
    y = root(par, y);
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
    int n, *a, *b, *par, *rank, *size, c = 0;
    int i, k;

    // Read the input, initialize the disjoint set, and process the array
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    b = (int *)malloc(n * sizeof(int));
    par = (int *)malloc(n * sizeof(int));
    rank = (int *)malloc(n * sizeof(int));
    size = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        par[i] = i;
        rank[i] = 1;
        size[i] = 1;
    }

    // Process the array in reverse order to calculate the result
    for (k = n - 1; k >= 0; k--) {
        b[k] = k;
    }

    for (k = 0; k < n; k++) {
        int l = 1, r = 1;
        if (b[k] > 0 && a[b[k] - 1] > a[b[k]]) {
            l += size[root(par, b[k] - 1)];
            unite(par, rank, size, b[k] - 1, b[k]);
        }
        if (b[k] + 1 < n && a[b[k] + 1] > a[b[k]]) {
            r += size[root(par, b[k] + 1)];
            unite(par, rank, size, b[k] + 1, b[k]);
        }
        c += l * r * a[b[k]];
    }

    // Print the final result
    printf("%d\n", c);

    // Free allocated memory
    free(a);
    free(b);
    free(par);
    free(rank);
    free(size);

    return 0;
}
