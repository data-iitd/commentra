#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) { 
    int n ; // Declaring the size of the matrix
    char arr [ ] [ ] ; // Declaring the 2D character array
    char str [ ] ; // Declaring the string array to store input strings

    // Reading the size of the matrix
    scanf ( "%d", &n ) ; 

    // Allocating memory for the 2D character array
    arr = ( char * ) malloc ( n * sizeof ( char * ) ) ; 
    for ( int i = 0 ; i < n ; i ++ ) { 
        arr [ i ] = ( char * ) malloc ( n * sizeof ( char ) ) ; 
    } 

    // Allocating memory for the string array
    str = ( char * ) malloc ( n * sizeof ( char * ) ) ; 
    for ( int i = 0 ; i < n ; i ++ ) { 
        str [ i ] = ( char * ) malloc ( n * sizeof ( char ) ) ; 
    } 

    // Reading n strings and storing them in the str array
    for ( int i = 0 ; i < n ; i ++ ) { 
        scanf ( "%s", str [ i ] ) ; 
    } 

    // Populating the 2D character array from the strings
    for ( int i = 0 ; i < n ; i ++ ) { 
        for ( int j = 0 ; j < n ; j ++ ) { 
            arr [ i ] [ j ] = str [ i ][ j ] ; 
        } 
    } 

    // Comparing the first two characters to determine a and b
    char a = arr [ 0 ] [ 0 ] ; 
    char b = arr [ 0 ] [ 1 ] ; 

    // If the characters are the same, print "NO" and exit
    if ( a == b ) { 
        printf ( "NO" ) ; 
    } else { 
        int res = 1 ; // Initialize result as true

        // Iterating through the matrix to validate the pattern
        for ( int i = 0 ; i < n ; i ++ ) { 
            for ( int j = 0 ; j < n ; j ++ ) { 
                if ( i == j || i + j == n - 1 ) { // Check diagonal elements
                    if ( arr [ i ] [ j ] != a ) { // If diagonal element is not a, set res to false
                        res = 0 ; 
                        break ; 
                    } 
                } else { // Check off-diagonal elements
                    if ( arr [ i ] [ j ] != b ) { // If off-diagonal element is not b, set res to false
                        res = 0 ; 
                        break ; 
                    } 
                } 
            } 
        } 

        // Printing the result
        if ( res ) { 
            printf ( "YES" ) ; 
        } else { 
            printf ( "NO" ) ; 
        } 
    } 

    // Freeing memory
    for ( int i = 0 ; i < n ; i ++ ) { 
        free ( arr [ i ] ) ; 
        free ( str [ i ] ) ; 
    } 
    free ( arr ) ; 
    free ( str ) ; 

    return 0 ; 
}

