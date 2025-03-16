#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<int> g[100000]; // Graph's adjacency list representation

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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n; // Read the number of nodes
    for (int i = 0; i < n - 1; ++i) { // Read the edges and construct the graph
        int a, b;
        cin >> a >> b; // Read nodes a and b
        g[a - 1].push_back(b - 1); // Add edge from a to b (0-based index)
        g[b - 1].push_back(a - 1); // Add edge from b to a (0-based index)
    }
    
    int m = maxMatching(0, -1) / 2; // Calculate the maximum matching
    cout << (2 * m == n ? "Second" : "First") << '\n'; // Determine the winner and print the result
    
    return 0; // End of the program
}

// <END-OF-CODE>
