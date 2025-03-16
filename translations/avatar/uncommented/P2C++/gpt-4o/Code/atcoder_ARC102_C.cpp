#include <iostream>
#include <vector>
using namespace std;

const int mod = 998244353;
const int __N = 8000;

vector<long long> g1(__N + 1, 1);
vector<long long> g2(__N + 1, 1);
vector<long long> inverse(__N + 1, 0);

void precompute() {
    inverse[1] = 1;
    for (int i = 2; i <= __N; ++i) {
        g1[i] = g1[i - 1] * i % mod;
        inverse[i] = (-inverse[mod % i] * (mod / i)) % mod;
        if (inverse[i] < 0) inverse[i] += mod;
        g2[i] = g2[i - 1] * inverse[i] % mod;
    }
}

long long cmb(int n, int r) {
    if (r < 0 || r > n) return 0;
    r = min(r, n - r);
    return g1[n] * g2[r] % mod * g2[n - r] % mod;
}

long long kumiawase(int p, int q) {
    return cmb(p + q - 1, q - 1);
}

long long solve(int n, int K) {
    if (n > K + 1) return 0;
    long long ans = 0;
    int kumi = (n - 1) / 2;
    for (int p = 0; p <= kumi; ++p) {
        if (p > __N) break;
        ans += (1LL << p) * cmb(kumi, p) % mod * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0))) % mod;
        if (n % 2 == 0 && N - p - 1 >= 0) {
            ans += (1LL << p) * cmb(kumi, p) % mod * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0))) % mod;
        }
        ans %= mod;
    }
    return ans;
}

int main() {
    int K, N;
    cin >> K >> N;
    precompute();
    
    vector<long long> ans;
    for (int i = 2; i <= 2 * K; ++i) {
        if (i <= K + 1) {
            long long tmp = solve(i, K) % mod;
            ans.push_back(tmp);
            cout << tmp << endl;
        } else {
            cout << ans[K - (i - K)] << endl;
        }
    }
    return 0;
}

// <END-OF-CODE>
