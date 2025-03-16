#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a constant for the modulus
const int mod = 1000000007;

// Function to perform modular exponentiation
int modpow(int a, int n) {
    int res = 1; // Initialize result
    while (n > 0) {
        if (n & 1) { // If n is odd
            res = (1LL * res * a) % mod; // Update result
        }
        a = (1LL * a * a) % mod; // Square the base
        n >>= 1; // Divide n by 2
    }
    return res; // Return the final result
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n; // Read the number of integers

    vector<int> c(n); // Create a vector to hold n integers
    for (int i = 0; i < n; i++) {
        cin >> c[i]; // Read n integers into vector c
    }

    long long ans = 0; // Initialize answer variable
    sort(c.begin(), c.end()); // Sort the vector of integers

    // Calculate the answer based on the sorted integers
    for (int i = 0; i < n; i++) {
        ans = (ans + (1LL * (n + 1 - i) * c[i]) % mod) % mod; // Update the answer using the formula
    }

    // Print the final result after applying modular exponentiation
    cout << (ans * modpow(4, n - 1) % mod) << endl;

    return 0;
}

// <END-OF-CODE>
