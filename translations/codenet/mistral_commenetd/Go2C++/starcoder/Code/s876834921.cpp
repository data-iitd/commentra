
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Initialize an empty string variable's'
    string s;

    // Read a string input from the user using 'cin' function
    cin >> s;

    // Replace all occurrences of the substrings "dream" and "erase" with "D" and "E" respectively using'replace' function
    replace(s.begin(), s.end(), "dream", "D");
    replace(s.begin(), s.end(), "erase", "E");

    // Remove the substrings "Der" and "Er" from the string's' using'replace' function
    replace(s.begin(), s.end(), "Der", "");
    replace(s.begin(), s.end(), "Er", "");

    // Remove leading and trailing spaces from the string's' using 'trim' function
    s.erase(0, s.find_first_not_of(' '));
    s.erase(s.find_last_not_of(' ') + 1);

    // Check if the string's' is empty or not
    if (s.empty()) {
        // Print "YES" if the string's' is empty
        cout << "YES" << endl;
    } else {
        // Print "NO" if the string's' is not empty
        cout << "NO" << endl;
    }

    // End of the code
    return 0;
}

