#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 998244353LL;

class Main {
public:
    void solve(istream &in, ostream &out) {
        int A, B, C, D;
        in >> A >> B >> C >> D;

        vector<vector<long long>> dp(3001, vector<long long>(3001, 0));
        dp[A][B] = 1;

        for (int c = A; c <= C; c++) {
            for (int d = B; d <= D; d++) {
                if (c == A && d == B) {
                    continue;
                }
                long long ans = 0;
                if (c > A) {
                    long long part = dp[c - 1][d];
                    ans = (part * d) % MOD;
                }
                if (d > B) {
                    long long part = dp[c][d - 1];
                    ans = (ans + (part * c) % MOD) % MOD;
                }
                if (c > A && d > B) {
                    ans = (ans - (dp[c - 1][d - 1] * (c - 1) % MOD * (d - 1) % MOD) + MOD) % MOD;
                }
                dp[c][d] = (ans + MOD) % MOD;
            }
        }
        out << dp[C][D] << endl;
    }
};

int main() {
    Main main;
    main.solve(cin, cout);
    return 0;
}

// <END-OF-CODE>
