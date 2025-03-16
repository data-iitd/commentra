#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

bool isValid(const string& s1, const string& s2) {
    unordered_map<char, bool> map;
    
    // Populate the map with characters from s1
    for (char c : s1) {
        map[c] = true;
    }
    
    // Check if all characters of s1 are present in s2
    for (char c : s2) {
        if (map.find(c) == map.end()) return false;
    }
    
    return true;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2; // Read first and second strings
    
    // Check if the strings are valid using the isValid method
    if (!isValid(s1, s2)) {
        cout << -1 << endl; // Print -1 if strings are not valid
    } else {
        unordered_map<char, int> m1, m2;
        
        // Populate the HashMap with the frequency of each character in s1
        for (char c : s1) {
            m1[c]++;
        }
        
        // Populate the HashMap with the frequency of each character in s2
        for (char c : s2) {
            m2[c]++;
        }
        
        int ans = 0; // Initialize answer variable
        set<char> hs; // Create set to track processed characters
        
        // Iterate over the characters of s2
        for (char c : s2) {
            if (hs.find(c) == hs.end()) {
                hs.insert(c); // Mark character as processed
                int x1 = m1[c]; // Get frequency of character in s1
                int x2 = m2[c]; // Get frequency of character in s2
                x1 = min(x1, x2); // Calculate minimum frequency
                ans += x1; // Add minimum frequency to answer
            }
        }
        
        cout << ans << endl; // Print the final answer
    }
    
    return 0;
}
