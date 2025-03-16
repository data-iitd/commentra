#include <bits/stdc++.h>
using namespace std;

// Function to calculate the value of t
int t(int i, int k) {
    return ( (t(i-1, k) % k) * 10 + 7 ) % k;
}

// Function to find the smallest multiple of k
int main() {
    // Read the value of k
    int k;
    cin >> k;

    // Initialize a variable t to 0
    int t = 0;

    // Loop from 1 to k
    for (int i = 1; i <= k; i++) {
        // Calculate the value of t using the current value of i and k
        t = t(i, k);

        // Check if t is a multiple of k
        if (t == 0) {
            // Print the value of i and break out of the loop
            cout << i << endl;
            break;
        }
    }

    // If the loop completes without finding a multiple of k, print -1
    if (t!= 0) {
        cout << -1 << endl;
    }

    return 0;
}

