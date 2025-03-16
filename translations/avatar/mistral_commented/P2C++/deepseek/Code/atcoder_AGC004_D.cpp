#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Set the recursion limit for the function call stack to 1 million
#define RECURSION_LIMIT 1000000
#undef _GLIBCXX_DEBUG
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// Define the depth-first search function 'dfs'
vector<set<int>> links;
int dfs(int n, int k, vector<int>& aaa, int v, int p) {
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
        int hgt = dfs(n, k, aaa, u, v);

        // Update the height from leaf and cut count
        height_from_leaf = max(height_from_leaf, hgt);
        cut_count += hgt;
    }

    // Update the height from leaf and cut count for the current node 'v'
    height_from_leaf += 1;

    // If the parent node 'p' is not 0 and the height from leaf is equal to 'k',
    // then this node is a cut vertex and we need to add 1 to the cut count
    if (p != 0 && height_from_leaf == k) {
        height_from_leaf = 0;
        cut_count += 1;
    }

    // Return the height from leaf and cut count for the current node 'v'
    return height_from_leaf;
}

int main() {
    // Read input from standard input
    int n, k;
    cin >> n >> k;
    vector<int> aaa(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> aaa[i];
        aaa[i] -= 1;
    }

    // Initialize the 'links' list with sets for each node
    links.resize(n);

    // Process the input edges and add them to the 'links' list
    for (int i = 0; i < n - 1; ++i) {
        links[aaa[i]].insert(i + 1);
    }

    // Call the 'dfs' function with the initial parameters
    int ans = dfs(n, k, aaa, 0, 0);

    // If the first node is not a root node, add 1 to the answer
    if (aaa[0] != 0) {
        ans += 1;
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}
