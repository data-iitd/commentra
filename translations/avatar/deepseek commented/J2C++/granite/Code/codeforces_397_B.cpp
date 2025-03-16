

#include <bits/stdc++.h>
using namespace std;

// Static variable to hold the value of N.
static int N;
// Constant MOD value.
const int MOD = (int) (1e9 + 7);

int main() {
    // Scanner to read input from the standard input stream.
    cin.tie(0)->sync_with_stdio(0);
    // PrintWriter to write output to the standard output stream.
    cout.tie(0)->sync_with_stdio(0);
    // Read the number of test cases.
    int t;
    cin >> t;
    // Process each test case.
    while (t-- > 0) {
        // Read the values of n, a, and b.
        long long n, a, b;
        cin >> n >> a >> b;
        // Check if n is less than a.
        if (n < a) {
            cout << "No\n";
            continue;
        }
        // Check if a is equal to b.
        if (a == b) {
            if (n % a == 0) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
            continue;
        }
        // Calculate x as b / (b - a).
        long long x = b / (b - a);
        // Check if n is greater than x * a.
        if (n > x * a) {
            cout << "Yes\n";
            continue;
        }
        // Perform binary search to find the minimum ans.
        long long low = 1;
        long long high = x + 1;
        long long ans = 1;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (mid * a < n) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }
        // Check if n lies between (ans - 1) * b and ans * a.
        if (n > (ans - 1) * b && n < ans * a) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
    return 0;
}
