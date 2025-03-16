#include <iostream>
using namespace std;

// Function to read an integer from standard input.
int ri() {
    int x;
    cin >> x;
    return x;
}

int main() {
    // Read the integer value of N from standard input.
    int N = ri();

    // Initialize the variable ans to 0.
    long long ans = 0;

    // Start a loop that iterates from 1 to N + 1.
    for (int i = 1; i <= N; ++i) {
        // Calculate the sum of multiples of i up to N using the formula for the sum of an arithmetic series.
        ans += static_cast<long long>(i) * (N / i) * (N / i + 1) / 2;
    }

    // Print the final value of ans, which represents the sum of multiples of numbers from 1 to N.
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
