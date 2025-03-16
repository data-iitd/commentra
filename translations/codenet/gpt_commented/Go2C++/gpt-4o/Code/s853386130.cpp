#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <queue>
#include <functional>

using namespace std;

const int mod = 1000000007;
const int INF = 1000000007;

int min(int x, int y) {
    return (x < y) ? x : y;
}

vector<vector<int>> floydWarshall(int n, const vector<vector<int>>& costs) {
    vector<vector<int>> dist = costs;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return dist;
}

void generatePermutations(vector<int>& arr, vector<vector<int>>& result, int start) {
    if (start == arr.size() - 1) {
        result.push_back(arr);
        return;
    }
    for (int i = start; i < arr.size(); i++) {
        swap(arr[start], arr[i]);
        generatePermutations(arr, result, start + 1);
        swap(arr[start], arr[i]); // backtrack
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, R;
    cin >> n >> m >> R;

    vector<int> rs(R);
    for (int i = 0; i < R; i++) {
        cin >> rs[i];
        rs[i]--; // Adjust for 0-based indexing
    }

    vector<vector<int>> costs(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        costs[i][i] = 0; // The cost to reach itself is 0
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--; // Adjust for 0-based indexing
        costs[a][b] = c; // Set cost for edge a to b
        costs[b][a] = c; // Set cost for edge b to a (undirected graph)
    }

    costs = floydWarshall(n, costs);

    vector<vector<int>> perms;
    generatePermutations(rs, perms, 0);
    int ans = INF;

    for (const auto& perm : perms) {
        int tmp = 0;
        for (size_t j = 1; j < perm.size(); j++) {
            int from = perm[j - 1];
            int to = perm[j];
            tmp += costs[from][to]; // Accumulate the cost of the current permutation
        }
        ans = min(ans, tmp); // Update the answer with the minimum cost found
    }

    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
