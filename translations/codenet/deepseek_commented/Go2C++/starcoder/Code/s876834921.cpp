#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s; // Step 1: Reading Input - The program starts by declaring a string variable `s` and using `cin` to read input from the user.

    s = replace(s, "dream", "D", -1); // Step 2: Replacing Substrings - The program replaces occurrences of "dream" with "D" and "erase" with "E".
    s = replace(s, "erase", "E", -1);

    s = replace(s, "Der", "", -1); // Step 3: Removing Modified Substrings - The program further replaces occurrences of "Der", "Er", "D", and "E" with an empty string.
    s = replace(s, "Er", "", -1);
    s = replace(s, "D", "", -1);
    s = replace(s, "E", "", -1);

    s = trim(s); // Step 4: Trimming Spaces - The program removes any leading or trailing whitespace from the string.

    if (s == "") { // Step 5: Checking for Emptiness - The program checks if the string `s` is empty and prints "YES" or "NO" accordingly.
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

