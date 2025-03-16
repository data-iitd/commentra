#include <iostream>
#include <vector>
using namespace std;

// Define the root function which returns the root of a tree node
// This function uses recursion to find the root of a node by traversing up the tree
// until it reaches the root node or a node with the same parent
int root(int x, vector<int>& par) {
    return par[x] == x ? x : root(par[x], par);
}

// Define the same function which checks if two nodes have the same root
// This function is used to check if two nodes belong to the same tree
bool same(int x, int y, vector<int>& par) {
    return root(x, par) == root(y, par);
}

// Define the unite function which merges two trees into one
// This function sets the parent of the smaller tree to the root of the larger tree
// and updates the size of the root node accordingly
void unite(int x, int y, vector<int>& par, vector<int>& rank, vector<int>& size) {
    x = root(x, par);
    y = root(y, par);
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
    // Read input from standard input and initialize variables
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Initialize parent and rank lists with given size
    vector<int> par(n), rank(n, 1), size(n, 1);
    for (int i = 0; i < n; ++i) {
        par[i] = i;
    }

    // Initialize a vector b to store the indices of elements in the input list a
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        b[a[i] - 1] = i;
    }

    // Initialize a variable c to store the result
    long long c = 0;

    // Iterate through the list b from the second element to the first
    for (int k : vector<int>(b.rbegin(), b.rend())) {
        // Initialize variables l and r to store the sizes of the left and right subtrees
        long long l = 1, r = 1;

        // Check if the current node k has a larger element to its left
        if (k > 0 && a[k - 1] > a[k]) {
            // If yes, update l with the size of the left subtree
            l += size[root(k - 1, par)];
            // Merge the left and current subtrees
            unite(k - 1, k, par, rank, size);
        }

        // Check if the current node k has a larger element to its right
        if (k + 1 < n && a[k + 1] > a[k]) {
            // If yes, update r with the size of the right subtree
            r += size[root(k + 1, par)];
            // Merge the right and current subtrees
            unite(k + 1, k, par, rank, size);
        }

        // Update the result variable c with the product of the sizes of the left and right subtrees
        // and the value of the current element
        c += l * r * a[k];
    }

    // Print the result
    cout << c << endl;

    return 0;
}

// <END-OF-CODE>
