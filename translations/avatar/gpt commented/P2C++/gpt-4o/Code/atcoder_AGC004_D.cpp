#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Function to perform DFS and calculate height and cut count
pair<int, int> dfs(const vector<set<int>>& links, int n, int k, int v, int p) {
    // Initialize height from the leaf node and cut count
    int height_from_leaf = 0;
    int cut_count = 0;

    // Iterate through all connected nodes (children) of the current node
    for (int u : links[v]) {
        // Recursively perform DFS on the child node and get its height and cut count
        auto [hgt, cut] = dfs(links, n, k, u, v);
        
        // Update the maximum height from the leaf node
        height_from_leaf = max(height_from_leaf, hgt);
        
        // Accumulate the cut count from the child nodes
        cut_count += cut;
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
    return {height_from_leaf, cut_count};
}

int main() {
    // Read input values for n (number of nodes), k (target height), and the rest of the connections
    int n, k;
    cin >> n >> k;
    
    vector<int> aaa(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> aaa[i];
    }

    // Create a list of sets to represent the graph (tree) connections
    vector<set<int>> links(n);
    
    // Populate the links based on the input connections
    for (int i = 0; i < n - 1; ++i) {
        aaa[i]--;  // Adjust for 0-based indexing
        links[aaa[i]].insert(i + 1); // i + 1 because children are indexed from 1 to n-1
    }

    // Perform DFS starting from the root node (0) and get the total cuts
    auto [_, ans] = dfs(links, n, k, 0, 0);

    // If the first node is not the root, increment the answer
    if (aaa[0] != 1) {
        ans += 1;
    }

    // Print the final answer (total cuts)
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
