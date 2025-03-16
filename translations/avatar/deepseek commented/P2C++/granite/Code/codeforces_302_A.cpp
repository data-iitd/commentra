

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, sa, a, b;
    cin >> n >> m;
    // Read two integers n and m from input

    sa = count(begin(string(m, '-')), end(string(m, '-')), '-');
    // Count the number of '-' characters in the input

    sa = min(n - sa, sa);
    // Set sa to the minimum of n - sa and sa, possibly normalizing sa

    vector<string> ss;
    // Initialize an empty vector to store results

    for (int _ = 0; _ < m; _++) {
        cin >> a >> b;
        // Read two integers a and b in each iteration of the loop

        b -= a;
        // Subtract a from b

        if (b % 2 && b <= sa * 2) {
            // Check if b is odd and within certain bounds
            ss.push_back("1\n");
            // Append "1\n" to ss if condition is met
        } else {
            ss.push_back("0\n");
            // Append "0\n" to ss otherwise
    }

    cout << accumulate(ss.begin(), ss.end(), string());
    // Join and print the contents of ss

    return 0;
}
// End of C++ code