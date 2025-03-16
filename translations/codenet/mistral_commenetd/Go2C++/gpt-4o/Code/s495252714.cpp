#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Constants
const int mod = 1000000007;

// Function to calculate modular exponentiation
int modpow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (1LL * res * a) % mod;
        }
        a = (1LL * a * a) % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    // Read an integer n from standard input
    int n;
    cin >> n;

    // Read n integers c from standard input and store them in a vector
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    // Initialize answer variable to 0
    long long ans = 0;

    // Sort vector c in ascending order
    sort(c.begin(), c.end());

    // Iterate through vector c and calculate answer
    for (int i = 0; i < n; i++) {
        // Calculate contribution of current integer to answer
        ans = (ans + (1LL * (n + 1 - i) * c[i]) % mod) % mod;
    }

    // Calculate final answer by multiplying answer with (4^(n-1)) modulo mod
    cout << (ans * modpow(4, n - 1)) % mod << endl;

    return 0;
}

// <END-OF-CODE>
