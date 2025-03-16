#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

const ll mod = 998244353;
const int __N = 8000;

vector<ll> g1 = {1, 1};
vector<ll> g2 = {1, 1};
vector<ll> inverse = {0, 1};

// Combination function to calculate binomial coefficient modulo mod
ll cmb(int n, int r, ll mod) {
    if (r < 0 || r > n) {
        return 0;
    }
    r = min(r, n - r);
    return g1[n] * g2[r] % mod * g2[n - r] % mod;
}

// Function to calculate kumiawase (combination with repetition) modulo mod
ll kumiawase(int p, int q) {
    return cmb(p + q - 1, q - 1, mod);
}

// Function to solve the problem for a given n
ll solve(int n) {
    assert(n <= K + 1);
    ll ans = 0;
    int kumi = (n - 1) / 2;
    for (int p = 0; p <= kumi; ++p) {
        if (p > N) {
            break;
        }
        ans += (1LL << p) * cmb(kumi, p, mod) % mod * kumiawase(N - p, p + (K - kumi * 2 - int(n % 2 == 0))) % mod;
        ans %= mod;
        if (n % 2 == 0 && N - p - 1 >= 0) {
            ans += (1LL << p) * cmb(kumi, p, mod) % mod * kumiawase(N - p - 1, p + (K - kumi * 2 - int(n % 2 == 0))) % mod;
            ans %= mod;
        }
    }
    return ans;
}

int main() {
    int K, N;
    cin >> K >> N;

    // Precompute factorials, inverses, and modular inverses up to __N
    for (int i = 2; i <= __N; ++i) {
        g1.push_back(g1.back() * i % mod);
        inverse.push_back((-inverse[mod % i] * (mod / i)) % mod);
        g2.push_back(g2.back() * inverse.back() % mod);
    }

    vector<ll> ans;
    for (int i = 2; i <= 2 * K; ++i) {
        if (i <= K + 1) {
            ll tmp = solve(i) % mod;
            ans.push_back(tmp);
            cout << tmp << endl;
        } else {
            cout << ans[ans.size() - i + K] << endl;
        }
    }

    return 0;
}
