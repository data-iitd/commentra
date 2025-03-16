#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int MOD = 1000000007;
const int INF = 1000000007;

vector<vector<int>> permutations(vector<int>& arr) {
    vector<vector<int>> res;
    function<void(vector<int>&, int)> helper = [&](vector<int>& arr, int n) {
        if (n == 1) {
            res.push_back(arr);
        } else {
            helper(arr, n - 1);
            for (int i = 0; i < n - 1; i++) {
                if (n % 2 == 1) {
                    swap(arr[i], arr[n - 1]);
                } else {
                    swap(arr[0], arr[n - 1]);
                }
                helper(arr, n - 1);
            }
        }
    };
    helper(arr, arr.size());
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
        a--;
        b--;
        costs[a][b] = c;
        costs[b][a] = c;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
            }
        }
    }

    vector<vector<int>> perms = permutations(rs);
    int ans = INF;
    for (const auto& perm : perms) {
        int tmp = 0;
        for (int j = 1; j < perm.size(); j++) {
            int from = perm[j - 1];
            int to = perm[j];
            tmp += costs[from][to];
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}
