#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Define the depth-first search function 'dfs'
pair<int, int> dfs(const vector<set<int>>& links, int n, int k, int v, int p) {
    // Initialize variables for height from leaf node and cut count
    int height_from_leaf = 0;
    int cut_count = 0;

    // Iterate through neighbors of the current node 'v'
    for (int u : links[v]) {
        // Recursively call the 'dfs' function for the neighbor 'u'
        auto [hgt, cut] = dfs(links, n, k, u, v);

        // Update the height from leaf and cut count
        height_from_leaf = max(height_from_leaf, hgt);
        cut_count += cut;
    }

    // Update the height from leaf for the current node 'v'
    height_from_leaf += 1;

    // If the parent node 'p' is not 0 and the height from leaf is equal to 'k',
    // then this node is a cut vertex and we need to add 1 to the cut count
    if (p != 0 && height_from_leaf == k) {
        height_from_leaf = 0;
        cut_count += 1;
    }

    // Return the height from leaf and cut count for the current node 'v'
    return {height_from_leaf, cut_count};
}

int main() {
    // Read input
    int n, k;
    cin >> n >> k;
    vector<int> aaa;
    int a;
    while (cin >> a) {
        aaa.push_back(a);
    }

    // Initialize the 'links' list with sets for each node
    vector<set<int>> links(n);

    // Process the input edges and add them to the 'links' list
    for (size_t i = 0; i < aaa.size(); ++i) {
        a = aaa[i] - 1; // Convert to 0-based index
        links[a].insert(i);
    }

    // Call the 'dfs' function with the initial parameters
    auto [_, ans] = dfs(links, n, k, 0, 0);

    // If the first node is not a root node, add 1 to the answer
    if (aaa[0] != 1) {
        ans += 1;
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
