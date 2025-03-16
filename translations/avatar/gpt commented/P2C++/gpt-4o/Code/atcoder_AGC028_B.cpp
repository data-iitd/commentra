#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

const int MOD = 1e9 + 7;
const int Nsq = 1000;
const int M = 1e6;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Read the integer input N
    int N;
    std::cin >> N;

    // Read the array A from input
    std::vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Initialize a 2D array to store factorial values
    std::vector<std::vector<long long>> fact(Nsq, std::vector<long long>(Nsq, 0));
    fact[0][0] = 1;

    // Compute factorial values for columns
    for (int n = 1; n < Nsq; ++n) {
        fact[0][n] = (fact[0][n - 1] * n) % MOD;  // Fill the first row
    }

    // Compute factorial values for rows
    for (int n = 1; n < Nsq; ++n) {
        fact[n][0] = (fact[n - 1][0] * n) % MOD;  // Fill the first column
        for (int m = 1; m < Nsq; ++m) {
            fact[n][m] = (fact[n][m - 1] * fact[n - 1][m]) % MOD;  // Fill the rest
        }
    }

    // Flatten the factorial array to 1D
    std::vector<long long> flat_fact(Nsq * Nsq);
    for (int i = 0; i < Nsq; ++i) {
        for (int j = 0; j < Nsq; ++j) {
            flat_fact[i * Nsq + j] = fact[i][j];
        }
    }

    // Create an array of indices from 0 to N-1
    std::vector<int> j(N);
    std::iota(j.begin(), j.end(), 0);

    // Calculate modular inverses of numbers from 1 to N
    std::vector<long long> inv(N);
    for (int i = 0; i < N; ++i) {
        inv[i] = pow(i + 1, MOD - 2, MOD);  // Modular inverse
    }

    // Compute cumulative sum of inverses and take modulo
    for (int i = 1; i < N; ++i) {
        inv[i] = (inv[i] + inv[i - 1]) % MOD;
    }

    // Calculate temporary values based on the cumulative inverses
    std::vector<long long> temp(N);
    for (int i = 0; i < N; ++i) {
        temp[i] = (inv[i] + inv[N - 1 - i] - 1 + MOD) % MOD;  // Ensure non-negative
    }

    // Compute the final answer by multiplying A with temp and summing the result
    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = (ans + A[i] * temp[i]) % MOD;
    }

    // Multiply the answer by the factorial of N and take modulo
    ans = (ans * flat_fact[N]) % MOD;

    // Print the final answer
    std::cout << ans << "\n";

    return 0;
}

// <END-OF-CODE>
