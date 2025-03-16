#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>

using namespace std;

int main() {
    // Read input values for n (number of items), m (number of categories), and x (threshold value)
    int n, m, x;
    cin >> n >> m >> x;

    // Read the cost matrix where each row corresponds to an item and each column to a category
    vector<vector<int>> c(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> c[i][j];
        }
    }

    // Create an array of indices for the items
    vector<int> pre(n);
    iota(pre.begin(), pre.end(), 0);

    // Initialize lists to hold combinations and to track remaining combinations
    vector<vector<int>> l;
    vector<int> rem;

    // Initialize the answer variable to store the minimum cost
    int ans = numeric_limits<int>::max();

    // Generate all possible combinations of items of varying lengths
    for (int i = 1; i <= n; ++i) {
        vector<bool> v(n);
        fill(v.begin(), v.begin() + i, true);
        do {
            vector<int> combination;
            for (int j = 0; j < n; ++j) {
                if (v[j]) {
                    combination.push_back(pre[j]);
                }
            }
            l.push_back(combination);
        } while (prev_permutation(v.begin(), v.end()));
    }

    // Iterate over each category from 0 to m-1 (0-based index for categories)
    for (int i = 0; i < m; ++i) {
        // Check each combination of items
        for (size_t j = 0; j < l.size(); ++j) {
            int ca = 0;  // Initialize cumulative cost for the current combination
            // Calculate the total cost for the current combination in the current category
            for (int ii : l[j]) {
                ca += c[ii][i];
            }

            // If the total cost is less than the threshold x, mark this combination for removal
            if (ca < x) {
                rem.push_back(j);
            }
        }

        // Remove combinations that did not meet the cost requirement
        if (!rem.empty()) {
            for (int j = rem.size() - 1; j >= 0; --j) {
                l.erase(l.begin() + rem[j]);
            }
            rem.clear();  // Reset the remaining combinations list
        }

        // If no valid combinations remain, print -1 and exit
        if (l.empty()) {
            cout << -1 << endl;
            return 0;
        }
    }

    // If valid combinations remain, calculate the minimum cost for the first category
    for (const auto& i : l) {
        int ca = 0;  // Initialize cumulative cost for the current combination
        // Calculate the total cost for the current combination in the first category
        for (int j : i) {
            ca += c[j][0];
        }

        // Update the answer with the minimum cost found
        ans = min(ans, ca);
    }

    // Print the minimum cost found
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
