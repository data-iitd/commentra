#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int mod = 998244353;
const int N = 8000;
int g1[N + 1], g2[N + 1], inverse[N + 1];
int cmb(int n, int r, int mod) {
    if (r < 0 || r > n) return 0;
    r = min(r, n - r);
    return g1[n] * g2[r] * g2[n - r] % mod;
}
int kumiawase(int p, int q) {
    return cmb(p + q - 1, q - 1, mod);
}
int solve(int n) {
    int ans = 0;
    int kumi = (n - 1) / 2;
    for (int p = kumi + 1; p <= N; p++) {
        ans += 2 * pow(2, p) * cmb(kumi, p, mod) * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0)));
        if (n % 2 == 0 && N - p - 1 >= 0) {
            ans += 2 * pow(2, p) * cmb(kumi, p, mod) * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0)));
        }
    }
    return ans;
}
int main() {
    int K, N;
    cin >> K >> N;
    g1[0] = g1[1] = 1;
    g2[0] = g2[1] = 1;
    inverse[0] = inverse[1] = 1;
    for (int i = 2; i <= N; i++) {
        g1[i] = (g1[i - 1] * i) % mod;
        inverse[i] = (-inverse[mod % i] * (mod / i)) % mod;
        g2[i] = (g2[i - 1] * inverse[i - 1]) % mod;
    }
    int ans[2 * K + 1];
    for (int i = 2; i <= 2 * K + 1; i++) {
        if (i <= K + 1) {
            ans[i] = solve(i) % 998244353;
            cout << ans[i] << endl;
        } else {
            cout << ans[2 * K + 1 - i] << endl;
        }
    }
    return 0;
}



