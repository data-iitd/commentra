

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

const int MOD = 100000007;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int Nsq = 1000;
    vector<vector<int>> fact(Nsq, vector<int>(Nsq));
    fact[0][0] = 1;
    for (int n = 1; n < Nsq; n++) {
        fact[0][n] = fact[0][n - 1] * n % MOD;
    }
    for (int n = 1; n < Nsq; n++) {
        fact[n][0] = fact[n - 1][0] * n % MOD;
    }
    for (int n = 1; n < Nsq; n++) {
        for (int m = 1; m < Nsq; m++) {
            fact[n][m] = fact[n - 1][m] * m % MOD;
        }
    }

    vector<int> inv(N);
    for (int i = 0; i < N; i++) {
        inv[i] = pow(i + 1, MOD - 2, MOD);
    }
    partial_sum(inv.begin(), inv.end(), inv.begin(), plus<int>());
    inv.erase(inv.begin());
    reverse(inv.begin(), inv.end());

    vector<int> temp(N);
    for (int j = 0; j < N; j++) {
        temp[j] = inv[j] + inv[N - 1 - j] - 1;
    }

    int ans = accumulate(A.begin(), A.end(), 0LL, [&](int sum, int a) {
        return (sum + (long long)a * temp[a - 1]) % MOD;
    });
    ans = (long long)ans * fact[N][N] % MOD;

    cout << ans << endl;

    return 0;
}

