#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Define the constant for modular arithmetic.
const int mod = 1000000007;

// Function to perform modular exponentiation.
int modpow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    // Sort the vector of integers.
    sort(c.begin(), c.end());

    // Initialize the answer variable.
    int ans = 0;

    // Calculate the answer based on the sorted vector.
    for (int i = 0; i < n; i++) {
        ans = (ans + (n + 1 - i) * c[i] % mod) % mod;
    }

    // Print the final answer, multiplied by 4^(n-1) modulo mod.
    cout << ans * modpow(4, n - 1) % mod << endl;

    return 0;
}
