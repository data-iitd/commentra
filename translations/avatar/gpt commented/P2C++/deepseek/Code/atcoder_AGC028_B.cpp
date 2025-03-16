#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;
const int M = 1000000;
const int Nsq = 1000;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> fact(M);
    iota(fact.begin(), fact.end(), 0);

    for (int n = 1; n < Nsq; ++n) {
        for (int i = 0; i < Nsq; ++i) {
            fact[n * Nsq + i] = (long long)fact[n * Nsq + i - 1] * fact[(n - 1) * Nsq + i] % MOD;
        }
    }

    for (int n = 1; n < Nsq; ++n) {
        for (int i = 0; i < Nsq; ++i) {
            fact[n * Nsq + i] = (long long)fact[n * Nsq + i] * fact[(n - 1) * Nsq + i] % MOD;
        }
    }

    vector<int> inv(N);
    inv[0] = 1;
    for (int i = 1; i < N; ++i) {
        inv[i] = (long long)inv[i - 1] * pow(i + 1, MOD - 2, MOD) % MOD;
    }

    vector<int> temp(N);
    partial_sum(inv.begin(), inv.end(), temp.begin(), [](int a, int b) { return (a + b) % MOD; });

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = (ans + (long long)A[i] * (temp[i] + temp[N - 1 - i] - 1) % MOD) % MOD;
    }

    ans = (long long)ans * fact[N] % MOD;

    cout << ans << endl;

    return 0;
}
