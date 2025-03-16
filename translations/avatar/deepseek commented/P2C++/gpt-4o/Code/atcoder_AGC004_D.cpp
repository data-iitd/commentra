#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int dfs(const vector<set<int>>& links, int n, int k, int v, int p) {
    int height_from_leaf = 0;  // Initialize the height from the leaf node
    int cut_count = 0;  // Initialize the count of cuts
    for (int u : links[v]) {  // Traverse the tree
        if (u == 0) {  // Skip if the node is the root (0)
            continue;
        }
        auto [hgt, cut] = dfs(links, n, k, u, v);  // Recursively call DFS
        height_from_leaf = max(height_from_leaf, hgt);  // Update the height from the leaf
        cut_count += cut;  // Count the number of cuts
    }
    height_from_leaf += 1;  // Increment the height from the leaf node
    if (p != 0 && height_from_leaf == k) {  // Check if a cut is needed
        height_from_leaf = 0;  // Reset the height
        cut_count += 1;  // Increment the cut count
    }
    return make_pair(height_from_leaf, cut_count);  // Return the height and cut count
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> aaa(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> aaa[i];
    }

    vector<set<int>> links(n);  // Initialize the tree structure
    for (int i = 0; i < n - 1; ++i) {  // Build the tree
        aaa[i] -= 1;  // Adjust for 0-based index
        links[aaa[i]].insert(i + 1);  // Add the child node
    }

    auto [_, ans] = dfs(links, n, k, 0, -1);  // Perform DFS starting from the root
    if (aaa[0] != 1) {  // Adjust the answer if necessary
        ans += 1;
    }
    cout << ans << endl;  // Output the final result

    return 0;
}  // <END-OF-CODE>
