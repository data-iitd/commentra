
#include <bits/stdc++.h>
using namespace std;

// g is a static vector of vectors that will store the graph's adjacency list representation.
static vector<vector<int>> g;

// maxMatching method calculates the maximum matching in a tree structure.
static int maxMatching(int v, int p) {
    int a = 0; // Number of matched pairs
    int o = 0; // Number of unmatched nodes
    for (int w : g[v]) {
        if (w == p) continue; // Skip the parent node
        int r = maxMatching(w, v); // Recursively calculate matching for child nodes
        a += r / 2; // Add half of the matches from the child
        o += r % 2; // Count the unmatched nodes
    }
    return 2 * a + min(1, o) + 1; // Return the total number of matches
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n; // Read the number of nodes
    g.resize(n); // Initialize the graph's adjacency list
    for (int i = 0; i < n - 1; ++i) { // Read the edges and construct the graph
        int a, b;
        cin >> a >> b; // Read node a and node b
        g[a - 1].push_back(b - 1); // Add edge from a to b
        g[b - 1].push_back(a - 1); // Add edge from b to a
    }
    int m = maxMatching(0, -1) / 2; // Calculate the maximum matching
    cout << (2 * m == n? "Second" : "First") << endl; // Determine the winner and print the result
    return 0;
}

