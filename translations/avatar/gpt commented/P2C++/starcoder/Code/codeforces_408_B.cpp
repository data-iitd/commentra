#include <bits/stdc++.h>
using namespace std;

int main() {
    // Set the number of test cases (currently set to 1)
    int t = 1;
    // Loop through each test case
    for (int _ = 0; _ < t; _++) {
        // Read the first line of input which represents the colors bought
        string line;
        cin >> line;
        // Count the occurrences of each color bought using map
        map<char, int> bought_count;
        for (char c : line) {
            bought_count[c]++;
        }
        
        // Read the second line of input which represents the colors made
        cin >> line;
        // Count the occurrences of each color made using map
        map<char, int> made_count;
        for (char c : line) {
            made_count[c]++;
        }
        
        // Initialize the result variable to store the total count of matched colors
        int res = 0;
        
        // Iterate through each color in the made_count
        for (auto color : made_count) {
            // If a color made is not found in the bought colors, return -1
            if (bought_count.find(color.first) == bought_count.end()) {
                cout << -1 << endl;
                return 0;
            }
            // Add the minimum of the bought and made counts for each color to the result
            res += min(bought_count[color.first], color.second);
        }
        
        // Print the total count of matched colors
        cout << res << endl;
    }
}

