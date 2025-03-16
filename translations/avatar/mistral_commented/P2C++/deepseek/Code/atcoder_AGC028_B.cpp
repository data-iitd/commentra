#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const long long MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    const int M = 1000000;
    const int Nsq = 1000;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<vector<long long>> fact(Nsq, vector<long long>(Nsq, 0));
    iota(fact[0].begin(), fact[0].end(), 1);

    for (int n = 1; n < Nsq; ++n) {
        for (int m = 0; m < Nsq; ++m) {
            fact[n][m] = (fact[n - 1][m] * fact[n][m - 1]) % MOD;
        }
    }

    vector<long long> fact_flat(N * Nsq * Nsq);
    for (int i = 0; i < Nsq; ++i) {
        for (int j = 0; j < Nsq; ++j) {
            fact_flat[i * Nsq + j] = fact[i][j];
        }
    }

    vector<long long> j(N);
    iota(j.begin(), j.end(), 0);

    vector<long long> inv(N);
    inv[0] = 1;
    for (int i = 1; i < N; ++i) {
        inv[i] = pow(i + 1, MOD - 2, MOD);
    }

    vector<long long> inv_cumsum(N);
    inv_cumsum[0] = inv[0];
    for (int i = 1; i < N; ++i) {
        inv_cumsum[i] = (inv_cumsum[i - 1] + inv[i]) % MOD;
    }

    vector<long long> temp(N);
    for (int i = 0; i < N; ++i) {
        temp[i] = (inv_cumsum[i] + inv_cumsum[N - 1 - i] - 1) % MOD;
    }

    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = (ans + A[i] * temp[i] % MOD) % MOD;
    }

    ans = (ans * fact_flat[N]) % MOD;

    cout << ans << '\n';

    return 0;
}
