#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

const int size = 1000000;

// Initialize arrays for parent and rank
vector<int> par, rank;

// Function to initialize arrays
void initialize(int n) {
    par.resize(n);
    rank.resize(n);
    // Set all elements as their own parent initially
    for (int i = 0; i < n; i++) {
        par[i] = i;
    }
}

// Function to find the root of a node
int root(int i) {
    // If the node is its own parent, return it
    if (par[i] == i) {
        return i;
    }
    // Recursively find the root of the parent
    par[i] = root(par[i]);
    // Return the new root
    return par[i];
}

// Function to check if two nodes have the same parent
bool same(int i, int j) {
    // Find the root of both nodes
    return root(i) == root(j);
}

// Function to unite two nodes
void unite(int i, int j) {
    // Find the roots of both nodes
    i = root(i);
    j = root(j);
    // If they already have the same parent, return
    if (i == j) {
        return;
    }
    // Make the smaller rank node a child of the larger rank node
    if (rank[i] < rank[j]) {
        par[i] = j;
    } else {
        par[j] = i;
        // If they have the same rank, increase the rank of the node with the smaller index
        if (rank[i] == rank[j]) {
            rank[i]++;
        }
    }
}

// Function to read two integers from a single line
pair<int, int> NextInts() {
    int x, y;
    cin >> x >> y;
    return {x - 1, y - 1}; // Decrease each index by 1
}

// Function to read an array of integers from a single line
vector<int> NextIntArray(int n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--; // Decrease each index by 1
    }
    return a;
}

// Main function
int main() {
    // Read number of nodes and edges
    int n, m;
    cin >> n >> m;
    // Read array of edges
    vector<int> p = NextIntArray(n);
    // Initialize arrays
    initialize(n);
    // Process each edge by uniting their parents
    for (int i = 0; i < m; i++) {
        auto [x, y] = NextInts();
        unite(x, y);
    }
    // Count the number of disconnected components
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (same(i, p[i])) {
            s++;
        }
    }
    // Print the result
    cout << s << endl;
    return 0;
}

// <END-OF-CODE>
