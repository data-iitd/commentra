#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to perform ceiling division
long long divUp(long long x, long long y) {
    return (x + y - 1) / y;
}

int main() {
    long long N;
    cin >> N; // Read the number of pairs
    vector<long long> T(N), A(N); // Initialize vectors for T and A

    // Read pairs of integers into T and A
    for (long long i = 0; i < N; i++) {
        cin >> T[i] >> A[i]; // Read each pair
    }

    long long t = T[0], a = A[0]; // Initialize t and a with the first pair

    // Iterate through the remaining pairs to compute the required values
    for (long long i = 1; i < N; i++) {
        long long r = max(divUp(t, T[i]), divUp(a, A[i])); // Calculate the required multiplier
        t = T[i] * r; // Update t based on the multiplier
        a = A[i] * r; // Update a based on the multiplier
    }

    cout << t + a << endl; // Output the final result
    return 0; // End of the program
}

// <END-OF-CODE>
