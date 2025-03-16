#include <bits/stdc++.h>
using namespace std;

// Define the depth-first search function 'dfs'
void dfs(vector<set<int>> &links, int n, int k, int v, int p, int &height_from_leaf, int &cut_count) {
    // Update the height from leaf and cut count for the current node 'v'
    height_from_leaf++;

    // If the parent node 'p' is not 0 and the height from leaf is equal to 'k',
    // then this node is a cut vertex and we need to add 1 to the cut count
    if (p!= 0 && height_from_leaf == k) {
        height_from_leaf = 0;
        cut_count++;
    }

    // Iterate through neighbors of the current node 'v'
    for (int u : links[v]) {
        // Skip if the neighbor is not a valid node (0)
        if (u == 0) continue;

        // Recursively call the 'dfs' function for the neighbor 'u'
        dfs(links, n, k, u, v, height_from_leaf, cut_count);
    }
}

// Read input from standard input
int n, k;
cin >> n >> k;
vector<set<int>> links(n);
for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    a--;
    links[a].insert(i);
}

// Initialize variables for height from leaf node and cut count
int height_from_leaf = 0, cut_count = 0;

// Call the 'dfs' function with the initial parameters
dfs(links, n, k, 0, 0, height_from_leaf, cut_count);

// If the first node is not a root node, add 1 to the answer
if (links[0].size()!= 1) cut_count++;

// Print the final answer
cout << cut_count << endl;

