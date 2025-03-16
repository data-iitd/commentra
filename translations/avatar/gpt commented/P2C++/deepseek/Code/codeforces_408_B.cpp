#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solution() {
    // Read the first line of input which represents the colors bought
    string line;
    getline(cin, line);
    // Count the occurrences of each color bought using unordered_map
    unordered_map<char, int> bought_count;
    for (char color : line) {
        bought_count[color]++;
    }
    
    // Read the second line of input which represents the colors made
    getline(cin, line);
    // Count the occurrences of each color made using unordered_map
    unordered_map<char, int> made_count;
    for (char color : line) {
        made_count[color]++;
    }
    
    // Initialize the result variable to store the total count of matched colors
    int res = 0;
    
    // Iterate through each color in the made_count
    for (const auto& pair : made_count) {
        char color = pair.first;
        // If a color made is not found in the bought colors, return -1
        if (bought_count.find(color) == bought_count.end()) {
            cout << -1 << endl;
            return;
        }
        // Add the minimum of the bought and made counts for each color to the result
        res += min(bought_count[color], pair.second);
    }
    
    // Print the total count of matched colors
    cout << res << endl;
}

int main() {
    // Set the number of test cases (currently set to 1)
    int t = 1;
    // Loop through each test case
    for (int _ = 0; _ < t; ++_) {
        solution();
    }
    return 0;
}
