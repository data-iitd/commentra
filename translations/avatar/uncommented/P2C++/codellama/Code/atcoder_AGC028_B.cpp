#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int M = 1000000;
    vector<vector<int>> fact(N * N, vector<int>(M));
    fact[0][0] = 1;
    for (int n = 1; n < N * N; n++) {
        for (int i = 0; i < M; i++) {
            fact[n][i] = (fact[n - 1][i] * i) % MOD;
        }
    }
    for (int n = 1; n < N * N; n++) {
        for (int i = 0; i < M; i++) {
            fact[n][i] = (fact[n][i] + fact[n - 1][i - 1]) % MOD;
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
    ans = (ans * fact[N * N - 1][0]) % MOD;
    cout << ans << endl;
    return 0;
}



