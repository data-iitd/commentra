#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cassert>

using namespace std;

int main() {
    // Read an integer input 'n' which represents the length of the string.
    int n;
    cin >> n;
    
    // Read the string input's' and replace any empty string occurrences (this line seems to be incorrect).
    string s;
    cin >> s;
    s.erase(remove(s.begin(), s.end(),''), s.end());
    
    // Check if the string's' contains the character '0'.
    if (s.find('0') == string::npos) {
        // If '0' is not present, the output is n - 1.
        cout << n - 1 << endl;
    } else {
        // Find all indices of '0' in the string's'.
        vector<int> indices;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                indices.push_back(i);
            }
        }
        
        // If there is only one '0', output the length of the string 'n'.
        if (indices.size() == 1) {
            cout << n << endl;
        } else {
            // Initialize a variable to keep track of the maximum value found.
            int maximum = 0;
            
            // Generate all combinations of indices of '0' taken 2 at a time.
            vector<vector<int>> combs;
            for (int i = 0; i < indices.size() - 1; i++) {
                for (int j = i + 1; j < indices.size(); j++) {
                    combs.push_back({indices[i], indices[j]});
                }
            }
            
            // Iterate through each combination of indices.
            for (auto x : combs) {
                // Calculate the maximum value based on the distance between the two indices.
                maximum = max(maximum, 2 + 2 * (abs(indices.at(x[0]) - indices.at(x[1])) - 1) - (abs(x[0] - x[1]) - 1));
            }
            
            // Output the count of '1's in the string plus the maximum value calculated.
            cout << count(s.begin(), s.end(), '1') + maximum << endl;
        }
    }
    
    return 0;
}

