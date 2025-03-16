#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

const long long MOD = 1000000007;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    std::vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    const int Nsq = 1000;
    const int M = 1000000;
    std::vector<long long> fact(Nsq * Nsq, 0);
    fact[0] = 1;
    for (int n = 1; n < Nsq; ++n) {
        for (int m = 0; m < Nsq; ++m) {
            fact[n * Nsq + m] = fact[n * Nsq + (m - 1)];
            fact[n * Nsq + m] = (fact[n * Nsq + m] * fact[(n - 1) * Nsq + m]) % MOD;
        }
    }
    for (int n = 1; n < Nsq; ++n) {
        for (int m = 0; m < Nsq; ++m) {
            fact[n * Nsq + m] = (fact[n * Nsq + m] * fact[(n - 1) * Nsq + m]) % MOD;
        }
    }

    std::vector<long long> inv(N);
    inv[0] = 1;
    for (int i = 1; i < N; ++i) {
        inv[i] = pow(i + 1, MOD - 2, MOD);
    }
    std::vector<long long> inv_cumsum(N);
    std::partial_sum(inv.begin(), inv.end(), inv_cumsum.begin(), [](long long a, long long b) { return (a + b) % MOD; });

    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        long long temp = (inv_cumsum[i] + inv_cumsum[N - 1 - i] - 1) % MOD;
        ans = (ans + A[i] * temp) % MOD;
    }

    ans = (ans * fact[N]) % MOD;
    std::cout << ans << '\n';

    return 0;
}
