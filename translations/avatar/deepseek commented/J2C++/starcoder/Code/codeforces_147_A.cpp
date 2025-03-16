
#include <iostream>
#include <string>

using namespace std;

// Method to check if a character is a Latin letter
bool isLatinLetter ( char c ) {
    return c >= 'a' && c <= 'z' ;
}

// Method to check if a character is a punctuation mark
bool isPunctuation ( char c ) {
    if ( c == '.' ) return true ;
    if ( c == ',' ) return true ;
    if ( c == '!' ) return true ;
    if ( c == '?' ) return true ;
    return false ;
}

// Main method: Entry point of the program
int main ( ) {
    // Read the input string
    string s ;
    cin >> s ;
    // Create a string to build the output string
    string out = "" ;
    // Get the length of the input string
    int n = s.length ( ) ;
    // Append the first character of the input string to the output string
    out += s[0] ;
    // Loop through the input string starting from the second character
    for ( int i = 1 ; i < n ; i ++ ) {
        char c = s[i] ;
        // Check if the character is a Latin letter
        if ( isLatinLetter ( c ) ) {
            // If the previous character is not a Latin letter, add a space
            if (! isLatinLetter ( s[i-1] ) ) {
                out +='' ;
            }
            // Append the current Latin letter to the output string
            out += c ;
        }
        // Check if the character is a punctuation mark
        else if ( isPunctuation ( c ) ) {
            // Append the punctuation mark to the output string
            out += c ;
        }
    }
    // Print the final string with spaces added between Latin letters
    cout << out << endl ;
    // Return from the main method
    return 0 ;
}

