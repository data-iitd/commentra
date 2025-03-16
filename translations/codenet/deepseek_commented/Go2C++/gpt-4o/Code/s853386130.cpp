#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// Constants for the modulo operation and infinity value
const int mod = 1000000007;
const int INF = 1000000007;

// Function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to generate all permutations of a given array
void permutations(vector<int>& arr, int n, vector<vector<int>>& res) {
    if (n == 1) {
        res.push_back(arr);
    } else {
        for (int i = 0; i < n; i++) {
            permutations(arr, n - 1, res);
            if (n % 2 == 1) {
                swap(arr[i], arr[n - 1]);
            } else {
                swap(arr[0], arr[n - 1]);
            }
        }
    }
}

int main() {
    // Read the number of cities, roads, and restaurants
    int n, m, R;
    cin >> n >> m >> R;

    // Read the indices of the restaurants and decrement by 1 for 0-based indexing
    vector<int> rs(R);
    for (int i = 0; i < R; i++) {
        cin >> rs[i];
        rs[i]--;
    }

    // Initialize the cost matrix with INF and set diagonal to 0
    vector<vector<int>> costs(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        costs[i][i] = 0;
    }

    // Read the road connections and their costs, updating the cost matrix
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        costs[a][b] = c;
        costs[b][a] = c;
    }

    // Use the Floyd-Warshall algorithm to compute the shortest paths between all pairs of cities
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
            }
        }
    }

    // Generate all permutations of the restaurant indices and find the minimum cost tour
    vector<vector<int>> permResults;
    permutations(rs, R, permResults);
    int ans = INF;
    for (const auto& perm : permResults) {
        int tmp = 0;
        for (size_t j = 1; j < perm.size(); j++) {
            int from = perm[j - 1];
            int to = perm[j];
            tmp += costs[from][to];
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
