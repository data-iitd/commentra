#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll MOD = 998244353L;

class Main {
public:
    vector<vector<ll>> dp;

    // This method solves the problem using dynamic programming
    void solve(ll A, ll B, ll C, ll D) {
        // Initialize the dp array for the starting point (A, B)
        dp.resize(C + 1, vector<ll>(D + 1, 0));
        dp[A][B] = 1;

        // Iterate over the range from A to C and from B to D
        for (ll c = A; c <= C; c++) {
            for (ll d = B; d <= D; d++) {
                // Skip the starting point (A, B)
                if (c == A && d == B) {
                    continue;
                }

                // Calculate the answer based on previous states
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

                // Store the result in dp array
                dp[c][d] = ans;
            }
        }

        // Output the result for the final state (C, D)
        cout << dp[C][D] << endl;
    }
};

int main() {
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    Main obj;
    obj.solve(A, B, C, D);
    return 0;
}

