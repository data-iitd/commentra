
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform DFS and calculate the total cuts
int dfs(vector<vector<int>>& links, int n, int k, int v, int p) {
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
        int hgt, cut = dfs(links, n, k, u, v);

        // Update the maximum height from the leaf node
        height_from_leaf = max(height_from_leaf, hgt);

        // Accumulate the cut count from the child nodes
        cut_count += cut;
    }

    // Increment the height from the leaf node as we return to the parent
    height_from_leaf += 1;

    // Check if the current height matches k and we are not at the root node
    if (p!= 0 && height_from_leaf == k) {
        // Reset height from leaf to 0 and increment cut count
        height_from_leaf = 0;
        cut_count += 1;
    }

    // Return the height from the leaf and the total cut count
    return height_from_leaf, cut_count;
}

int main() {
    // Read input values for n (number of nodes), k (target height), and the rest of the connections
    int n, k;
    cin >> n >> k;

    // Create a vector of vectors to represent the graph (tree) connections
    vector<vector<int>> links(n);

    // Populate the links based on the input connections
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        a--;  // Adjust for 0-based indexing
        links[a].push_back(i);
    }

    // Perform DFS starting from the root node (0) and get the total cuts
    int _, ans = dfs(links, n, k, 0, 0);

    // If the first node is not the root, increment the answer
    if (links[0].size()!= 1) {
        ans += 1;
    }

    // Print the final answer (total cuts)
    cout << ans << endl;

    return 0;
}

