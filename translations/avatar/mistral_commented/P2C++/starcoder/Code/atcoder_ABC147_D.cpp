#include <iostream>
#include <vector>
#include <climits>
#include <cstdint>

using namespace std;

int main() {
    // Read the number of elements 'N' from the user
    int N;
    cin >> N;

    // Read 'N' integers from the user and store them in a vector 'A'
    vector<int64_t> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Initialize the result variable to zero
    int64_t result = 0;

    // Iterate through each bit position 'b' from 0 to 59
    for (int b = 0; b < 60; b++) {

        // Calculate the sum of bits in position 'b' in all numbers of 'A'
        int64_t bs = 0;
        for (int64_t a : A) {
            bs += (a >> b) & 1;
        }

        // Calculate the contribution of this bit position 'b' to the result
        int64_t contribution = bs * (N - bs) * (1 << b);

        // Add this contribution to the result
        result = (result + contribution) % 1000000007;
    }

    // Print the final result
    cout << result << endl;

    return 0;
}
