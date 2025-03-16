#include <iostream>
#include <vector>
#include <numeric>

const int MOD = 1000000007;

int main() {
    // Read the number of elements 'N' from the user
    int N;
    std::cin >> N;

    // Read 'N' integers from the user and store them in a vector 'A'
    std::vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Initialize the result variable to zero
    long long result = 0;

    // Iterate through each bit position 'b' from 0 to 59
    for (int b = 0; b < 60; ++b) {
        // Calculate the sum of bits in position 'b' in all numbers of 'A'
        long long bs = 0;
        for (int i = 0; i < N; ++i) {
            bs += (A[i] >> b) & 1;
        }

        // Calculate the contribution of this bit position 'b' to the result
        long long contribution = bs * (N - bs) % MOD * (1LL << b) % MOD;

        // Add this contribution to the result
        result = (result + contribution) % MOD;
    }

    // Print the final result
    std::cout << result << std::endl;

    return 0;
}

// <END-OF-CODE>
