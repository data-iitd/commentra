#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

string run(const string& s, const string& t) {
    // Define the run function that takes two string arguments, s and t
    unordered_map<char, int> countS, countT;
    // Create unordered maps to count occurrences of characters in s and t

    for (char c : s) {
        countS[c]++;
    }
    // Count characters in s

    for (char c : t) {
        countT[c]++;
    }
    // Count characters in t

    vector<int> ss, tt;
    // Vectors to store the counts of characters

    for (const auto& pair : countS) {
        ss.push_back(pair.second);
    }
    // Store counts from countS into ss

    for (const auto& pair : countT) {
        tt.push_back(pair.second);
    }
    // Store counts from countT into tt

    sort(ss.begin(), ss.end());
    sort(tt.begin(), tt.end());
    // Sort the counts

    if (ss == tt) {
        // Check if the sorted counts of s and t are equal
        return "Yes";
    } else {
        // If not equal, return "No"
        return "No";
    }
}

int main() {
    // Define the main function to get input and print the result
    string s, t;
    // Declare strings for input
    cin >> s;
    // Get input for s from the user
    cin >> t;
    // Get input for t from the user
    cout << run(s, t) << endl;
    // Call the run function with s and t as arguments and print the result
    return 0;
}

