
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main ( ) {
    // Initialize a string variable 's' to store the input line
    char s[100] = "" ;

    // Read the next line from the console and store it in the string 's'
    fgets ( s, 100, stdin ) ;

    // Get the length of the string 's'
    int length = strlen ( s ) ;

    // Initialize a character variable 'ch' to store the first non-space and non-question mark character found in the string 's'
    char ch = ' ' ;

    // Iterate through the string 's' from the end to the beginning
    for ( int i = length - 1 ; i >= 0 ; i -- ) {
        // Check if the current character is not a space or a question mark
        if ( s[i] != ' ' && s[i] != '?' ) {
            // If yes, store the character in 'ch' and break out of the loop
            ch = s[i] ;
            break ;
        }
    }

    // Convert the character 'ch' to lowercase
    ch = tolower ( ch ) ;

    // Check if the character 'ch' is a vowel or a y
    if ( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y' ) {
        // If yes, print "YES" to the console
        printf ( "YES\n" ) ;
    } else {
        // If no, print "NO" to the console
        printf ( "NO\n" ) ;
    }

    // End of code
    return 0 ;
}

