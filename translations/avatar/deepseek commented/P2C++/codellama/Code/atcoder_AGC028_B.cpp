
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define MOD 1000000007

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int Nsq = 1000;
    vector<vector<int>> fact(Nsq, vector<int>(Nsq, 1));
    for (int n = 1; n < Nsq; n++) {
        for (int i = 0; i < Nsq; i++) {
            fact[i][n] = (fact[i][n - 1] * fact[i][n - 1]) % MOD;
        }
    }

    for (int n = 1; n < Nsq; n++) {
        for (int i = 0; i < Nsq; i++) {
            fact[n][i] = (fact[n][i] * fact[n - 1][Nsq - 1]) % MOD;
        }
    }

    vector<int> inv(N);
    for (int i = 0; i < N; i++) {
        inv[i] = pow(i + 1, MOD - 2, MOD);
    }
    vector<int> temp(N);
    for (int i = 0; i < N; i++) {
        temp[i] = (inv[i] + inv[N - 1 - i] - 1) % MOD;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = (ans + (A[i] * temp[i]) % MOD) % MOD;
    }
    ans = (ans * fact[N][Nsq - 1]) % MOD;

    cout << ans << endl;

    return 0;
}

