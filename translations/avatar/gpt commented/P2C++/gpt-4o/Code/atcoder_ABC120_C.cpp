#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    // Read input string
    string s;
    cin >> s;

    // Check if all characters in the string are the same
    if (set<char>(s.begin(), s.end()).size() == 1) {
        cout << 0 << endl;  // If true, print 0 and exit
        return 0;
    }

    // Count the occurrences of each character in the string
    unordered_map<char, int> count;
    for (char c : s) {
        count[c]++;
    }

    // Calculate the answer as twice the minimum frequency of any character
    int min_freq = INT_MAX;
    for (const auto& pair : count) {
        min_freq = min(min_freq, pair.second);
    }
    int ans = min_freq * 2;

    // Print the final answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
