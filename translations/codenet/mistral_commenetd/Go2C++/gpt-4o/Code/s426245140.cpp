// Include the necessary header for input and output
#include <iostream>
#include <string>

using namespace std;

// Main function
int main() {
    // Define a variable named "s" of type string to store user input
    string s;

    // Use "cin" to read a string input from the standard input
    cin >> s;

    // Check if the first three characters of the string "s" form an identical sequence
    if ((s[0] == s[1] && s[1] == s[2]) || (s[1] == s[2] && s[2] == s[3])) {
        // If the condition is true, print "Yes" to the standard output
        cout << "Yes" << endl;
    } else {
        // If the condition is false, print "No" to the standard output
        cout << "No" << endl;
    }

    return 0;
}

// <END-OF-CODE>
