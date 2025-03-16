#include <bits/stdc++.h>

using namespace std;

// Define a helper function 'find' to locate the indices of a character in a string
int find(string s, char ch) {
    // Use a for-loop to iterate through the string's' and return the index of the character 'ch'
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ch) {
            return i;
        }
    }
    // Return -1 if the character 'ch' is not found in the string's'
    return -1;
}

// Check if the given input is valid and execute the main logic if it is
int main() {
    // Read the number of test cases 'n' from the standard input
    int n;
    cin >> n;

    // Read the string's' from the standard input and remove any leading or trailing whitespaces
    string s;
    cin >> s;
    s.erase(remove(s.begin(), s.end(),''), s.end());

    // Check if the string's' does not contain '0' character
    if (find(s, '0') == -1) {
        // If '0' is not present, print the result as the number of test cases minus one
        cout << n - 1 << endl;
    }

    // If '0' is present, proceed with further logic
    else {
        // Find the indices of '0' character in the string's'
        vector<int> indices;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                indices.push_back(i);
            }
        }

        // Check if there is only one '0' character in the string's'
        if (indices.size() == 1) {
            // If there is only one '0', print the result as the number of '1's in the string
            cout << n << endl;
        }

        // If there are multiple '0's, calculate the maximum combination score
        else {
            // Initialize the maximum combination score as 0
            int maximum = 0;

            // Generate all possible combinations of indices of '0' characters using itertools.combinations()
            vector<vector<int>> combs;
            do {
                combs.push_back(vector<int>(indices.begin(), indices.end()));
            } while (next_permutation(indices.begin(), indices.end()));

            // Iterate through each combination and calculate the score for that combination
            for (vector<int> x : combs) {
                // Calculate the score for the current combination using the given formula
                int score = 2 + 2 * (abs(indices.at(x[0]) - indices.at(x[1])) - 1) - (abs(x[0] - x[1]) - 1);
                // Update the maximum combination score if the current combination score is greater
                maximum = max(maximum, score);
            }

            // Print the final result which is the number of '1's in the string plus the maximum combination score
            cout << s.count('1') + maximum << endl;
        }
    }

    // Return 0
    return 0;
}

