#include <stdio.h>
#include <stdlib.h>

int *par, *rank, *size, *b;

int root(int x) {
    if (par[x] != x) {
        par[x] = root(par[x]); // Path compression
    }
    return par[x];
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
        b[a[i] - 1] = i; // Store the index of each element in b
        par[i] = i; // Initialize parent array
        rank[i] = 1; // Initialize rank array
        size[i] = 1; // Initialize size array
    }
    
    long long c = 0; // Initialize counter for the final result
    
    // Iterate through the array b in reverse order
    for (int k = n - 1; k >= 0; k--) {
        int l = 1, r = 1; // Initialize left and right sizes
        if (b[k] > 0 && a[b[k] - 1] > a[b[k]]) {
            l += size[root(b[k] - 1)]; // Add the size of the left component
            unite(b[k] - 1, b[k]); // Unite the left neighbor with the current element
        }
        if (b[k] + 1 < n && a[b[k] + 1] > a[b[k]]) {
            r += size[root(b[k] + 1)]; // Add the size of the right component
            unite(b[k] + 1, b[k]); // Unite the right neighbor with the current element
        }
        c += (long long)l * r * a[b[k]]; // Update the counter
    }
    
    printf("%lld\n", c); // Print the final result
    
    // Free allocated memory
    free(a);
    free(par);
    free(rank);
    free(size);
    free(b);
    
    return 0;
}

// <END-OF-CODE>
