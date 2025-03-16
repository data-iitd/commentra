#include <iostream>
using namespace std;

int main() {
    // Read the integer k from input
    int k;
    cin >> k;

    // Initialize a variable to hold the current value of t
    long long t = 0;

    // Loop through numbers from 1 to k
    for (int i = 1; i <= k; ++i) {
        // Update t by appending a '7' at the end and taking modulo k
        t = (t % k) * 10 + 7;

        // Check if the current value of t is divisible by k
        if (t % k == 0) {
            cout << i << endl;  // Print the current index if divisible
            return 0; // Exit the program
        }
    }

    // If no index was found, print -1
    cout << -1 << endl;

    return 0;
}

// <END-OF-CODE>
