#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Set the value of modulo for modular arithmetic calculations
const int mod = 1e9 + 7;

int main() {
    // Read an integer n from the standard input
    int n;
    cin >> n;

    // Read n integers from the standard input and store them in a vector c
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    // Sort the vector c in descending order
    sort(c.rbegin(), c.rend());

    // Calculate the value of b using the formula 2^(2*n-2) modulo mod
    long long b = 1;
    for (int i = 0; i < 2 * n - 2; ++i) {
        b = (b * 2) % mod;
    }

    // Calculate the value of a as 2*b modulo mod
    long long a = (2 * b) % mod;

    // Initialize the variable ans to zero
    long long ans = 0;

    // Iterate through each index i from 0 to n-1 in the vector c
    for (int i = 0; i < n; ++i) {
        // Add the product of the current element c[i] and the sum of a and i*b to the variable ans
        ans = (ans + c[i] * (a + i * b)) % mod;
    }

    // Print the value of ans as the output
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
