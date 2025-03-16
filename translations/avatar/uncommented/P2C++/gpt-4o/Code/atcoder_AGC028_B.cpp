#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

const int MOD = 1e9 + 7;
const int M = 1e6;
const int Nsq = 1000;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    std::vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    std::vector<long long> fact(Nsq * Nsq, 1);
    for (int n = 1; n < Nsq; ++n) {
        for (int k = 0; k < Nsq; ++k) {
            fact[k * Nsq + n] = (fact[k * Nsq + n - 1] * fact[k * Nsq + n]) % MOD;
        }
    }
    for (int n = 1; n < Nsq; ++n) {
        for (int k = 0; k < Nsq; ++k) {
            fact[n * Nsq + k] = (fact[(n - 1) * Nsq + k] * fact[n * Nsq + k]) % MOD;
        }
    }

    std::vector<long long> inv(N);
    for (int i = 0; i < N; ++i) {
        inv[i] = pow(i + 1, MOD - 2) % MOD;
    }
    std::vector<long long> cumsum(N);
    std::partial_sum(inv.begin(), inv.end(), cumsum.begin());
    std::vector<long long> temp(N);
    for (int j = 0; j < N; ++j) {
        temp[j] = (cumsum[j] + cumsum[N - 1 - j] - 1) % MOD;
    }

    long long ans = 0;
    for (int j = 0; j < N; ++j) {
        ans = (ans + A[j] * temp[j]) % MOD;
    }
    ans = (ans * fact[N]) % MOD;

    std::cout << ans << '\n';
    return 0;
}

// <END-OF-CODE>
