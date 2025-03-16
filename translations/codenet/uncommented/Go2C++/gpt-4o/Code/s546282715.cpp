#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_map<int, int> aa;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        aa[x] = 1;
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    const int MOD = 1000000007;

    for (int i = 0; i < n; i++) {
        for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
            if (aa.find(i + ii) != aa.end()) {
                continue;
            }
            dp[i + ii] = (dp[i + ii] + dp[i]) % MOD;
        }
    }

    cout << dp[n] << endl;

    return 0;
}

// <END-OF-CODE>
