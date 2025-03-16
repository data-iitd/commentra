#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    // Read input from the user and store it in the variable 's'
    cin >> s;

    // Iterate over each character in the string 's'
    for (int i = 0; i < s.length(); i++) {
        // Check if the current character exists in the substring that follows it
        if (s.find(s[i], i + 1) != string::npos) {
            // If the character is found in the remaining substring, print "no" and exit
            cout << "no" << endl;
            return 0;
        }
    }

    // If no duplicate characters were found, print "yes"
    cout << "yes" << endl;
    return 0;
}

