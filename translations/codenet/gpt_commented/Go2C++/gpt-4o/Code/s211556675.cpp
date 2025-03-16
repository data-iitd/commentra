#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to read an integer from input
int readInt() {
    int x;
    cin >> x;
    return x;
}

// Main function
int main() {
    // Read four integers from input
    int A = readInt();
    int B = readInt();
    int C = readInt();
    int K = readInt();

    // Determine the maximum value among A, B, and C
    int ma = max({A, B, C});
    int rest = 0; // Initialize the rest variable to hold the sum of the other two values

    // Calculate the sum of the two smaller values
    if (ma == A) {
        rest += B + C;
    } else if (ma == B) {
        rest += A + C;
    } else {
        rest += A + B;
    }

    // Double the maximum value K times
    for (int i = 0; i < K; i++) {
        ma *= 2;
    }

    // Output the final result: doubled max value plus the sum of the other two
    cout << ma + rest << endl;

    return 0;
}
// <END-OF-CODE>
