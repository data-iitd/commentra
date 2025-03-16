#include <bits/stdc++.h>
using namespace std;

#define dprint(...)

#define MOD 998244353
#define N 8000

int g1[N + 1];
int g2[N + 1];
int inverse[N + 1];

void precompute() {
    g1[0] = 1;
    g2[0] = 1;
    inverse[1] = 1;
    for (int i = 2; i <= N; i++) {
        g1[i] = (g1[i - 1] * i) % MOD;
        inverse[i] = (-inverse[MOD % i] * (MOD / i)) % MOD;
        g2[i] = (g2[i - 1] * inverse[i]) % MOD;
    }
}

int cmb(int n, int r) {
    if (r < 0 || r > n)
        return 0;
    r = min(r, n - r);
    return g1[n] * g2[r] * g2[n - r] % MOD;
}

int kumiawase(int p, int q) {
    return cmb(p + q - 1, q - 1);
}

int solve(int n) {
    int ans = 0;
    int kumi = (n - 1) / 2;
    for (int p = 0; p <= kumi; p++) {
        if (p > N)
            break;
        ans += 1LL * (1 << p) * cmb(kumi, p) * kumiawase(N - p, p + (K - kumi * 2 - (n & 1)));
        if (n & 1 && N - p - 1 >= 0)
            ans += 1LL * (1 << p) * cmb(kumi, p) * kumiawase(N - p - 1, p + (K - kumi * 2 - (n & 1)));
    }
    return ans % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << solve(n) << "\n";
    }
    return 0;
}

