#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
using namespace std;

// g is a static array of vectors that will store the graph's adjacency list representation.
vector<int> g[100000];

// maxMatching method calculates the maximum matching in a tree structure.
int maxMatching(int v, int p) {
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
    int n; // Number of nodes
    cin >> n; // Read the number of nodes
    for (int i = 0; i < n - 1; ++i) { // Read the edges and construct the graph
        int a, b; // Nodes a and b
        cin >> a >> b; // Read node a and b
        g[a - 1].push_back(b - 1); // Add edge from a to b
        g[b - 1].push_back(a - 1); // Add edge from b to a
    }
    int m = maxMatching(0, -1) / 2; // Calculate the maximum matching
    cout << (2 * m == n ? "Second" : "First") << endl; // Determine the winner and print the result
    return 0;
}

