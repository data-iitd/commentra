#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>

using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    // Read the cost matrix where each row represents a book and columns represent cost and skill levels
    vector<vector<int>> c(n, vector<int>(m + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            cin >> c[i][j];
        }
    }

    // Initialize a vector to store combinations
    vector<vector<int>> l;
    vector<int> pre(n);
    iota(pre.begin(), pre.end(), 0); // Fill pre with 0, 1, ..., n-1

    // Generate all possible combinations of books
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

    // Initialize the answer variable to store the minimum cost
    int ans = numeric_limits<int>::max();

    // Check each combination to see if the total skill level meets the requirement
    for (int i = 1; i <= m; ++i) {
        vector<vector<int>> valid_combinations;
        for (const auto& k : l) {
            int ca = 0;
            for (int ii : k) {
                ca += c[ii][i];
            }
            if (ca >= x) {
                valid_combinations.push_back(k);
            }
        }
        l = valid_combinations; // Update l with valid combinations
        if (l.empty()) {
            cout << -1 << endl;
            return 0;
        }
    }

    // Find the minimum cost among the valid combinations
    for (const auto& i : l) {
        int ca = 0;
        for (int j : i) {
            ca += c[j][0];
        }
        ans = min(ans, ca);
    }

    cout << ans << endl;

    return 0;
}
// <END-OF-CODE>
