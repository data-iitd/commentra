#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;  // Define the modulo constant
const int M = 1e6;        // Define a constant for the factorial table size
const int Nsq = 1e3;      // Define a constant for the size of the factorial table

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;  // Read the size of the array
    vector<int64_t> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];  // Read the array elements
    }

    // Initialize the factorial table
    vector<vector<int64_t>> fact(Nsq, vector<int64_t>(Nsq, 0));
    fact[0][0] = 1;

    // Compute the factorial table
    for (int n = 1; n < Nsq; ++n) {
        fact[0][n] = (fact[0][n - 1] * n) % MOD;  // Fill the first row
    }

    // Compute the factorial table row-wise
    for (int n = 1; n < Nsq; ++n) {
        for (int m = 0; m < Nsq; ++m) {
            fact[n][m] = (fact[n - 1][Nsq - 1] * fact[0][m]) % MOD;  // Fill the current row
        }
    }

    // Flatten the factorial table for efficient storage
    vector<int64_t> flat_fact(Nsq * Nsq);
    for (int i = 0; i < Nsq; ++i) {
        for (int j = 0; j < Nsq; ++j) {
            flat_fact[i * Nsq + j] = fact[i][j];
        }
    }

    // Compute the inverse factorial values
    vector<int64_t> inv(N);
    for (int i = 0; i < N; ++i) {
        inv[i] = pow(i + 1, MOD - 2, MOD);  // Compute modular inverse
    }

    // Compute the cumulative sum of inverses
    for (int i = 1; i < N; ++i) {
        inv[i] = (inv[i] + inv[i - 1]) % MOD;
    }

    // Compute the temporary value
    vector<int64_t> temp(N);
    for (int j = 0; j < N; ++j) {
        temp[j] = (inv[j] + inv[N - 1 - j] - 1 + MOD) % MOD;  // Ensure non-negative
    }

    // Compute the final answer
    int64_t ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = (ans + A[i] * temp[i]) % MOD;
    }

    // Multiply the final answer with the factorial of N
    ans = (ans * flat_fact[N]) % MOD;

    // Print the final answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
