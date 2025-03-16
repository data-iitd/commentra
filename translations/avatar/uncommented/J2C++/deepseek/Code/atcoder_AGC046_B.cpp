#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include <queue>
#include <map>
#include <cstdio>
#include <iomanip>
#include <bitset>
#include <numeric>
#include <cstring>
#include <functional>
#include <chrono>
#include <cassert>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 998244353LL;
const int MAXN = 3001;
ll dp[MAXN][MAXN];

void solve(istream& is, ostream& os) {
    int A, B, C, D;
    is >> A >> B >> C >> D;
    dp[A][B] = 1;
    for (int c = A; c <= C; ++c) {
        for (int d = B; d <= D; ++d) {
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
                ans = (ans + (part * c) % MOD) % MOD;
            }
            if (c > A && d > B) {
                ans = (ans - (dp[c - 1][d - 1] * (c - 1) % MOD * (d - 1) % MOD) % MOD + MOD) % MOD;
            }
            dp[c][d] = (ans % MOD + MOD) % MOD;
        }
    }
    os << dp[C][D] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve(cin, cout);
    return 0;
}

