
#include <iostream>
#include <string>

using namespace std ; // Using standard namespace

int main ( ) {
    // Main function to start the program

    string s ; // Declare a string variable
    cin >> s ; // Read the input string

    // Check if the string contains both 'A' and 'B'
    if ( s.find ( "A" ) != string::npos && s.find ( "B" ) != string::npos ) {
        cout << "Yes" << endl ; // Print "Yes" if both characters are present
    } else {
        cout << "No" << endl ; // Print "No" if either character is missing
    }

    return 0 ; // Return 0 to indicate successful execution
}

