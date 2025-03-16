
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    const int MOD = 1e9 + 7;
    const int Nsq = 1e3;

    vector<int> fact(Nsq * Nsq);
    fact[0] = 1;
    for (int n = 1; n < Nsq; n++) {
        for (int i = 0; i < Nsq; i++) {
            fact[n * Nsq + i] = fact[n * Nsq + i - 1] * n % MOD;
        }
    }

    for (int n = 1; n < Nsq; n++) {
        for (int i = 0; i < Nsq; i++) {
            fact[n * Nsq + i] = fact[n * Nsq + i] * fact[(n - 1) * Nsq + Nsq - 1] % MOD;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int temp = 0;
        for (int j = 0; j < N; j++) {
            temp += fact[j] * fact[N - 1 - j];
            temp %= MOD;
        }
        ans += A[i] * temp % MOD;
        ans %= MOD;
    }

    ans *= fact[N];
    ans %= MOD;

    cout << ans << "\n";

    return 0;
}

