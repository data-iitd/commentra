
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Read input string
    string s;
    cin >> s;

    // Check if all characters in the string are the same
    if (count(s.begin(), s.end(), s[0]) == s.size()) {
        cout << 0 << endl;  // If true, print 0 and exit
        return 0;
    }

    // Count the occurrences of each character in the string
    unordered_map<char, int> a;
    for (char c : s) {
        a[c]++;
    }

    // Calculate the answer as twice the minimum frequency of any character
    int ans = *min_element(a.begin(), a.end(), [](const pair<char, int>& p1, const pair<char, int>& p2) {
        return p1.second < p2.second;
    }).second * 2;

    // Print the final answer
    cout << ans << endl;
}

// Entry point of the program
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int tests = 1;
    // cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        // Run the main function for the current test case
        main();
    }
    return 0;
}

Translate the above C++ code to Java and end with comment "