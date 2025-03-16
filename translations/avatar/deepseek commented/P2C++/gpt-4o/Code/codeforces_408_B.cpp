#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

void solution() {
    // Read the first line of input and create an unordered_map for the bought colors
    string line;
    getline(cin, line);
    unordered_map<char, int> bought_count;
    for (char color : line) {
        bought_count[color]++;
    }

    // Read the second line of input and create an unordered_map for the colors to be made
    getline(cin, line);
    unordered_map<char, int> made_count;
    for (char color : line) {
        made_count[color]++;
    }

    // Initialize the result variable to store the total number of colors that can be made
    int res = 0;

    // Iterate over each color in the 'made_count' unordered_map
    for (const auto& pair : made_count) {
        char color = pair.first;
        // Check if the color is not in the 'bought_count' unordered_map
        if (bought_count.find(color) == bought_count.end()) {
            // If a color is not bought, print -1 and exit
            cout << -1 << endl;
            return;
        }
        // Calculate the minimum of the counts of the current color in both 'bought_count' and 'made_count'
        // and add this to the result
        res += min(bought_count[color], made_count[color]);
    }

    // Print the final result
    cout << res << endl;
}

int main() {
    // Set the number of test cases to 1
    int t = 1;
    // Run the solution function for one test case
    for (int i = 0; i < t; i++) {
        solution();
    }
    return 0;
}

// <END-OF-CODE>
