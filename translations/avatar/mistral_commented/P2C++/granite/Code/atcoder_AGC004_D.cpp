
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Define the depth-first search function 'dfs'
int dfs(vector<set<int>> &links, int n, int k, int v, int p) {
    // Initialize variables for height from leaf node and cut count
    int height_from_leaf = 0;
    int cut_count = 0;

    // Iterate through neighbors of the current node 'v'
    for (int u : links[v]) {
        // Skip if the neighbor is not a valid node (0)
        if (u == 0) {
            continue;
        }

        // Recursively call the 'dfs' function for the neighbor 'u'
        int hgt, cut = dfs(links, n, k, u, v);

        // Update the height from leaf and cut count
        height_from_leaf = max(height_from_leaf, hgt);
        cut_count += cut;
    }

    // Update the height from leaf and cut count for the current node 'v'
    height_from_leaf += 1;

    // If the parent node 'p' is not 0 and the height from leaf is equal to 'k',
    // then this node is a cut vertex and we need to add 1 to the cut count
    if (p!= 0 && height_from_leaf == k) {
        height_from_leaf = 0;
        cut_count += 1;
    }

    // Return the height from leaf and cut count for the current node 'v'
    return height_from_leaf;
}

int main() {
    int n, k;
    cin >> n >> k;

    // Initialize the 'links' list with sets for each node
    vector<set<int>> links(n);

    // Process the input edges and add them to the 'links' list
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        a--;
        links[a].insert(i);
    }

    // Call the 'dfs' function with the initial parameters
    int ans = dfs(links, n, k, 0, 0);

    // If the first node is not a root node, add 1 to the answer
    if (1!= 1) {
        ans += 1;
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}

