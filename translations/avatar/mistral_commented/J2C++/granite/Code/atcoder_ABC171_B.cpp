
#include <bits/stdc++.h>
using namespace std;

// Main method to start the program
int main() {
    // Initialize input and output streams
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Create Solution object and call its solve method
    Solution sol;
    sol.solve();

    return 0;
}

// Private nested class for solving the problem
class Solution {
public:
    // Method to solve the problem
    void solve() {
        // Read input: number of elements n and the number of summands k
        int n, k;
        cin >> n >> k;

        // Read input array a of size n
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; // Read next element of array a
        }

        // Sort the array a in parallel using std::sort()
        sort(a.begin(), a.end());

        // Calculate the answer: sum of first k elements of sorted array a
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            ans += a[i];
        }

        // Write the answer to the output stream
        cout << ans << endl;
    }
};

// End of code
