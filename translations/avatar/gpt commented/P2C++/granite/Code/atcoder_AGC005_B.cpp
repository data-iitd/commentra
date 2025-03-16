
#include <iostream>
#include <vector>

using namespace std;

// Define a function to find the root of an element using path compression
int root(vector<int>& par, int x) {
    return x if par[x] == x else root(par, par[x]);
}

// Define a function to check if two elements belong to the same set
bool same(vector<int>& par, int x, int y) {
    return root(par, x) == root(par, y);
}

// Define a function to unite two sets containing elements z
void unite(vector<int>& par, vector<int>& rank, vector<int>& size, int x, int y) {
    // Find the roots of the elements z
    x = root(par, x);
    y = root(par, y);
    
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
                rank[x] += 1;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    // Initialize the parent array where each element is its own parent
    vector<int> par(n);
    for (int i = 0; i < n; i++) {
        par[i] = i;
    }
    
    // Initialize rank and size arrays for union-find structure
    vector<int> rank(n, 1);  // All elements start with rank 1
    vector<int> size(n, 1);  // All elements start with size 1
    
    // Create an array to store the indices of elements in a
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        b[t - 1] = i;  // Store the index of each element in b
    }
    
    // Initialize a counter for the final result
    long long c = 0;
    
    // Iterate through the array b in reverse order
    for (int k = n - 1; k >= 0; k--) {
        int l = 1, r = 1;  // Initialize left and right sizes
        
        // Check if the left neighbor exists and is greater
        if (k > 0 && b[k - 1] > b[k]) {
            l += size[root(par, k - 1)];  // Add the size of the left component
            unite(par, rank, size, k - 1, k);  // Unite the left neighbor with the current element
        }
        
        // Check if the right neighbor exists and is greater
        if (k + 1 < n && b[k + 1] > b[k]) {
            r += size[root(par, k + 1)];  // Add the size of the right component
            unite(par, rank, size, k + 1, k);  // Unite the right neighbor with the current element
        }
        
        // Update the counter with the product of left size, right size, and the current element's value
        c += l * r * b[k];
    }
    
    // Print the final result
    cout << c << endl;
}

Translate the above C++ code to Java and end with comment "