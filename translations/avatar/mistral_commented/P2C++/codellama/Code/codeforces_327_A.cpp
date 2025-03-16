#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Define a helper function 'find' to locate the indices of a character in a string
vector<int> find(string s, char ch) {
    // Use list comprehension to create a list of indices where the character 'ch' appears in the string 's'
    vector<int> indices;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ch) {
            indices.push_back(i);
        }
    }
    return indices;
}

// Check if the given input is valid and execute the main logic if it is
int main() {
    // Read the number of test cases 'n' from the standard input
    int n;
    cin >> n;

    // Read the string 's' from the standard input and remove any leading or trailing whitespaces
    string s;
    getline(cin, s);
    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);

    // Check if the string 's' does not contain '0' character
    if (s.find('0') == string::npos) {
        // If '0' is not present, print the result as the number of test cases minus one
        cout << n - 1 << endl;
    }

    // If '0' is present, proceed with further logic
    else {
        // Find the indices of '0' character in the string 's'
        vector<int> indices = find(s, '0');

        // Check if there is only one '0' character in the string 's'
        if (indices.size() == 1) {
            // If there is only one '0', print the result as the number of '1's in the string
            cout << s.length() - 1 << endl;
        }

        // If there are multiple '0's, calculate the maximum combination score
        else {
            // Initialize the maximum combination score as 0
            int maximum = 0;

            // Generate all possible combinations of indices of '0' characters using itertools.combinations()
            vector<vector<int>> combs;
            for (int i = 0; i < indices.size(); i++) {
                for (int j = i + 1; j < indices.size(); j++) {
                    vector<int> comb;
                    comb.push_back(indices[i]);
                    comb.push_back(indices[j]);
                    combs.push_back(comb);
                }
            }

            // Iterate through each combination and calculate the score for that combination
            for (int i = 0; i < combs.size(); i++) {
                // Calculate the score for the current combination using the given formula
                int score = 2 + 2 * (abs(indices[combs[i][0]] - indices[combs[i][1]]) - 1) - (abs(combs[i][0] - combs[i][1]) - 1);
                // Update the maximum combination score if the current combination score is greater
                maximum = max(maximum, score);
            }

            // Print the final result which is the number of '1's in the string plus the maximum combination score
            cout << s.length() - 1 + maximum << endl;
        }
    }

    return 0;
}

