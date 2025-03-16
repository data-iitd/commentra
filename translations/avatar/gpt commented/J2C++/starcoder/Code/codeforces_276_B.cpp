#include <bits/stdc++.h>
using namespace std;

int main() {
    // Read a line of input from the user
    string str;
    getline(cin, str);
    
    // Create a map to count occurrences of each character
    map<char, int> map;
    int oddCount = 0; // Initialize counter for characters with odd occurrences
    
    // Iterate through each character in the input string
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        // Update the count of the character in the map
        if (map.find(ch)!= map.end()) {
            map[ch]++;
        } else {
            map[ch] = 1;
        }
    }
    
    // Count how many characters have an odd number of occurrences
    for (auto it = map.begin(); it!= map.end(); it++) {
        if (it->second % 2!= 0) {
            oddCount++;
        }
    }
    
    // Determine the output based on the count of odd occurrences
    if (oddCount <= 1 || oddCount % 2!= 0) {
        cout << "First" << endl; // Output "First" if conditions are met
    } else {
        cout << "Second" << endl; // Output "Second" otherwise
    }
    
    return 0;
}

