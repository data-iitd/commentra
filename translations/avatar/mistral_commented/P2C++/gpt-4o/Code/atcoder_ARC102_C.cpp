#include <iostream>
#include <vector>
using namespace std;

// Define a constant for the modulus
const int mod = 998244353;

// Define a constant N for the size of the arrays
const int __N = 8000;

// Precompute factorials and their inverses
vector<long long> g1(__N + 1, 1), g2(__N + 1, 1), inverse(__N + 1, 0);

void precompute() {
    inverse[1] = 1;
    for (int i = 2; i <= __N; ++i) {
        g1[i] = g1[i - 1] * i % mod;
        inverse[i] = (-inverse[mod % i] * (mod / i)) % mod;
        g2[i] = g2[i - 1] * inverse[i] % mod;
    }
}

// Function to compute combinations
long long cmb(int n, int r) {
    if (r < 0 || r > n) return 0;
    r = min(r, n - r);
    return g1[n] * g2[r] % mod * g2[n - r] % mod;
}

// Function to compute the value of a combinatorial sum
long long kumiawase(int p, int q) {
    return cmb(p + q - 1, q - 1);
}

// Function to compute the answer for a given value of n
long long solve(int n, int K, int N) {
    if (n > K + 1) return 0;
    long long ans = 0;
    int kumi = (n - 1) / 2;
    for (int p = 0; p <= kumi; ++p) {
        if (p > N) break;
        ans += (1LL << p) * cmb(kumi, p) % mod * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0))) % mod;
        if (n % 2 == 0 && N - p - 1 >= 0) {
            ans += (1LL << p) * cmb(kumi, p) % mod * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0))) % mod;
        }
    }
    return ans % mod;
}

int main() {
    int K, N;
    cin >> K >> N;

    // Precompute values
    precompute();

    // Initialize an empty vector to store the answers
    vector<long long> ans;

    // Compute the answers for all integers from 2 to 2K+1
    for (int i = 2; i <= 2 * K; ++i) {
        long long tmp = solve(i, K, N);
        ans.push_back(tmp);
        cout << tmp << endl;
    }

    // Print the answers for the negative integers
    for (int i = 2; i <= 2 * K; ++i) {
        if (i <= K + 1) {
            cout << ans[i - K - 1] << endl;
        } else {
            cout << ans[ans.size() - i + K] << endl;
        }
    }

    return 0;
}

// <END-OF-CODE>
