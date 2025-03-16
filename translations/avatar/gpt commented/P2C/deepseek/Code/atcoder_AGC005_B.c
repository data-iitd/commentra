#include <stdio.h>
#include <stdlib.h>

// Define a function to find the root of an element using path compression
int root(int *par, int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = root(par, par[x]);
    }
}

// Define a function to check if two elements belong to the same set
int same(int *par, int x, int y) {
    return root(par, x) == root(par, y);
}

// Define a function to unite two sets containing elements z
void unite(int *par, int *rank, int *size, int x, int y) {
    // Find the roots of the elements x and y
    int rx = root(par, x);
    int ry = root(par, y);
    
    // If the roots are different, unite the sets
    if (rx != ry) {
        // Union by rank: attach the smaller tree under the larger tree
        if (rank[rx] < rank[ry]) {
            par[rx] = ry;  // Make ry the parent of rx
            size[ry] += size[rx];  // Update the size of the new root
        } else {
            par[ry] = rx;  // Make rx the parent of ry
            size[rx] += size[ry];  // Update the size of the new root
            
            // If ranks are equal, increment the rank of the new root
            if (rank[rx] == rank[ry]) {
                rank[rx]++;
            }
        }
    }
}

int main() {
    // Read input values: first value is n, followed by n integers
    int n, *a, *b, *par, *rank, *size;
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    b = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[a[i] - 1] = i;  // Store the index of each element in b
    }

    // Initialize the parent array where each element is its own parent
    par = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        par[i] = i;
    }

    // Initialize rank and size arrays for union-find structure
    rank = (int *)malloc((n + 1) * sizeof(int));
    size = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        rank[i] = 1;  // All elements start with rank 1
        size[i] = 1;  // All elements start with size 1
    }

    // Initialize a counter for the final result
    long long c = 0;

    // Iterate through the array b in reverse order
    for (int k = n - 1; k >= 0; k--) {
        int l = 1, r = 1;  // Initialize left and right sizes
        
        // Check if the left neighbor exists and is greater
        if (b[k] > 0 && a[b[k] - 1] > a[b[k]]) {
            l += size[root(par, b[k] - 1)];  // Add the size of the left component
            unite(par, rank, size, b[k] - 1, b[k]);  // Unite the left neighbor with the current element
        }
        
        // Check if the right neighbor exists and is greater
        if (b[k] + 1 < n && a[b[k] + 1] > a[b[k]]) {
            r += size[root(par, b[k] + 1)];  // Add the size of the right component
            unite(par, rank, size, b[k] + 1, b[k]);  // Unite the right neighbor with the current element
        }
        
        // Update the counter with the product of left size, right size, and the current element's value
        c += l * r * (long long)a[b[k]];
    }

    // Print the final result
    printf("%lld\n", c);

    // Free allocated memory
    free(a);
    free(b);
    free(par);
    free(rank);
    free(size);

    return 0;
}
