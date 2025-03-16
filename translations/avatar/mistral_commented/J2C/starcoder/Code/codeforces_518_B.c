
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Main method declaration
int main ( int argc, char * argv [ ] ) {
    char s [ 100000 ] ;
    scanf ( "%s", s ) ;
    char t [ 100000 ] ;
    scanf ( "%s", t ) ;

    // Initialize counters for unique characters in the first string and opposite characters in the second string
    int ura = 0 ;
    int opa = 0 ;

    // Create a HashMap to store the frequency of each character in the second string
    int tmap [ 26 ] ;
    memset ( tmap, 0, sizeof ( tmap ) ) ;

    // Read the characters of the second string and store their frequencies in the HashMap
    for ( int i = 0 ; i < strlen ( t ) ; i ++ ) {
        char ch = t [ i ] ;
        if ( tmap [ ch - 'a' ] == 0 ) // If the character is not already in the HashMap
            tmap [ ch - 'a' ] = 1 ; // Add it with a frequency of 1
        else
            tmap [ ch - 'a' ] ++ ; // If the character is already in the HashMap, increment its frequency
    }

    // Process the first string
    int length = strlen ( s ) ;
    for ( int i = 0 ; i < length ; i ++ ) {
        char ch = s [ i ] ;
        int num = tmap [ ch - 'a' ] ;
        if ( num == 0 ) // If the character is not in the second string
            continue ;
        int inum = num ;
        if ( inum == 1 ) // If the character appears only once in the second string
            tmap [ ch - 'a' ] = 0 ; // Remove it from the HashMap
        else
            tmap [ ch - 'a' ] -- ; // If the character appears more than once in the second string, decrement its frequency
        s [ i ] = 'Я' ; // Replace the character in the string with 'Я'
        ura ++ ; // Increment the counter for unique characters
    }

    // Process the reversed version of the first string
    for ( int i = 0 ; i < length ; i ++ ) {
        char ch = s [ i ] ;
        char rch = reverse ( ch ) ; // Get the reverse character of the current character
        int num = tmap [ rch - 'a' ] ;
        if ( num == 0 ) // If the reverse character is not in the second string
            continue ;
        int inum = num ;
        if ( inum == 1 ) // If the reverse character appears only once in the second string
            tmap [ rch - 'a' ] = 0 ; // Remove it from the HashMap
        else
            tmap [ rch - 'a' ] -- ; // If the reverse character appears more than once in the second string, decrement its frequency
        opa ++ ; // Increment the counter for opposite characters
    }

    // Print the results
    printf ( "%d %d\n", ura, opa ) ;
}

// Reverse the given character
char reverse ( char ch ) {
    if ( islower ( ch ) ) { // If the character is lowercase
        return toupper ( ch ) ; // Return its uppercase version
    } else {
        return tolower ( ch ) ; // If the character is uppercase, return its lowercase version
    }
}

