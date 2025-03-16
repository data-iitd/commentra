
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

int main() {
    // Read the size of the array
    int N;
    cin >> N;

    // Create a vector from the input values
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Initialize the result variable to 0
    long long result = 0;

    // Loop over each bit position from 0 to 59
    for (int b = 0; b < 60; b++) {
        // Count the number of set bits at the current bit position
        int bs = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] & (1 << b)) {
                bs++;
            }
        }

        // Calculate the contribution of the current bit position to the result
        result = (result + bs * (N - bs) * (1 << b)) % 1000000007;
    }

    // Print the final result
    cout << result << endl;

    return 0;
}

