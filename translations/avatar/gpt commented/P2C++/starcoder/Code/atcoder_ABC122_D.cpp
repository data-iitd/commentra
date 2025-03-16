#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int mod = 1000000007;
    vector<map<string, int>> memo(n + 1);
    function<int(int, string)> dfs = [&](int cur, string last3) {
        if (memo[cur].count(last3)) {
            return memo[cur][last3];
        }
        if (cur == n) {
            return 1;
        }
        int ret = 0;
        for (char c = 'A'; c <= 'T'; c++) {
            if (ok(last3 + c)) {
                ret = (ret + dfs(cur + 1, last3[1:] + c)) % mod;
            }
        }
        memo[cur][last3] = ret;
        return ret;
    };
    cout << dfs(0, "TTT") << "\n";
}

