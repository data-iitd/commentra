
#include <stdio.h>

// Define a function to find the root of an element using path compression
int root(int x, int *par) {
    return x == par[x]? x : (par[x] = root(par[x], par));
}

// Define a function to check if two elements belong to the same set
int same(int x, int y, int *par) {
    return root(x, par) == root(y, par);
}

// Define a function to unite two sets containing elements z
void unite(int x, int y, int *par, int *rank, int *size) {
    // Find the roots of the elements z
    x = root(x, par);
    y = root(y, par);
    
    // If the roots are different, unite the sets
    if (x!= y) {
        // Union by rank: attach the smaller tree under the larger tree
        if (rank[x] < rank[y]) {
            par[x] = y;  // Make y the parent of x
            size[y] += size[x];  // Update the size of the new root
        } else {
            par[y] = x;  // Make x the parent of y
            size[x] += size[y];  // Update the size of the new root
            
            // If ranks are equal, increment the rank of the new root
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }
}

int main() {
    // Read input values: first value is n, followed by n integers
    int n;
    scanf("%d", &n);
    int a[n], b[n], par[n], rank[n], size[n];
    
    // Initialize the parent array where each element is its own parent
    for (int i = 0; i < n; i++) {
        par[i] = i;
    }
    
    // Initialize rank and size arrays for union-find structure
    for (int i = 0; i < n; i++) {
        rank[i] = 1;  // All elements start with rank 1
        size[i] = 1;  // All elements start with size 1
    }
    
    // Create an array to store the indices of elements in a
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[a[i] - 1] = i;  // Store the index of each element in b
    }
    
    // Initialize a counter for the final result
    long long c = 0;
    
    // Iterate through the array b in reverse order
    for (int k = n - 1; k >= 0; k--) {
        int l = 1, r = 1;  // Initialize left and right sizes
        
        // Check if the left neighbor exists and is greater
        if (k > 0 && a[k - 1] > a[k]) {
            l += size[root(k - 1, par)];  // Add the size of the left component
            unite(k - 1, k, par, rank, size);  // Unite the left neighbor with the current element
        }
        
        // Check if the right neighbor exists and is greater
        if (k + 1 < n && a[k + 1] > a[k]) {
            r += size[root(k + 1, par)];  // Add the size of the right component
            unite(k + 1, k, par, rank, size);  // Unite the right neighbor with the current element
        }
        
        // Update the counter with the product of left size, right size, and the current element's value
        c += (long long)l * r * a[k];
    }
    
    // Print the final result
    printf("%lld\n", c);
    
    return 0;
}
