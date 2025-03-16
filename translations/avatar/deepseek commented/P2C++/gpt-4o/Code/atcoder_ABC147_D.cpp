#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int main() {
    // Read the size of the array
    int N;
    cin >> N;

    // Create a vector to store the input values
    vector<int64_t> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Initialize the result variable to 0
    int64_t result = 0;
    const int MOD = 1000000007;

    // Loop over each bit position from 0 to 59
    for (int b = 0; b < 60; ++b) {
        // Count the number of set bits at the current bit position
        int bs = 0;
        for (int i = 0; i < N; ++i) {
            bs += (A[i] >> b) & 1;
        }

        // Calculate the contribution of the current bit position to the result
        result = (result + static_cast<int64_t>(bs) * (N - bs) * (1LL << b)) % MOD;
    }

    // Print the final result
    cout << result << endl;

    return 0;
}

// <END-OF-CODE>
