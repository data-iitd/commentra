

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

ll dp[3001][3001];

void solve(int A, int B, int C, int D) {
    dp[A][B] = 1;

    for (int c = A; c <= C; c++) {
        for (int d = B; d <= D; d++) {
            if (c == A && d == B) {
                continue;
            }

            ll ans = 0;

            if (c > A) {
                ll part = dp[c - 1][d];
                ans = (part * d) % MOD;
            }

            if (d > B) {
                ll part = dp[c][d - 1];
                ans = (ans + (part * c)) % MOD;
            }

            if (c > A && d > B) {
                ans = (ans - (dp[c - 1][d - 1] * (c - 1) * (d - 1)) % MOD + MOD) % MOD;
            }

            dp[c][d] = ans;
        }
    }

    cout << dp[C][D] << endl;
}

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    solve(A, B, C, D);
    return 0;
}

These comments should provide a clear understanding of the code for anyone who reads it.