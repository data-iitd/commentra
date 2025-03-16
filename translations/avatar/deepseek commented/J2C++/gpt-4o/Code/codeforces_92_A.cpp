#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k; // Read the number of elements in the sequence and the initial value of k

    int i = 1, req = 1; // Initialize i and req to 1

    // Loop continues as long as k - req is non-negative
    while (k - req >= 0) {
        k -= req; // Subtract req from k
        i++; // Increment i
        if (i % n != 0) {
            req = i % n; // Update req to i % n if i % n is not zero
        } else {
            req = n; // Update req to n if i % n is zero
        }
    }

    cout << k << endl; // Print the final value of k
    return 0;
}

// <END-OF-CODE>
