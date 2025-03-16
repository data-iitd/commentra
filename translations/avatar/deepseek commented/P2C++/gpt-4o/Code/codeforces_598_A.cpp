#include <iostream>
using namespace std;

int solve(int n) {
    // Calculate the sum of the first n natural numbers
    int s = (1 + n) * n / 2;
    // Initialize t to 1
    int t = 1;
    // Subtract twice the sum of powers of 2 up to n from s
    while (t <= n) {
        s -= 2 * t;
        t *= 2;
    }
    return s;
}

int main() {
    int t;  // Number of test cases
    cin >> t;  // Read the number of test cases

    // Main loop to iterate over the number of test cases
    for (int i = 0; i < t; i++) {
        int n;  // Each n for the test case
        cin >> n;  // Read n
        cout << solve(n) << endl;  // Print the result of the solve function for the current n
    }

    return 0;
}

// <END-OF-CODE>
