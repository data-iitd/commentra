
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main method declaration
int main ( int argc , char * argv [ ] ) {
    char * s = malloc ( 1000000 * sizeof ( char ) ) ; // Create a new string to store the first input string
    char * t = malloc ( 1000000 * sizeof ( char ) ) ; // Create a new string to store the second input string
    scanf ( "%s" , s ) ; // Read the first input string from the console
    scanf ( "%s" , t ) ; // Read the second input string from the console

    // Initialize counters for unique characters in the first string and opposite characters in the second string
    int ura = 0 ;
    int opa = 0 ;

    // Create a HashMap to store the frequency of each character in the second string
    char * tmap [ 26 ] ;
    for ( int i = 0 ; i < 26 ; i ++ ) {
        tmap [ i ] = malloc ( 1000000 * sizeof ( char ) ) ;
        tmap [ i ] [ 0 ] = '\0' ;
    }

    // Read the characters of the second string and store their frequencies in the HashMap
    int length = strlen ( t ) ;
    for ( int i = 0 ; i < length ; i ++ ) {
        char ch = t [ i ] ;
        if ( tmap [ ch - 'a' ] [ 0 ] == '\0' ) // If the character is not already in the HashMap
            strcat ( tmap [ ch - 'a' ] , "1" ) ; // Add it with a frequency of 1
        else
            strcat ( tmap [ ch - 'a' ] , "1" ) ; // If the character is already in the HashMap, increment its frequency
    }

    // Process the first string
    length = strlen ( s ) ;
    for ( int i = 0 ; i < length ; i ++ ) {
        char ch = s [ i ] ;
        char * num = tmap [ ch - 'a' ] ;
        if ( num [ 0 ] == '\0' ) // If the character is not in the second string
            continue ;
        int inum = atoi ( num ) ;
        if ( inum == 1 ) // If the character appears only once in the second string
            tmap [ ch - 'a' ] [ 0 ] = '\0' ; // Remove it from the HashMap
        else
            strcat ( tmap [ ch - 'a' ] , "1" ) ; // If the character appears more than once in the second string, decrement its frequency
        s [ i ] = 'Я' ; // Replace the character in the string with 'Я'
        ura ++ ; // Increment the counter for unique characters
    }

    // Process the reversed version of the first string
    for ( int i = 0 ; i < length ; i ++ ) {
        char ch = s [ i ] ;
        char rch = reverse ( ch ) ; // Get the reverse character of the current character
        char * num = tmap [ rch - 'a' ] ;
        if ( num [ 0 ] == '\0' ) // If the reverse character is not in the second string
            continue ;
        int inum = atoi ( num ) ;
        if ( inum == 1 ) // If the reverse character appears only once in the second string
            tmap [ rch - 'a' ] [ 0 ] = '\0' ; // Remove it from the HashMap
        else
            strcat ( tmap [ rch - 'a' ] , "1" ) ; // If the reverse character appears more than once in the second string, decrement its frequency
        opa ++ ; // Increment the counter for opposite characters
    }

    // Print the results
    printf ( "%d %d\n" , ura , opa ) ;

    // Free the memory allocated for the strings
    free ( s ) ;
    free ( t ) ;
    for ( int i = 0 ; i < 26 ; i ++ )
        free ( tmap [ i ] ) ;

    return 0 ;
}

// Reverse the given character
char reverse ( char ch ) {
    if ( ch >= 'a' && ch <= 'z' ) // If the character is lowercase
        return ch - 'a' + 'A' ; // Return its uppercase version
    else
        return ch - 'A' + 'a' ; // If the character is uppercase, return its lowercase version
}

