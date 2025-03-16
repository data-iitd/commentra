#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Define a function named 'run' that takes two arguments 's' and 't'
string run(const string& s, const string& t) {
    // Using map to count the occurrences of each character in string 's'
    // and storing the result in a map
    map<char, int> ss;
    for (char c : s) {
        ss[c]++;
    }

    // Using map to count the occurrences of each character in string 't'
    // and storing the result in a map
    map<char, int> tt;
    for (char c : t) {
        tt[c]++;
    }

    // Create vectors from the maps to sort them
    vector<int> ss_values;
    vector<int> tt_values;
    for (const auto& pair : ss) {
        ss_values.push_back(pair.second);
    }
    for (const auto& pair : tt) {
        tt_values.push_back(pair.second);
    }

    // Sort the vectors
    sort(ss_values.begin(), ss_values.end());
    sort(tt_values.begin(), tt_values.end());

    // Comparing the sorted vectors of occurrences of characters in strings 's' and 't'
    // If they are equal, then the strings have the same frequency distribution of characters
    // and thus are identical, so return "Yes"
    // Otherwise, return "No"
    if (ss_values == tt_values) {
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

