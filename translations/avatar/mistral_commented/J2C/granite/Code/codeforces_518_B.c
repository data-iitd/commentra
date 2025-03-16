

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Main method declaration
int main ( int argc, char * argv [ ] ) {
    char s [ 100001 ] ; // Create a character array to store the first input string
    char t [ 100001 ] ; // Create a character array to store the second input string
    scanf ( "%s", s ) ; // Read the first input string from the console
    scanf ( "%s", t ) ; // Read the second input string from the console

    // Initialize counters for unique characters in the first string and opposite characters in the second string
    int ura = 0 ;
    int opa = 0 ;

    // Create a HashMap to store the frequency of each character in the second string
    int tmap [ 256 ] = { 0 } ; // Initialize the HashMap with zeros

    // Read the characters of the second string and store their frequencies in the HashMap
    for ( int i = 0 ; t [ i ]!= '\0' ; i ++ ) {
        int ch = t [ i ] ;
        tmap [ ch ] ++ ; // Increment the frequency of the current character in the HashMap
    }

    // Process the first string
    int length = strlen ( s ) ;
    for ( int i = 0 ; i < length ; i ++ ) {
        int ch = s [ i ] ;
        int inum = tmap [ ch ] ;
        if ( inum == 0 ) // If the character is not in the second string
            continue ;
        tmap [ ch ] -- ; // If the character appears more than once in the second string, decrement its frequency
        s [ i ] = 'Я' ; // Replace the character in the string with 'Я'
        ura ++ ; // Increment the counter for unique characters
    }

    // Process the reversed version of the first string
    for ( int i = 0 ; i < length ; i ++ ) {
        int ch = s [ i ] ;
        int rch = ( ch >= 'a' && ch <= 'z' )? ( ch - 32 ) : ( ch + 32 ) ; // Get the reverse character of the current character
        int inum = tmap [ rch ] ;
        if ( inum == 0 ) // If the reverse character is not in the second string
            continue ;
        tmap [ rch ] -- ; // If the reverse character appears more than once in the second string, decrement its frequency
        opa ++ ; // Increment the counter for opposite characters
    }

    // Print the results
    printf ( "%d %d\n", ura, opa ) ; // Print the counters for unique characters and opposite characters

    return 0 ; // Return 0 to indicate successful execution
}

Translate the above C code to Python and end with comment "