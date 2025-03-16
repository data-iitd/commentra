
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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
    // Create a string to store the input
    char s[100] ;
    // Create a string to store the output
    char sb[100] ;
    // Read the input string
    scanf ( "%s", s ) ;
    // Get the length of the input string
    int n = strlen ( s ) ;
    // Append the first character of the input string to the output string
    sb[0] = s[0] ;
    // Loop through the input string starting from the second character
    for ( int i = 1 ; i < n ; i ++ ) {
        char c = s[i] ;
        // Check if the character is a Latin letter
        if ( isLatinLetter ( c ) ) {
            // If the previous character is not a Latin letter, add a space
            if ( ! isLatinLetter ( s[i - 1] ) ) {
                sb[i] = ' ' ;
            }
            // Append the current Latin letter to the output string
            sb[i] = c ;
        }
        // Check if the character is a punctuation mark
        else if ( isPunctuation ( c ) ) {
            // Append the punctuation mark to the output string
            sb[i] = c ;
        }
    }
    // Print the final string with spaces added between Latin letters
    printf ( "%s\n", sb ) ;
    return 0 ;
}

