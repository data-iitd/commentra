#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int MOD = 1000000007;
const int INF = INT_MAX;

int main() {
    // Reading input from standard input
    int n, m, R;
    cin >> n >> m >> R;

    // Initializing rs vector with starting points
    vector<int> rs(R);
    for (int i = 0; i < R; i++) {
        cin >> rs[i];
        rs[i]--; // Decreasing starting point index for matrix indexing
    }

    // Initializing costs matrix with infinite values
    vector<vector<int>> costs(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        costs[i][i] = 0; // Initializing costs[i][i] with zero value
    }

    // Reading roads and filling costs matrix with their costs
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; // Decreasing starting point index for matrix indexing
        b--; // Decreasing ending point index for matrix indexing
        costs[a][b] = c; // Filling costs[a][b] with cost c
        costs[b][a] = c; // Filling costs[b][a] with cost c
    }

    // Applying Warshall-Floyd algorithm to find shortest paths between all pairs of cities
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (costs[i][k] != INF && costs[k][j] != INF) {
                    costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]); // Updating costs[i][j] with minimum of current value and costs[i][k] + costs[k][j]
                }
            }
        }
    }

    // Calculating minimum cost of visiting all cities in a single tour
    vector<vector<int>> perms = permutations(rs); // Generating all permutations of starting points
    int ans = INF; // Initializing answer with infinite value
    for (const auto& perm : perms) { // Iterating through all permutations
        int tmp = 0; // Initializing temporary variable tmp with zero value
        for (size_t j = 1; j < perm.size(); j++) { // Iterating through all pairs of consecutive starting points
            int from = perm[j-1]; // Getting previous starting point
            int to = perm[j]; // Getting current starting point
            tmp += costs[from][to]; // Adding cost of road from from to to tmp
        }
        ans = min(ans, tmp); // Updating answer with minimum of current answer and tmp
    }
    cout << ans << endl; // Printing answer
}

// Helper function to generate all permutations of given vector
vector<vector<int>> permutations(const vector<int>& arr) {
    vector<vector<int>> res;
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    do {
        res.push_back(temp);
    } while (next_permutation(temp.begin(), temp.end()));
    return res;
}
