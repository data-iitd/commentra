#include <bits/stdc++.h>
using namespace std;

// Define constants
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

// Define main function
int main() {
    // Read input string
    string s;
    cin >> s;

    // Check if all characters in the string are the same
    if (s.size() == 1) {
        // If so, print 0 and exit
        cout << 0 << endl;
        return 0;
    }

    // Count the occurrences of each character in the string
    map<char, int> a;
    for (char c : s) {
        a[c]++;
    }

    // Calculate the answer
    int ans = INF;
    for (auto it : a) {
        ans = min(ans, it.second * 2);
    }

    // Print the answer
    cout << ans << endl;

    return 0;
}

// End of code
