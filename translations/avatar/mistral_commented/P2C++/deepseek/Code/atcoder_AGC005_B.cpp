#include <iostream>
#include <vector>
#include <numeric> // for std::iota

using namespace std;

// Define the root function which returns the root of a tree node
// This function uses recursion to find the root of a node by traversing up the tree
// until it reaches the root node or a node with the same parent
int root(vector<int>& par, int x) {
    return par[x] == x ? x : root(par, par[x]);
}

// Define the same function which checks if two nodes have the same root
// This function is used to check if two nodes belong to the same tree
bool same(vector<int>& par, int x, int y) {
    return root(par, x) == root(par, y);
}

// Define the unite function which merges two trees into one
// This function sets the parent of the smaller tree to the root of the larger tree
// and updates the size of the root node accordingly
void unite(vector<int>& par, vector<int>& rank, vector<int>& size, int x, int y) {
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
                rank[x] += 1;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Initialize parent and rank lists with given size
    vector<int> par(n);
    iota(par.begin(), par.end(), 0);
    vector<int> rank(n, 1);
    vector<int> size(n, 1);

    // Initialize a list b to store the indices of elements in the input list a
    vector<int> b(n);
    // Iterate through the input list and store the indices of elements in list b
    for (int i = 0; i < n; ++i) {
        b[a[i] - 1] = i;
    }

    // Initialize a variable c to store the result
    long long c = 0;

    // Iterate through the list b from the second element to the first
    for (int k : b) {
        // Initialize variables l and r to store the sizes of the left and right subtrees
        int l = 1, r = 1;

        // Check if the current node k has a larger element to its left
        if (k > 0 && a[k - 1] > a[k]) {
            // If yes, update l with the size of the left subtree
            l += size[root(par, k - 1)];
            // Merge the left and current subtrees
            unite(par, rank, size, k - 1, k);
        }

        // Check if the current node k has a larger element to its right
        if (k + 1 < n && a[k + 1] > a[k]) {
            // If yes, update r with the size of the right subtree
            r += size[root(par, k + 1)];
            // Merge the right and current subtrees
            unite(par, rank, size, k + 1, k);
        }

        // Update the result variable c with the product of the sizes of the left and right subtrees
        // and the value of the current element
        c += static_cast<long long>(l) * r * a[k];
    }

    // Print the result
    cout << c << endl;

    return 0;
}
