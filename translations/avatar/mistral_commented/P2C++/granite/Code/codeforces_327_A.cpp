
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Define a helper function 'find' to locate the indices of a character in a string
vector<int> find(string s, char ch) {
    // Use vector<int> to store the indices of the character 'ch' in the string's'
    vector<int> indices;

    // Use for loop to iterate through each character in the string's'
    for (int i = 0; i < s.length(); i++) {
        // If the current character matches the character 'ch', add its index to the 'indices' vector
        if (s[i] == ch) {
            indices.push_back(i);
        }
    }

    // Return the vector of indices
    return indices;
}

int main() {
    // Read the number of test cases 'n' from the standard input
    int n;
    cin >> n;

    // Read the string's' from the standard input and remove any leading or trailing whitespaces
    string s;
    getline(cin, s);
    s.erase(remove(s.begin(), s.end(),''), s.end());

    // Check if the string's' does not contain '0' character
    if (s.find('0') == string::npos) {
        // If '0' is not present, print the result as the number of test cases minus one
        cout << n - 1 << endl;
    } else {
        // If '0' is present, proceed with further logic
        // Find the indices of '0' character in the string's'
        vector<int> indices = find(s, '0');

        // Check if there is only one '0' character in the string's'
        if (indices.size() == 1) {
            // If there is only one '0', print the result as the number of '1's in the string
            cout << n << endl;
        } else {
            // If there are multiple '0's, calculate the maximum combination score
            int maximum = 0;

            // Use for loop to iterate through all possible combinations of indices of '0' characters
            for (int i = 0; i < indices.size(); i++) {
                for (int j = i + 1; j < indices.size(); j++) {
                    // Calculate the score for the current combination using the given formula
                    int score = 2 + 2 * (abs(indices[i] - indices[j]) - 1) - (abs(i - j) - 1);
                    // Update the maximum combination score if the current combination score is greater
                    maximum = max(maximum, score);
                }
            }

            // Print the final result which is the number of '1's in the string plus the maximum combination score
            cout << s.count('1') + maximum << endl;
        }
    }

    return 0;
}

