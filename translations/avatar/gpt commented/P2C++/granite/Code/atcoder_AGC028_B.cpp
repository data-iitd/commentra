
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Define the modulo constant
const int MOD = 100000007;

// Read the integer input N
int N;
cin >> N;

// Define a constant for the maximum size
const int M = 1000000;

// Read the array A from input and convert it to a vector of int64 type
vector<int64_t> A(N);
for (int i = 0; i < N; i++) {
    cin >> A[i];
}

// Define the size for factorial calculations
const int Nsq = 1000;

// Initialize a 2D vector to store factorial values
vector<vector<int64_t>> fact(Nsq, vector<int64_t>(Nsq));

// Set the first factorial value
fact[0][0] = 1;

// Compute factorial values for columns
for (int n = 1; n < Nsq; n++) {
    fact[0][n] = fact[0][n - 1] * n % MOD;
}

// Compute factorial values for rows
for (int n = 1; n < Nsq; n++) {
    fact[n][0] = fact[n - 1][0] * n % MOD;
}

// Compute factorial values for the rest of the matrix
for (int n = 1; n < Nsq; n++) {
    for (int m = 1; m < Nsq; m++) {
        fact[n][m] = fact[n - 1][m] * m % MOD;
    }
}

// Create an array of indices from 0 to N-1
vector<int> j(N);
iota(j.begin(), j.end(), 0);

// Calculate modular inverses of numbers from 1 to N
vector<int64_t> inv(N);
for (int i = 0; i < N; i++) {
    inv[i] = pow(i + 1, MOD - 2, MOD);
}

// Compute cumulative sum of inverses and take modulo
partial_sum(inv.begin(), inv.end(), inv.begin(), [](int64_t a, int64_t b) { return (a + b) % MOD; });

// Calculate temporary values based on the cumulative inverses
vector<int64_t> temp(N);
transform(j.begin(), j.end(), inv.begin(), temp.begin(), [](int i, int64_t inv) { return (inv + inv[N - 1 - i] - 1) % MOD; });

// Compute the final answer by multiplying A with temp and summing the result
int64_t ans = accumulate(A.begin(), A.end(), 0LL, [&](int64_t a, int64_t b) { return (a + b * temp[j.size() - 1]) % MOD; });
ans = ans * fact[N][N] % MOD;

// Print the final answer
cout << ans << endl;

// End of code
