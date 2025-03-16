
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Define the modulo constant
const int MOD = 1000000007;

// Define a constant for the maximum size
const int M = 1000000;

// Define a constant for factorial calculations
const int Nsq = 1000;

// Define a function to compute factorial values
void factorial(vector<int> &fact) {
    // Set the first factorial value
    fact[0] = 1;

    // Compute factorial values for columns
    for (int n = 1; n < Nsq; n++) {
        for (int i = 0; i < Nsq; i++) {
            fact[n * Nsq + i] = (fact[n * Nsq + i] + fact[n * Nsq + i - 1]) % MOD;
        }
    }

    // Compute factorial values for rows
    for (int n = 1; n < Nsq; n++) {
        for (int i = 0; i < Nsq; i++) {
            fact[n + i * Nsq] = (fact[n + i * Nsq] + fact[(n - 1) + i * Nsq]) % MOD;
        }
    }
}

// Define a function to compute modular inverses
void modular_inverse(vector<int> &inv, int n) {
    // Initialize the first element
    inv[0] = pow(1, MOD - 2, MOD);

    // Compute modular inverses for the rest of the elements
    for (int i = 1; i < n; i++) {
        inv[i] = (inv[i - 1] * (i + 1) % MOD) % MOD;
    }
}

// Define a function to compute the final answer
int compute_answer(vector<int> &A, vector<int> &inv, vector<int> &fact) {
    // Initialize the final answer
    int ans = 0;

    // Compute temporary values based on the cumulative inverses
    for (int i = 0; i < A.size(); i++) {
        ans = (ans + inv[i] + inv[A.size() - 1 - i] - 1) % MOD;
    }

    // Compute the final answer by multiplying A with temp and summing the result
    for (int i = 0; i < A.size(); i++) {
        ans = (ans + A[i] * ans % MOD) % MOD;
    }

    // Multiply the answer by the factorial of N and take modulo
    ans = (ans * fact[A.size()]) % MOD;

    // Return the final answer
    return ans;
}

int main() {
    // Read the integer input N
    int N;
    cin >> N;

    // Read the array A from input and convert it to a vector of int64 type
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Initialize a 2D array to store factorial values
    vector<int> fact(Nsq * Nsq);

    // Compute factorial values
    factorial(fact);

    // Initialize a vector to store modular inverses
    vector<int> inv(N);

    // Compute modular inverses
    modular_inverse(inv, N);

    // Compute the final answer
    int ans = compute_answer(A, inv, fact);

    // Print the final answer
    cout << ans << endl;

    return 0;
}

