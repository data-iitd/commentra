#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <cstring>

using namespace std;

const int MOD = 1000000007;
const int INF = 1000000007;

int main() {
    // Initialize a buffered reader to read input
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, R;
    cin >> n >> m >> R;

    // Read the required nodes and adjust for 0-based indexing
    vector<int> rs(R);
    for (int i = 0; i < R; i++) {
        cin >> rs[i];
        rs[i]--;
    }

    // Initialize the cost matrix with INF values
    vector<vector<int>> costs(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        costs[i][i] = 0; // The cost to reach itself is 0
    }

    // Read the edges and their costs
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        costs[a][b] = c; // Set cost for edge a to b
        costs[b][a] = c; // Set cost for edge b to a (undirected graph)
    }

    // Calculate the shortest paths using the Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
            }
        }
    }

    // Generate all permutations of the required nodes
    sort(rs.begin(), rs.end());
    int ans = INF;

    // Evaluate each permutation to find the minimum cost path
    do {
        int tmp = 0;
        for (int j = 1; j < R; j++) {
            tmp += costs[rs[j - 1]][rs[j]]; // Accumulate the cost of the current permutation
        }
        ans = min(ans, tmp); // Update the answer with the minimum cost found
    } while (next_permutation(rs.begin(), rs.end()));

    // Output the minimum cost
    cout << ans << endl;

    return 0;
}
