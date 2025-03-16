#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

// Function to generate combinations
void generateCombinations(const vector<int>& pre, int start, int depth, vector<vector<int>>& result, vector<int>& current) {
    if (depth == 0) {
        result.push_back(current);
        return;
    }
    for (int i = start; i <= pre.size() - depth; ++i) {
        current.push_back(pre[i]);
        generateCombinations(pre, i + 1, depth - 1, result, current);
        current.pop_back();
    }
}

int main() {
    // Take input dimensions and threshold from user
    int n, m, x;
    cin >> n >> m >> x;

    // Initialize 2D vector 'c' with dimensions (n, m)
    vector<vector<int>> c(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> c[i][j];
        }
    }

    // Initialize vector 'l' for storing combinations and 'rem' for storing indices
    vector<vector<int>> l;
    vector<int> rem;

    // Initialize variable 'ans' for storing minimum number of tests
    int ans = 0;

    // Create a vector for indices
    vector<int> pre(n);
    iota(pre.begin(), pre.end(), 0); // Fill with 0, 1, ..., n-1

    // Loop through all possible combinations of 'pre' indices
    for (int i = 0; i <= n; ++i) {
        vector<int> current;
        generateCombinations(pre, 0, i, l, current);
    }

    // Loop through each iteration 'i' of test cases
    for (int i = 0; i < m; ++i) {
        // Initialize variable 'ca' to 0 for sum of tests in current combination
        int ca = 0;

        // Loop through each combination in 'l'
        for (const auto& combination : l) {
            // Reset ca for each combination
            ca = 0;

            // Loop through each index 'j' in current combination
            for (int j : combination) {
                // Add the test result at index 'j' and test case 'i' to 'ca'
                ca += c[j][i];
            }

            // If the sum of tests in current combination is less than threshold 'x',
            // add the index of the current combination to 'rem' list
            if (ca < x) {
                rem.push_back(i);
            }
        }

        // If 'rem' list is not empty, remove the combinations with indices in 'rem' from 'l' list
        if (!rem.empty()) {
            for (int j : rem) {
                l.erase(l.begin() + j);
            }
            rem.clear();
        }

        // If 'l' list is empty, print -1 and break the loop
        if (l.empty()) {
            cout << -1 << endl;
            return 0;
        }
    }

    // If the loop completes without finding a valid combination,
    // calculate the minimum number of tests in all valid combinations
    for (const auto& combination : l) {
        int ca = 0;
        for (int j : combination) {
            ca += c[j][0];
        }

        // Update 'ans' with minimum number of tests among all valid combinations
        if (ans == 0) {
            ans = ca;
        } else {
            ans = min(ans, ca);
        }
    }

    // Print the minimum number of tests required
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
