
#include <bits/stdc++.h>
using namespace std;

// Define constants
const int MOD = 100000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// Define main function
int main() {
    // Read input string
    string s;
    cin >> s;

    // Check if all characters in the string are the same
    if (count(s.begin(), s.end(), s[0]) == s.size()) {
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
    int ans = *min_element(a.begin(), a.end(), [](const pair<char, int>& p1, const pair<char, int>& p2) {
        return p1.second < p2.second;
    }).second * 2;

    // Print the answer
    cout << ans << endl;
}

