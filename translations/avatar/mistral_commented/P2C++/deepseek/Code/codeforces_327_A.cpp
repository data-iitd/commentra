#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric> // for std::accumulate

using namespace std;

// Define a helper function 'find' to locate the indices of a character in a string
vector<int> find(const string& s, char ch) {
    vector<int> indices;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ch) {
            indices.push_back(i);
        }
    }
    return indices;
}

int main() {
    // Read the number of test cases 'n' from the standard input
    int n;
    cin >> n;
    cin.ignore(); // Ignore the newline character after reading 'n'

    // Read the string 's' from the standard input and remove any leading or trailing whitespaces
    string s;
    getline(cin, s);

    // Check if the string 's' does not contain '0' character
    if (s.find('0') == string::npos) {
        // If '0' is not present, print the result as the number of test cases minus one
        cout << n - 1 << endl;
    } else {
        // Find the indices of '0' character in the string 's'
        vector<int> indices = find(s, '0');

        // Check if there is only one '0' character in the string 's'
        if (indices.size() == 1) {
            // If there is only one '0', print the result as the number of '1's in the string
            cout << n << endl;
        } else {
            // Initialize the maximum combination score as 0
            int maximum = 0;

            // Generate all possible combinations of indices of '0' characters
            for (size_t i = 0; i < indices.size(); ++i) {
                for (size_t j = i + 1; j < indices.size(); ++j) {
                    // Calculate the score for the current combination using the given formula
                    int score = 2 + 2 * (abs(i - j) - 1) - (abs(indices[i] - indices[j]) - 1);
                    // Update the maximum combination score if the current combination score is greater
                    maximum = max(maximum, score);
                }
            }

            // Print the final result which is the number of '1's in the string plus the maximum combination score
            cout << count(s.begin(), s.end(), '1') + maximum << endl;
        }
    }

    return 0;
}
