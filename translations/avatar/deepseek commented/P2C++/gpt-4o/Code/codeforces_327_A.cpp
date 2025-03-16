#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

// Function to find indices of a character in a string
vector<int> find(const string& s, char ch) {
    vector<int> indices;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == ch) {
            indices.push_back(i);
        }
    }
    return indices;
}

int main() {
    // Read the integer input
    int n;
    cin >> n;
    cin.ignore(); // To ignore the newline character after the integer input

    // Read the string input and remove spaces
    string s;
    getline(cin, s);
    s.erase(remove(s.begin(), s.end(), ' '), s.end());

    // If the string does not contain '0', print n - 1
    if (s.find('0') == string::npos) {
        cout << n - 1 << endl;
    } else {
        // Find all indices of '0' in the string
        vector<int> indices = find(s, '0');

        // If there is only one '0', print n
        if (indices.size() == 1) {
            cout << n << endl;
        } else {
            // Initialize maximum to 0
            int maximum = 0;

            // Iterate over each combination of two indices of '0'
            for (size_t i = 0; i < indices.size(); ++i) {
                for (size_t j = i + 1; j < indices.size(); ++j) {
                    int dist = 2 + 2 * (abs(static_cast<int>(i) - static_cast<int>(j)) - 1) - (abs(indices[i] - indices[j]) - 1);
                    maximum = max(maximum, dist);
                }
            }

            // Print the count of '1's plus the maximum distance
            cout << count(s.begin(), s.end(), '1') + maximum << endl;
        }
    }

    return 0;
}

// <END-OF-CODE>
