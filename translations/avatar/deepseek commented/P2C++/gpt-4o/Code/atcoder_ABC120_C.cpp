#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Main function to solve the problem
int main() {
    // Read input string from the user
    string s;
    cin >> s;

    // Check if all characters in the string are the same
    if (s.find_first_not_of(s[0]) == string::npos) {
        cout << 0 << endl;
        return 0;
    }

    // Count the frequency of each character in the string
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    // Calculate the answer as twice the minimum frequency of any character
    int min_freq = INT_MAX;
    for (const auto& pair : freq) {
        min_freq = min(min_freq, pair.second);
    }
    int ans = min_freq * 2;

    // Print the answer and exit
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
