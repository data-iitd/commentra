#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    // Read the first line of input which represents the colors bought
    string line;
    getline(cin, line);
    // Count the occurrences of each color bought using map
    map<char, int> bought_count;
    for (char c : line) {
        bought_count[c]++;
    }
    
    // Read the second line of input which represents the colors made
    getline(cin, line);
    // Count the occurrences of each color made using map
    map<char, int> made_count;
    for (char c : line) {
        made_count[c]++;
    }
    
    // Initialize the result variable to store the total count of matched colors
    int res = 0;
    
    // Iterate through each color in the made_count
    for (auto it = made_count.begin(); it != made_count.end(); it++) {
        // If a color made is not found in the bought colors, return -1
        if (bought_count.find(it->first) == bought_count.end()) {
            return cout << -1 << endl;
        }
        // Add the minimum of the bought and made counts for each color to the result
        res += min(bought_count[it->first], it->second);
    }
    
    // Print the total count of matched colors
    cout << res << endl;
    
    return 0;
}

// 