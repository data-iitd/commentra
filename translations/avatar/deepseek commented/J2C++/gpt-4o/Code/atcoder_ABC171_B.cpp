#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void solve(istream &in, ostream &out) {
        int n, k;
        in >> n >> k; // Reads the number of elements (n) and the number of elements to consider (k)
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i]; // Reads the elements into a vector
        }
        sort(a.begin(), a.end()); // Sorts the vector
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            ans += a[i]; // Sums the first k elements
        }
        out << ans << endl; // Prints the result
    }
};

int main() {
    Solution sol;
    sol.solve(cin, cout); // Calls the solve function with standard input and output
    return 0;
}

// <END-OF-CODE>
