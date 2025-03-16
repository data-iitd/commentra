#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <unordered_set>
#include <numeric>

using namespace std;

// Main function to solve the problem
int main() {
    // Read input string from the user
    string s;
    cin >> s;
    
    // Check if all characters in the string are the same
    set<char> unique_chars(s.begin(), s.end());
    if (unique_chars.size() == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    // Count the frequency of each character in the string
    unordered_map<char, int> freq_map;
    for (char c : s) {
        freq_map[c]++;
    }
    
    // Calculate the answer as twice the minimum frequency of any character
    int min_freq = INT_MAX;
    for (auto& pair : freq_map) {
        min_freq = min(min_freq, pair.second);
    }
    int ans = min_freq * 2;
    
    // Print the answer and exit
    cout << ans << endl;
    
    return 0;
}
