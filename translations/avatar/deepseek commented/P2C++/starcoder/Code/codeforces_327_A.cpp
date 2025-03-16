#include <bits/stdc++.h>

using namespace std;

// Function to find indices of a character in a string
vector<int> find(string s, char ch) {
    vector<int> result;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ch) {
            result.push_back(i);
        }
    }
    return result;
}

// Main block of the code
int main() {
    // Read the integer input
    int n;
    cin >> n;
    // Read the string input and remove spaces
    string s;
    cin >> s;
    s.erase(remove(s.begin(), s.end(),''), s.end());
    
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
            // Generate all combinations of two indices of '0'
            vector<vector<int>> combs;
            for (int i = 0; i < indices.size(); i++) {
                for (int j = i + 1; j < indices.size(); j++) {
                    combs.push_back({indices[i], indices[j]});
                }
            }
            
            // Iterate over each combination and calculate the maximum distance
            for (auto x : combs) {
                maximum = max(maximum, 2 + 2 * (abs(indices.at(x[0]) - indices.at(x[1])) - 1) - (abs(x[0] - x[1]) - 1));
            }
            
            // Print the count of '1's plus the maximum distance
            cout << s.count('1') + maximum << endl;
        }
    }
    return 0;
}

