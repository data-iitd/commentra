#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <numeric>
#include <memory>
#include <stack>

using namespace std;

/**
 * Main class to run the program.
 */
int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Read the number of test cases.
    int t;
    cin >> t;

    // Process each test case.
    while (t--) {
        // Read the values of n, a, and b.
        long long n, a, b;
        cin >> n >> a >> b;

        // Check if n is less than a.
        if (n < a) {
            cout << "No" << endl;
            continue;
        }

        // Check if a is equal to b.
        if (a == b) {
            if (n % a == 0) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
            continue;
        }

        // Calculate x as b / (b - a).
        long long x = b / (b - a);

        // Check if n is greater than x * a.
        if (n > x * a) {
            cout << "Yes" << endl;
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
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }

    return 0;
}
