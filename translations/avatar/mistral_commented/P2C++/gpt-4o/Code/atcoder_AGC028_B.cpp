#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

// Define constant value
const int MOD = 1e9 + 7;
const int M = 1e6;
const int Nsq = 1e3;

int main() {
    // Read input number of elements N
    int N;
    cin >> N;

    // Initialize vector A with given size and input data
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Initialize 2D vector fact with given size and initial value 1
    vector<vector<long long>> fact(Nsq, vector<long long>(Nsq, 1));
    
    // Calculate factorial for each cell in the 2D vector fact using a loop
    for (int n = 1; n < Nsq; ++n) {
        for (int i = 0; i < Nsq; ++i) {
            fact[i][n] = (fact[i][n - 1] * (n + 1)) % MOD; // Multiply current row with previous row
        }
    }

    // Transpose the 2D vector fact and calculate factorial for each cell in the new rows
    for (int n = 1; n < Nsq; ++n) {
        for (int i = 0; i < Nsq; ++i) {
            fact[n][i] = (fact[n - 1][Nsq - 1] * fact[n][i]) % MOD; // Multiply current row with last cell of previous row
        }
    }

    // Flatten the 2D vector fact into a 1D vector
    vector<long long> flat_fact(Nsq * Nsq);
    for (int i = 0; i < Nsq; ++i) {
        for (int j = 0; j < Nsq; ++j) {
            flat_fact[i * Nsq + j] = fact[i][j];
        }
    }

    // Initialize vector j with given size
    vector<int> j(N);
    iota(j.begin(), j.end(), 0); // Fill j with 0, 1, ..., N-1

    // Calculate the inverse of each element in the array inv
    vector<long long> inv(N);
    for (int i = 0; i < N; ++i) {
        inv[i] = pow(i + 1, MOD - 2) % MOD; // Modular inverse using Fermat's little theorem
    }

    // Calculate cumulative sum of the array inv
    for (int i = 1; i < N; ++i) {
        inv[i] = (inv[i] + inv[i - 1]) % MOD;
    }

    // Calculate temporary array temp using elements from j and inv
    vector<long long> temp(N);
    for (int i = 0; i < N; ++i) {
        temp[i] = (inv[j[i]] + inv[N - 1 - j[i]] - 1 + MOD) % MOD; // Ensure non-negative
    }

    // Calculate the answer ans using given formula
    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = (ans + A[i] * temp[i]) % MOD;
    }

    // Multiply the answer ans with the last element of flat_fact array
    ans = (ans * flat_fact[N]) % MOD;

    // Print the answer ans
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
