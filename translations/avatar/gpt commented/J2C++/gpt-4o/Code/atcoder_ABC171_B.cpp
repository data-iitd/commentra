#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void solve(istream &in, ostream &out) {
        // Read the number of elements (n) and the number of smallest elements to sum (k)
        int n, k;
        in >> n >> k;

        // Initialize a vector to hold the input numbers
        vector<int> a(n);

        // Read n integers from input and store them in the vector
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }

        // Sort the vector in ascending order
        sort(a.begin(), a.end());

        // Initialize a variable to hold the sum of the smallest k elements
        int ans = 0;

        // Sum the first k elements of the sorted vector
        for (int i = 0; i < k; ++i) {
            ans += a[i];
        }

        // Output the result (sum of the smallest k elements)
        out << ans << endl;
    }
};

int main() {
    // Create an instance of the Solution class to solve the problem
    Solution sol;

    // Call the solve method to process the input and produce output
    sol.solve(cin, cout);

    return 0;
}

// <END-OF-CODE>
