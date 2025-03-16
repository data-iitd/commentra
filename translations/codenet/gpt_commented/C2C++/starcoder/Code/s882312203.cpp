#include <iostream>
#include <cstring>

using namespace std;

int main() {
    // Declare a character array to hold the input string (max length 25 + 1 for null terminator)
    char s[26];

    // Read a string from standard input
    cin >> s;

    // Loop through each character in the string
    for (int j = 0; j < strlen(s); j++) {
        // Compare the current character with every other character in the string
        for (int i = 0; i < strlen(s); i++) {
            // Check if the characters are the same and they are not the same position
            if ((i!= j) && (s[i] == s[j])) {
                // If a duplicate character is found, print "no" and exit the program
                cout << "no" << endl;
                return 0;
            }
        }
    }

    // If no duplicates were found, print "yes"
    cout << "yes" << endl;

    return 0;
}
