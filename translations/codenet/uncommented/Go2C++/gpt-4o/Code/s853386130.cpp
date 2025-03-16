#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <cmath>

using namespace std;

const int mod = 1000000007;
const int INF = 1000000007;

int min(int x, int y) {
    return x < y ? x : y;
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

vector<vector<int>> permutations(vector<int>& arr) {
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());
    do {
        res.push_back(arr);
    } while (next_permutation(arr.begin(), arr.end()));
    return res;
}

int main() {
    int n, m, R;
    cin >> n >> m >> R;

    vector<int> rs(R);
    for (int i = 0; i < R; i++) {
        cin >> rs[i];
        rs[i]--;
    }

    vector<vector<int>> costs(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        costs[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        costs[a][b] = c;
        costs[b][a] = c;
    }

    costs = floydWarshall(n, costs);

    auto perms = permutations(rs);
    int ans = INF;
    for (const auto& perm : perms) {
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
