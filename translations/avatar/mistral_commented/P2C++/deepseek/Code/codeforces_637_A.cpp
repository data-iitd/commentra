#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    // Read the number of strings to be processed
    int n;
    cin >> n;

    // Create a vector to store the strings
    vector<string> s(n);

    // Read the strings and store them in the vector
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    // Create an unordered_map to store the occurrences of each string
    unordered_map<string, int> w;

    // Count the occurrences of each string
    for (const auto& str : s) {
        ++w[str];
    }

    // Initialize variables for storing the index of the longest string and its value
    int c = -1, a_index = 0;
    string a;

    // Iterate through each string in the unordered_map
    for (const auto& pair : w) {
        // If the current string has the maximum occurrences
        if (pair.second == w.begin()->second) {
            // If its index in the original vector is greater than the current index of the longest string
            auto it = find(s.begin(), s.end(), pair.first);
            if (it != s.end() && distance(s.begin(), it) > c) {
                // Update the longest string and its index
                a = pair.first;
                a_index = distance(s.begin(), it);
                c = a_index;
            }
        }
    }

    // Print the longest string
    cout << a << endl;

    return 0;
}
