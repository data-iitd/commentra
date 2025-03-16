#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int mod = 1000000007;

int main() {
    // Read the number of elements
    int n;
    cin >> n;

    // Read the list of integers and convert them to a list of integers
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    // Sort the list in descending order
    sort(c.rbegin(), c.rend());

    // Calculate the value of b as 2^(2*n - 2) modulo mod
    int b = pow(2, 2 * n - 2) % mod;

    // Calculate the value of a as 2 * b modulo mod
    int a = 2 * b % mod;

    // Initialize the answer variable
    int ans = 0;

    // Iterate through the sorted list and calculate the answer
    for (int i = 0; i < n; ++i) {
        // Update the answer by adding the product of the current element and (a + i * b)
        ans += c[i] * (a + i * b);
        // Ensure the answer remains within the modulo
        ans %= mod;
    }

    // Print the final result
    cout << ans << endl;

    return 0;
}
