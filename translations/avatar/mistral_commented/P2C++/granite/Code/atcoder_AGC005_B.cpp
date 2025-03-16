
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define the root function which returns the root of a tree node
// This function uses recursion to find the root of a node by traversing up the tree
// until it reaches the root node or a node with the same parent
int root(int x, vector<int>& par) {
    return x == par[x]? x : par[x] = root(par[x], par);
}

// Define the same function which checks if two nodes have the same root
// This function is used to check if two nodes belong to the same tree
bool same(int x, int y, vector<int>& par) {
    return root(x, par) == root(y, par);
}

// Define the unite function which merges two trees into one
// This function sets the parent of the smaller tree to the root of the larger tree
// and updates the size of the root node accordingly
void unite(int x, int y, vector<int>& par, vector<int>& size, vector<int>& rank) {
    x = root(x, par);
    y = root(y, par);
    if (x!= y) {
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
    cin >> n;
    vector<int> a(n), b(n), par(n), rank(n), size(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i] - 1] = i;
    }
    long long c = 0;
    for (int k = n - 1; k >= 0; k--) {
        int l = 1, r = 1;
        if (k > 0 && a[k - 1] > a[k]) {
            l += size[root(k - 1, par)];
            unite(k - 1, k, par, size, rank);
        }
        if (k + 1 < n && a[k + 1] > a[k]) {
            r += size[root(k + 1, par)];
            unite(k + 1, k, par, size, rank);
        }
        c += (long long)l * r * a[k];
    }
    cout << c << endl;
    return 0;
}

