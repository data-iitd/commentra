
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s; // Step 1: Reading Input - The program starts by declaring a string variable `s` and using `cin` to read input from the user.

    replace(s.begin(), s.end(), "dream", "D"); // Step 2: Replacing Substrings - The program replaces occurrences of "dream" with "D" and "erase" with "E".
    replace(s.begin(), s.end(), "erase", "E");

    s.erase(remove(s.begin(), s.end(), "Der"), s.end()); // Step 3: Removing Modified Substrings - The program further replaces occurrences of "Der", "Er", "D", and "E" with an empty string.
    s.erase(remove(s.begin(), s.end(), "Er"), s.end());
    s.erase(remove(s.begin(), s.end(), "D"), s.end());
    s.erase(remove(s.begin(), s.end(), "E"), s.end());

    s.erase(0, s.find_first_not_of(" ")); // Step 4: Trimming Spaces - The program removes any leading or trailing whitespace from the string.
    s.erase(s.find_last_not_of(" ") + 1);

    if (s.empty()) { // Step 5: Checking for Emptiness - The program checks if the string `s` is empty and prints "YES" or "NO" accordingly.
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

