
####
// Importing necessary C libraries for reading input from the console and writing output to the console
#include <stdio.h>
#include <stdbool.h>

// Method to check if a character is a Latin letter
bool isLatinLetter ( char c ) {
    // Check if the character falls within the ASCII range of Latin letters
    return c >= 'a' && c <= 'z' ;
}

// Method to check if a character is a punctuation mark
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
    // Creating variables to store the input string and the output string
    char s [ 1000 ] ;
    char sb [ 1000 ] ;

    // Reading a line of input from the console
    scanf ( "%s", s ) ;

    // Finding the length of the input string
    int n = strlen ( s ) ;

    // Appending the first character of the input string to the output string
    sb [ 0 ] = s [ 0 ] ;

    // Iterating through the rest of the characters in the input string
    for ( int i = 1 ; i < n ; i ++ ) {
        // Getting the current character from the input string
        char c = s [ i ] ;

        // If the current character is a Latin letter, append it to the output string with a space before it if the previous character was not a Latin letter
        if ( isLatinLetter ( c ) ) {
            if (! isLatinLetter ( s [ i - 1 ] ) ) {
                sb [ strlen ( sb ) ] ='' ;
            }
            sb [ strlen ( sb ) ] = c ;
        }
        // If the current character is a punctuation mark, append it directly to the output string without a space
        else if ( isPunctuation ( c ) ) {
            sb [ strlen ( sb ) ] = c ;
        }
    }

    // Writing the output to the console
    printf ( "%s\n", sb ) ;

    // Ending the program
    return 0 ;
}
