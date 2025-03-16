#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// Define a function named 'run' that takes two arguments 's' and 't'
string run(const string& s, const string& t) {
    // Using unordered_map to count the occurrences of each character in string 's'
    unordered_map<char, int> countS;
    for (char c : s) {
        countS[c]++;
    }

    // Using unordered_map to count the occurrences of each character in string 't'
    unordered_map<char, int> countT;
    for (char c : t) {
        countT[c]++;
    }

    // Storing the counts in vectors
    vector<int> ss, tt;
    for (const auto& pair : countS) {
        ss.push_back(pair.second);
    }
    for (const auto& pair : countT) {
        tt.push_back(pair.second);
    }

    // Sorting the vectors
    sort(ss.begin(), ss.end());
    sort(tt.begin(), tt.end());

    // Comparing the sorted vectors of occurrences of characters in strings 's' and 't'
    // If they are equal, then the strings have the same frequency distribution of characters
    // and thus are identical, so return 'Yes'
    // Otherwise, return 'No'
    if (ss == tt) {
        return "Yes";
    } else {
        return "No";
    }
}

// Define a function named 'main' that takes no arguments
int main() {
    // Taking input strings 's' and 't' from the user
    string s, t;
    cin >> s >> t;

    // Calling the 'run' function with strings 's' and 't' as arguments and printing the result
    cout << run(s, t) << endl;

    return 0;
}

// <END-OF-CODE>
