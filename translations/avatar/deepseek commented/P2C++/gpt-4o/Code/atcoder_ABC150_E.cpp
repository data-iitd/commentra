#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n;
    cin >> n; // Read the integer input `n`

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i]; // Read the list of integers `c`
    }

    sort(c.rbegin(), c.rend()); // Sort the list `c` in descending order

    long long b = 1;
    for (int i = 0; i < 2 * n - 2; ++i) {
        b = (b * 2) % mod; // Calculate `b` as 2^(2*n - 2) % mod
    }

    long long a = (2 * b) % mod; // Calculate `a` as twice `b` modulo `mod`

    long long ans = 0; // Initialize `ans` to 0

    for (int i = 0; i < n; ++i) {
        ans = (ans + c[i] * (a + i * b)) % mod; // Update `ans`
    }

    cout << ans << endl; // Print the final result `ans`

    return 0;
}
// <END-OF-CODE>
