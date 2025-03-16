#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    string s;
    cin >> s;

    // Check if all characters are the same
    if (unordered_set<char>(s.begin(), s.end()).size() == 1) {
        cout << 0 << endl;
        return 0;
    }

    unordered_map<char, int> count;
    for (char c : s) {
        count[c]++;
    }

    int ans = INT_MAX;
    for (const auto& pair : count) {
        ans = min(ans, pair.second);
    }

    cout << ans * 2 << endl;
    return 0;
}

// <END-OF-CODE>
