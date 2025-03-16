
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

string run(string s, string t) {
    // Define the run function that takes two arguments, s and t
    map<char, int> ss;
    // Create a map object for s
    for (int i = 0; i < s.length(); i++) {
        // Iterate over the characters of s
        ss[s[i]]++;
        // Increment the value of the character in the map
    }
    map<char, int> tt;
    // Create a map object for t
    for (int i = 0; i < t.length(); i++) {
        // Iterate over the characters of t
        tt[t[i]]++;
        // Increment the value of the character in the map
    }
    if (ss == tt) {
        // Check if the maps are equal
        return "Yes";
    } else {
        // If not equal, return 'No'
        return "No";
    }
}

int main() {
    // Define the main function to get input and print the result
    string s, t;
    // Get input for s and t from the user
    cin >> s >> t;
    // Print the result of the run function with s and t as arguments
    cout << run(s, t) << endl;
    // End with comment "