
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int N ;  // Declaring an integer variable to store the number of strings
    scanf ( "%d" , &N ) ;  // Reading the number of strings from the input

    char **map = ( char ** ) malloc ( N * sizeof ( char * ) ) ;  // Creating a 2D array to store the strings

    for ( int i = 0 ; i < N ; i ++ ) {  // Loop to read strings from the input and store them in the 2D array
        map [ i ] = ( char * ) malloc ( 100 * sizeof ( char ) ) ;
        scanf ( "%s" , map [ i ] ) ;
    }

    int i = 0 ;  // Initializing an integer variable to store the index of the current string
    char *past = ( char * ) malloc ( 100 * sizeof ( char ) ) ;  // Creating a string variable to store the previous string
    char *next = ( char * ) malloc ( 100 * sizeof ( char ) ) ;  // Creating a string variable to store the next character of the current string

    while ( i < N ) {  // Loop to check for the condition
        if ( strcmp ( past , map [ i ] ) == 0 ) {  // Checking if the current string is already in the 2D array
            printf ( "No" ) ;
            return 0 ;
        }
        strcpy ( past , map [ i ] ) ;  // Storing the current string in the past variable

        if ( i != 0 ) {  // Checking if it's not the first iteration of the loop
            if ( strcmp ( next , map [ i ] ) != 0 ) {  // Checking if the current string starts with the same character as the previous string
                printf ( "No" ) ;
                return 0 ;
            }
        }
        strcpy ( next , map [ i ] ) ;  // Storing the last character of the current string in the next variable
        i ++ ;
    }

    printf ( "Yes" ) ;  // Printing "Yes" if the condition is satisfied

    return 0 ;
}

