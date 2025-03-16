#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Function to check if the frequency distributions of both strings are same
string run(string s, string t) {
    // Count the frequency of each character in string s and sort the frequencies
    vector<int> ss = sort(vector<int>(s.begin(), s.end()));
    
    // Count the frequency of each character in string t and sort the frequencies
    vector<int> tt = sort(vector<int>(t.begin(), t.end()));
    
    // Compare the sorted frequency lists of both strings
    if (ss == tt) {
        return "Yes";  // Return 'Yes' if the frequency distributions are the same
    } else {
        return "No";   // Return 'No' if the frequency distributions are different
    }
}

// Driver code
int main() {
    // Read input strings s and t from the user
    string s;
    cin >> s;
    string t;
    cin >> t;
    
    // Print the result of the run function which checks the character frequency
    cout << run(s, t) << endl;
    
    return 0;
}

