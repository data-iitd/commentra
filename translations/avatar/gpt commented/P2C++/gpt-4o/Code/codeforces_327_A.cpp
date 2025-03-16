#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> find(const string& s, char ch) {
    // This function returns a vector of indices where the character 'ch' appears in the string 's'.
    vector<int> indices;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == ch) {
            indices.push_back(i);
        }
    }
    return indices;
}

int main() {
    // Read an integer input 'n' which represents the length of the string.
    int n;
    cin >> n;
    
    // Read the string input 's'.
    string s;
    cin >> s;
    
    // Check if the string 's' contains the character '0'.
    if (s.find('0') == string::npos) {
        // If '0' is not present, the output is n - 1.
        cout << n - 1 << endl;
    } else {
        // Find all indices of '0' in the string 's'.
        vector<int> indices = find(s, '0');
        
        // If there is only one '0', output the length of the string 'n'.
        if (indices.size() == 1) {
            cout << n << endl;
        } else {
            // Initialize a variable to keep track of the maximum value found.
            int maximum = 0;
            
            // Iterate through each combination of indices of '0' taken 2 at a time.
            for (size_t i = 0; i < indices.size(); ++i) {
                for (size_t j = i + 1; j < indices.size(); ++j) {
                    // Calculate the maximum value based on the distance between the two indices.
                    int dist = abs(indices[i] - indices[j]);
                    maximum = max(maximum, 2 + 2 * (j - i - 1) - (dist - 1));
                }
            }
            
            // Output the count of '1's in the string plus the maximum value calculated.
            cout << count(s.begin(), s.end(), '1') + maximum << endl;
        }
    }

    return 0;
}

// <END-OF-CODE>
