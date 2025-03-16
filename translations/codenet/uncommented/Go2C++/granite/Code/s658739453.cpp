
#include <iostream>
#include <map>

using namespace std;

const int d = 1000000007;

int main() {
    int n, p;
    cin >> n >> p;

    map<int64_t, int64_t> mdans;
    for (int index = 0; index < p; index++) {
        int64_t n1;
        cin >> n1;
        mdans[n1] = n1;
    }

    vector<int64_t> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    if (mdans.find(1)!= mdans.end()) {
        dp[1] = 0;
    }

    for (int i = 2; i <= n; i++) {
        if (mdans.find(i)!= mdans.end()) {
            continue;
        }
        dp[i] = (dp[i - 1] + dp[i - 2]) % d;
    }

    cout << dp[n] << endl;

    return 0;
}

