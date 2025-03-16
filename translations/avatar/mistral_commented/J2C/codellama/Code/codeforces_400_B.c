
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    // Initializing variables for storing input
    int n, m, i, dexG, dexS, returnDex = - 1, index = 0 ;
    // Initializing a pointer to store the address of the array of strings
    char **arrs ;
    // Initializing a pointer to store the address of the array of integers
    int *length ;
    // Initializing a pointer to store the address of the HashSet
    int *set ;

    // Reading the first two integers from the input
    scanf ( "%d %d", &n, &m ) ;

    // Allocating memory for the array of strings
    arrs = ( char ** ) malloc ( n * sizeof ( char * ) ) ;

    // Iterating through the array and storing each string
    for ( i = 0 ; i < n ; i ++ ) {
        // Allocating memory for the current string
        arrs [ i ] = ( char * ) malloc ( m * sizeof ( char ) ) ;
        // Reading a string from the input
        scanf ( "%s", arrs [ i ] ) ;
    }

    // Allocating memory for the array of integers
    length = ( int * ) malloc ( n * sizeof ( int ) ) ;

    // Iterating through each string in the array and finding the length of substrings between "G" and "S"
    for ( i = 0 ; i < n ; i ++ ) {
        // Finding the index of "G" in the current string
        dexG = strchr ( arrs [ i ], 'G' ) - arrs [ i ] ;
        // Finding the index of "S" in the current string
        dexS = strchr ( arrs [ i ], 'S' ) - arrs [ i ] ;

        // Checking if "G" comes before "S" in the current string
        if ( dexG > dexS ) {
            returnDex = i ; // Storing the index of the string with "G" before "S"
            break ; // Exiting the loop as we have found the required string
        }

        // Storing the length of the substring between "G" and "S" in the length array
        length [ index ++ ] = dexS - dexG ;
    }

    // Allocating memory for the HashSet
    set = ( int * ) malloc ( n * sizeof ( int ) ) ;

    // Iterating through the length array and adding each unique length to the HashSet
    for ( i = 0 ; i < n ; i ++ ) {
        set [ i ] = length [ i ] ;
    }

    // Checking if there is a string with "G" before "S"
    if ( returnDex == - 1 ) {
        // Printing the result if there is no such string
        printf ( "%d\n", returnDex ) ;
    } else {
        // Printing the size of the HashSet if there is a string with "G" before "S"
        printf ( "%d\n", n ) ;
    }

    // Freeing the memory allocated for the array of strings
    for ( i = 0 ; i < n ; i ++ ) {
        free ( arrs [ i ] ) ;
    }
    free ( arrs ) ;

    // Freeing the memory allocated for the array of integers
    free ( length ) ;

    // Freeing the memory allocated for the HashSet
    free ( set ) ;

    return 0 ;
}

