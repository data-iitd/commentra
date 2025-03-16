#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MOD = 998244353LL;

class Main {
public:
    vector<vector<ll>> dp;

    void solve(istream& is, ostream& os) {
        int A, B, C, D;
        is >> A >> B >> C >> D;

        dp.resize(3001, vector<ll>(3001, 0));

        dp[A][B] = 1;

        for (int c = A; c <= C; ++c) {
            for (int d = B; d <= D; ++d) {
                if (c == A && d == B) continue;

                ll ans = 0;

                if (c > A) {
                    ll part = dp[c - 1][d];
                    ans = (part * d) % MOD;
                }

                if (d > B) {
                    ll part = dp[c][d - 1];
                    ans = (ans + (part * c) % MOD) % MOD;
                }

                if (c > A && d > B) {
                    ans = (ans - (dp[c - 1][d - 1] * (c - 1) * (d - 1) % MOD) + MOD) % MOD;
                }

                dp[c][d] = (ans % MOD + MOD) % MOD;
            }
        }

        os << dp[C][D] << endl;
    }
};

int main() {
    Main m;
    m.solve(cin, cout);
    return 0;
}

