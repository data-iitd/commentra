#include <bits/stdc++.h>
using namespace std;

// Define the modulo constant
const int MOD = 1000000007;

// Read the integer input N
int N;
cin >> N;

// Define a constant for the maximum size
const int M = 1000001;

// Read the array A from input and convert it to a vector of int64 type
vector<int64_t> A(N);
for (int i = 0; i < N; i++) {
    cin >> A[i];
}

// Define the size for factorial calculations
const int Nsq = 1001;

// Initialize a 2D array to store factorial values
vector<vector<int64_t>> fact(Nsq, vector<int64_t>(Nsq));

// Set the first factorial value
fact[0][0] = 1;

// Compute factorial values for columns
for (int n = 1; n < Nsq; n++) {
    for (int i = 0; i < Nsq; i++) {
        fact[i][n] = fact[i][n - 1] * fact[i][n - 1] % MOD;
    }
}

// Compute factorial values for rows
for (int n = 1; n < Nsq; n++) {
    for (int i = 0; i < Nsq; i++) {
        fact[n][i] = fact[n - 1][i] * fact[n - 1][i] % MOD;
    }
}

// Flatten the factorial array to 1D
vector<int64_t> fact_1d(Nsq * Nsq);
for (int i = 0; i < Nsq; i++) {
    for (int j = 0; j < Nsq; j++) {
        fact_1d[i * Nsq + j] = fact[i][j];
    }
}

// Create an array of indices from 0 to N-1
vector<int> j(N);
for (int i = 0; i < N; i++) {
    j[i] = i;
}

// Calculate modular inverses of numbers from 1 to N
vector<int64_t> inv(N);
for (int i = 0; i < N; i++) {
    inv[i] = pow(i + 1, MOD - 2, MOD);
}

// Compute cumulative sum of inverses and take modulo
inv = accumulate(inv.begin(), inv.end(), 0);
inv = vector<int64_t>(inv.begin(), inv.end() - 1);
for (int i = 0; i < N; i++) {
    inv[i] %= MOD;
}

// Calculate temporary values based on the cumulative inverses
vector<int64_t> temp(N);
for (int i = 0; i < N; i++) {
    temp[i] = inv[i] + inv[N - 1 - i] - 1;
}

// Compute the final answer by multiplying A with temp and summing the result
int64_t ans = 0;
for (int i = 0; i < N; i++) {
    ans += A[i] * temp[i] % MOD;
    ans %= MOD;
}

// Multiply the answer by the factorial of N and take modulo
ans *= fact_1d[N];
ans %= MOD;

// Print the final answer
cout << ans << endl;

// 