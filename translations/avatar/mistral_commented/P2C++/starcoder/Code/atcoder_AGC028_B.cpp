#include <bits/stdc++.h>
using namespace std;

// Define constant value
const int MOD = 1000000007;

// Read input number of elements N
int N;
cin >> N;

// Define a constant value for the size of the 2D array A
const int M = 1000001;

// Initialize 2D array A with given size and input data
int A[M];
for (int i = 0; i < N; i++) {
    cin >> A[i];
}

// Define a constant value for the size of the 2D array fact
const int Nsq = 1001;

// Initialize 2D array fact with given size and initial value 1
int fact[Nsq][Nsq];
for (int i = 0; i < Nsq; i++) {
    fact[i][0] = 1;
}

// Calculate factorial for each cell in the 2D array fact using a loop
for (int n = 1; n < Nsq; n++) {
    for (int i = 0; i < n; i++) {
        fact[n][i] = fact[n - 1][i] * fact[n][n - 1 - i];
        fact[n][i] %= MOD;
    }
}

// Calculate the inverse of each element in the array inv using a list comprehension
int inv[N];
for (int i = 0; i < N; i++) {
    inv[i] = pow(i + 1, MOD - 2, MOD);
}

// Calculate cumulative sum of the array inv
for (int i = 1; i < N; i++) {
    inv[i] += inv[i - 1];
    inv[i] %= MOD;
}

// Calculate temporary array temp using elements from j and inv
int temp[N];
for (int i = 0; i < N; i++) {
    temp[i] = inv[i] + inv[N - 1 - i] - 1;
}

// Calculate the answer ans using given formula
int ans = 0;
for (int i = 0; i < N; i++) {
    ans += A[i] * temp[i];
    ans %= MOD;
}

// Multiply the answer ans with the last element of fact array
ans *= fact[N][N - 1];

// Modulo the answer ans with given constant value MOD
ans %= MOD;

// Print the answer ans
cout << ans << endl;

// 