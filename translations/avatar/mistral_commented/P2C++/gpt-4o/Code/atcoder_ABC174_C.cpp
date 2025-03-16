#include <iostream>
using namespace std;

// Define constants
const int mod = 1000000007;

// Function to read an integer from standard input
int ii1() {
    int x;
    cin >> x;
    return x;
}

int main() {
    // Set the value of k from standard input
    int k = ii1();

    // Initialize a variable t to 0
    int t = 0;

    // Loop from 1 to k
    for (int i = 1; i <= k; i++) {
        // Calculate the value of t using the current value of i and k
        t = ( (t % k) * 10 + 7 ) % k;

        // Check if t is a multiple of k
        if (t == 0) {
            // Print the value of i and break out of the loop
            cout << i << endl;
            return 0; // Exit the program
        }
    }

    // If the loop completes without finding a multiple of k, print -1
    cout << -1 << endl;

    return 0;
}

// <END-OF-CODE>
