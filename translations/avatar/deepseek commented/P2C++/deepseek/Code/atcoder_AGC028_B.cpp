#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const long long MOD = 1000000007;  // Define the modulo constant

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;  // Read the size of the array

    const int M = 1000000;  // Define a constant for the factorial table size
    const int Nsq = 1000;  // Define a constant for the size of the factorial table

    vector<long long> A(N);  // Read the array elements
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Initialize the factorial table
    vector<long long> fact(Nsq * Nsq, 0);
    iota(fact.begin(), fact.end(), 0);
    fact[0] = 1;

    // Compute the factorial table
    for (int n = 1; n < Nsq; ++n) {
        for (int m = 0; m < Nsq; ++m) {
            fact[n * Nsq + m] *= fact[m + (n - 1) * Nsq];  // Multiply current column with the previous column
            fact[n * Nsq + m] %= MOD;  // Take modulo MOD
        }
        for (int m = 0; m < Nsq; ++m) {
            fact[n * Nsq + m] *= fact[(n - 1) * Nsq + Nsq - 1];  // Multiply current row with the last element of the previous row
            fact[n * Nsq + m] %= MOD;  // Take modulo MOD
        }
    }

    // Compute the inverse factorial values
    vector<long long> inv(N, 0);
    inv[0] = 1;
    for (int i = 1; i < N; ++i) {
        inv[i] = pow(i + 1, MOD - 2, MOD);
    }
    partial_sum(inv.begin(), inv.end(), inv.begin(), [](long long a, long long b) { return (a + b) % MOD; });

    // Compute the temporary value
    vector<long long> temp(N, 0);
    for (int i = 0; i < N; ++i) {
        temp[i] = inv[i] + inv[N - 1 - i] - 1;
        temp[i] = (temp[i] % MOD + MOD) % MOD;
    }

    // Compute the final answer
    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += A[i] * temp[i] % MOD;
        ans %= MOD;
    }

    // Multiply the final answer with the factorial of N
    ans *= fact[N - 1];
    ans %= MOD;

    // Print the final answer
    cout << ans << '\n';

    return 0;
}
