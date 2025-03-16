#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> find(string s, char ch) {
    // This function returns a vector of indices where the character 'ch' appears in the string 's'.
    vector<int> indices;
    for (int i = 0; i < s.length(); i++) {
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
    
    // Read the string input 's' and replace any empty string occurrences (this line seems to be incorrect).
    string s;
    cin >> s;
    s.erase(remove(s.begin(), s.end(), ''), s.end());
    
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
            
            // Generate all combinations of indices of '0' taken 2 at a time.
            vector<int> combs;
            for (int i = 0; i < indices.size() - 1; i++) {
                for (int j = i + 1; j < indices.size(); j++) {
                    combs.push_back(indices[i]);
                    combs.push_back(indices[j]);
                }
            }
            
            // Iterate through each combination of indices.
            for (int i = 0; i < combs.size() - 1; i += 2) {
                // Calculate the maximum value based on the distance between the two indices.
                maximum = max(maximum, 2 + 2 * (abs(indices[combs[i]] - indices[combs[i + 1]]) - 1) - (abs(combs[i] - combs[i + 1]) - 1));
            }
            
            // Output the count of '1's in the string plus the maximum value calculated.
            cout << count(s.begin(), s.end(), '1') + maximum << endl;
        }
    }
    return 0;
}

