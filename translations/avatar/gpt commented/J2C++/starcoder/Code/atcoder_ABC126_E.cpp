#include <bits/stdc++.h>
using namespace std;

// Constant for modulo operation
const int MOD = 1000000007;

// Class to implement Union-Find data structure
class UnionFindTree {
public:
    int n; // Number of elements
    int *par; // Parent array
    int *rank; // Rank array for union by rank

    // Constructor to initialize the Union-Find structure
    UnionFindTree(int n) {
        this->n = n;
        par = new int[n];
        rank = new int[n];
        // Initialize each element to be its own parent and rank to 0
        for (int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    // Find the root of the set containing x with path compression
    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }

    // Unite the sets containing x and y
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        // If they are already in the same set, do nothing
        if (x == y) return;
        // Union by rank
        if (rank[x] < rank[y])
            par[x] = y;
        else {
            par[y] = x;
            if (rank[x] == rank[y])
                rank[x]++;
        }
    }

    // Check if x and y are in the same set
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

// Main method to start the program
int main() {
    // Read the number of elements (nodes)
    int n = 0;
    cin >> n;
    // Initialize Union-Find data structure with n elements
    UnionFindTree utf(n);
    // Read the number of connections (edges)
    int m = 0;
    cin >> m;

    // Process each connection
    for (int i = 0; i < m; i++) {
        // Read the two nodes to unite and the weight (not used in this implementation)
        int x = 0;
        int y = 0;
        int z = 0;
        cin >> x >> y >> z;
        // Unite the two nodes
        utf.unite(x, y);
    }

    // Count the number of unique connected components
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        // Check if the current node is a root of a component
        if (utf.par[i] == i) {
            cnt++;
        }
    }

    // Output the count of unique connected components
    cout << cnt << endl;
    return 0;
}

