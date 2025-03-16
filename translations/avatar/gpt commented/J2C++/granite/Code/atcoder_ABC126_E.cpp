
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Union-Find data structure
class UnionFindTree {
private:
    vector<int> par; // Parent array
    vector<int> rank; // Rank array for union by rank

public:
    // Constructor to initialize the Union-Find structure
    UnionFindTree(int n) {
        par.resize(n);
        rank.resize(n);
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

int main() {
    int n, m;
    cin >> n >> m;
    UnionFindTree utf(n);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        utf.unite(x - 1, y - 1);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (utf.par[i] == i) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}

