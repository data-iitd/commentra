#######
#include <bits/stdc++.h>

using namespace std ;

// Function to check if a character is a Latin letter
bool isLatinLetter ( char c ) {
    // Check if the character falls within the ASCII range of Latin letters
    return c >= 'a' && c <= 'z' ;
}

// Function to check if a character is a punctuation mark
bool isPunctuation ( char c ) {
    // Check if the character is a dot, comma, exclamation mark, or question mark
    if ( c == '.' ) return true ;
    if ( c == ',' ) return true ;
    if ( c == '!' ) return true ;
    if ( c == '?' ) return true ;
    // If none of the above conditions are met, return false
    return false ;
}

int main ( ) {
    // Creating a stringstream to read input from the console
    stringstream ss ;
    ss.str ( cin.rdbuf ( ) ) ;

    // Creating a string to store the output
    string s ;

    // Reading a line of input from the console
    getline ( ss, s ) ;

    // Creating a stringstream to store the output
    stringstream ss2 ;

    // Finding the length of the input string
    int n = s.length ( ) ;

    // Appending the first character of the input string to the stringstream
    ss2 << s.at ( 0 ) ;

    // Iterating through the rest of the characters in the input string
    for ( int i = 1 ; i < n ; i ++ ) {
        // Getting the current character from the input string
        char c = s.at ( i ) ;

        // If the current character is a Latin letter, append it to the stringstream with a space before it if the previous character was not a Latin letter
        if ( isLatinLetter ( c ) ) {
            if (! isLatinLetter ( s.at ( i - 1 ) ) ) {
                ss2 <<'' ;
            }
            ss2 << c ;
        }
        // If the current character is a punctuation mark, append it directly to the stringstream without a space
        else if ( isPunctuation ( c ) ) {
            ss2 << c ;
        }
    }

    // Writing the output to the console
    cout << ss2.str ( ) << endl ;

    return 0 ;
}

