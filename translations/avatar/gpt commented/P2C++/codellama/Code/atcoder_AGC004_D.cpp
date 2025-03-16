
#include <bits/stdc++.h>

using namespace std;

// Set the maximum recursion limit to handle deep recursions
#define MAX_RECURSION_DEPTH 1000000

// Global variables
int n, k;
vector<vector<int>> links;

// DFS function to find the maximum height from the leaf node and the total cut count
pair<int, int> dfs(int v, int p) {
    // Initialize height from the leaf node and cut count
    int height_from_leaf = 0;
    int cut_count = 0;
    
    // Iterate through all connected nodes (children) of the current node
    for (int u : links[v]) {
        // Skip if the child node is 0 (indicating no further connections)
        if (u == 0) {
            continue;
        }
        
        // Recursively perform DFS on the child node and get its height and cut count
        pair<int, int> hgt_cut = dfs(u, v);
        
        // Update the maximum height from the leaf node
        height_from_leaf = max(height_from_leaf, hgt_cut.first);
        
        // Accumulate the cut count from the child nodes
        cut_count += hgt_cut.second;
    }
    
    // Increment the height from the leaf node as we return to the parent
    height_from_leaf += 1;
    
    // Check if the current height matches k and we are not at the root node
    if (p != 0 && height_from_leaf == k) {
        // Reset height from leaf to 0 and increment cut count
        height_from_leaf = 0;
        cut_count += 1;
    }
    
    // Return the height from the leaf and the total cut count
    return make_pair(height_from_leaf, cut_count);
}

int main() {
    // Read input values for n (number of nodes), k (target height), and the rest of the connections
    cin >> n >> k;
    links.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;  // Adjust for 0-based indexing
        links[a].push_back(b);
    }
    
    // Perform DFS starting from the root node (0) and get the total cuts
    pair<int, int> ans = dfs(0, 0);
    
    // If the first node is not the root, increment the answer
    if (links[0].size() != 0) {
        ans.second += 1;
    }
    
    // Print the final answer (total cuts)
    cout << ans.second << endl;
    
    return 0;
}

