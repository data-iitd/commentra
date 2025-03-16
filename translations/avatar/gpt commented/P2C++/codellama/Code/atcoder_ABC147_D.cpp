
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // Read the number of elements in the array
    int N;
    cin >> N;

    // Read the input values and create a vector of integers
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Initialize the result variable to store the final answer
    long long result = 0;

    // Iterate over each bit position from 0 to 59 (assuming 60 bits for integers)
    for (int b = 0; b < 60; b++) {
        // Count how many numbers have the b-th bit set (1)
        int bs = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] & (1 << b)) {
                bs++;
            }
        }

        // Calculate the contribution of the b-th bit to the result
        // bs * (N - bs) gives the number of pairs with different b-th bits
        // (1 << b) gives the value of the b-th bit
        result = (result + bs * (N - bs) * (1 << b)) % 1000000007;
    }

    // Print the final result
    cout << result << endl;

    return 0;
}

