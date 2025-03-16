#include <iostream>
#include <string>

using namespace std;

int main() {
    string s; // Declare a string variable to store the input string

    cin >> s; // Read a string from the user input and store it in the variable s

    // Outer loop to iterate over each character in the string s using index j
    for (int j = 0; j < s.length(); j++) {
        // Inner loop to iterate over each character in the string s using index i
        for (int i = 0; i < s.length(); i++) {
            // Check if the characters at positions i and j are the same, but only if i is not equal to j
            if ((i != j) && (s[i] == s[j])) {
                cout << "no" << endl; // Print "no" if a duplicate character is found and exit the program
                return 0;
            }
        }
    }

    cout << "yes" << endl; // Print "yes" if no duplicates are found after completing the loops

    return 0; // Return 0 to indicate successful execution of the program
}

