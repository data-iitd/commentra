#include <iostream>
#include <vector>

using namespace std;

class UnionFindTree {
    int n; // Number of elements
    vector<int> par; // Parent array
    vector<int> rank; // Rank array for union by rank

public:
    // Constructor to initialize the Union-Find structure
    UnionFindTree(int n) : n(n), par(n), rank(n, 0) {
        for (int i = 0; i < n; i++) {
            par[i] = i; // Initialize each element to be its own parent
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
        if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }

    // Check if x and y are in the same set
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

class Main {
public:
    // Method to execute the main logic
    void doIt() {
        int n, m;
        cin >> n; // Read the number of elements (nodes)
        UnionFindTree utf(n); // Initialize Union-Find data structure with n elements
        cin >> m; // Read the number of connections (edges)

        // Process each connection
        for (int i = 0; i < m; i++) {
            int x, y, z;
            cin >> x >> y >> z; // Read the two nodes to unite and the weight (not used)
            utf.unite(x - 1, y - 1); // Unite the two nodes (adjusting for 0-based index)
        }

        // Count the number of unique connected components
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            // Check if the current node is a root of a component
            if (utf.find(i) == i) {
                cnt++;
            }
        }

        // Output the count of unique connected components
        cout << cnt << endl;
    }
};

// Main method to start the program
int main() {
    Main().doIt();
    return 0;
}

// <END-OF-CODE>
