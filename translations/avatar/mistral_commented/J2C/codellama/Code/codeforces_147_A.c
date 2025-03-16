
#include <stdio.h>
#include <string.h>

// Function to check if a character is a Latin letter
int isLatinLetter ( char c ) {
    // Check if the character falls within the ASCII range of Latin letters
    if ( c >= 'a' && c <= 'z' ) {
        return 1 ;
    }
    else {
        return 0 ;
    }
}

// Function to check if a character is a punctuation mark
int isPunctuation ( char c ) {
    // Check if the character is a dot, comma, exclamation mark, or question mark
    if ( c == '.' ) {
        return 1 ;
    }
    else if ( c == ',' ) {
        return 1 ;
    }
    else if ( c == '!' ) {
        return 1 ;
    }
    else if ( c == '?' ) {
        return 1 ;
    }
    else {
        return 0 ;
    }
}

int main ( ) {
    // Declaring a string to store the input
    char s [ 100 ] ;

    // Reading a line of input from the console
    scanf ( "%s", s ) ;

    // Declaring a string to store the output
    char output [ 100 ] ;

    // Finding the length of the input string
    int n = strlen ( s ) ;

    // Appending the first character of the input string to the output string
    strcat ( output, s ) ;

    // Iterating through the rest of the characters in the input string
    for ( int i = 1 ; i < n ; i ++ ) {
        // Getting the current character from the input string
        char c = s [ i ] ;

        // If the current character is a Latin letter, append it to the output string with a space before it if the previous character was not a Latin letter
        if ( isLatinLetter ( c ) ) {
            if ( ! isLatinLetter ( s [ i - 1 ] ) ) {
                strcat ( output, " " ) ;
            }
            strcat ( output, s [ i ] ) ;
        }
        // If the current character is a punctuation mark, append it directly to the output string without a space
        else if ( isPunctuation ( c ) ) {
            strcat ( output, s [ i ] ) ;
        }
    }

    // Writing the output to the console
    printf ( "%s\n", output ) ;

    return 0 ;
}

