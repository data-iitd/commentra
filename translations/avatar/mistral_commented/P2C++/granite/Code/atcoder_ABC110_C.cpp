
#include <bits/stdc++.h>

using namespace std;

// Define a function named 'run' that takes two arguments's' and 't'
string run(string s, string t) {
    // Using unordered_map to count the occurrences of each character in string's'
    // and storing the result in a map
    unordered_map<char, int> ss;
    for (char c : s) {
        ss[c]++;
    }

    // Using unordered_map to count the occurrences of each character in string 't'
    // and storing the result in a map
    unordered_map<char, int> tt;
    for (char c : t) {
        tt[c]++;
    }

    // Comparing the maps of occurrences of characters in strings's' and 't'
    // If they are equal, then the strings have the same frequency distribution of characters
    // and thus are identical, so return 'Yes'
    // Otherwise, return 'No'
    if (ss == tt) {
        return "Yes";
    } else {
        return "No";
    }
}

// Define a function named'main' that takes no arguments
int main() {
    // Taking input strings's' and 't' from the user
    string s, t;
    cin >> s >> t;

    // Calling the 'run' function with strings's' and 't' as arguments and printing the result
    cout << run(s, t) << endl;

    return 0;
}

// End of code