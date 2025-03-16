
// Importing necessary packages
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Global variables initialization
const int mod = 1000000007;
const int INF = 1000000007;

int main() {
    // Reading input from standard input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, R;
    cin >> n >> m >> R;

    // Variables initialization
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
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]); // Updating costs[i][j] with minimum of current value and costs[i][k] + costs[k][j]
            }
        }
    }

    // Calculating minimum cost of visiting all cities in a single tour
    vector<vector<int>> perms = permutations(rs); // Generating all permutations of starting points
    int ans = INF; // Initializing answer with infinite value
    for (auto perm : perms) { // Iterating through all permutations
        int tmp = 0; // Initializing temporary variable tmp with zero value
        for (int j = 1; j < perm.size(); j++) { // Iterating through all pairs of consecutive starting points
            int from = perm[j-1]; // Getting previous starting point
            int to = perm[j]; // Getting current starting point
            tmp += costs[from][to]; // Adding cost of road from from to to tmp
        }
        ans = min(ans, tmp); // Updating answer with minimum of current answer and tmp
    }
    cout << ans << endl; // Printing answer
    return 0;
}

// Helper function to generate all permutations of given slice
vector<vector<int>> permutations(vector<int> arr) {
    // Helper function initialization
    vector<vector<int>> res;
    function<void(vector<int>, int)> helper = [&](vector<int> arr, int n) {
        if (n == 1) { // Base case: when only one element left in arr
            vector<int> tmp(arr); // Copying arr to tmp for returning
            res.push_back(tmp); // Adding tmp to result
            return;
        }

        for (int i = 0; i < n; i++) { // Iterating through all elements of arr
            helper(arr, n-1); // Recursively calling helper function with n-1
            if (n%2 == 1) { // Swapping first and last elements when n is odd
                swap(arr[i], arr[n-1]);
            } else { // Swapping first and last elements when n is even
                swap(arr[0], arr[n-1]);
            }
        }
    };
    helper(arr, arr.size()); // Calling helper function with arr and its length
    return res;
}

