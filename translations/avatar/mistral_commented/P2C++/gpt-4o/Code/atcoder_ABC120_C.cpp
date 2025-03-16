#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Define constants
const long long INF = 1e18;
const int MOD = 1e9 + 7;

// Define main function
int main() {
    // Read input string
    string s;
    cin >> s;

    // Check if all characters in the string are the same
    if (all_of(s.begin(), s.end(), [&](char c) { return c == s[0]; })) {
        // If so, print 0 and exit
        cout << 0 << endl;
        return 0;
    }

    // Count the occurrences of each character in the string
    unordered_map<char, int> count;
    for (char c : s) {
        count[c]++;
    }

    // Calculate the answer
    int ans = 2 * min_element(count.begin(), count.end(), 
                               [](const pair<char, int>& a, const pair<char, int>& b) {
                                   return a.second < b.second;
                               })->second;

    // Print the answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
