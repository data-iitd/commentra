
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// Method to check if there's a column filled with 'X' characters in the given string
int isSolution ( int columnsCount , char * x ) { 
    int allXs [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; 
    for ( int i = 0 ; i < 12 ; i ++ ) { 
        if ( x [ i ] != 'X' ) 
            allXs [ i % columnsCount ] = 0 ; 
    } 
    for ( int i = 0 ; i < columnsCount ; i ++ ) 
        if ( allXs [ i ] ) 
            return 1 ; 
    return 0 ; 
} 

// Main method where the program starts
int main ( ) { 
    int t ; 
    scanf ( "%d" , &t ) ; 
    for ( int i = 0 ; i < t ; i ++ ) { 
        int possibleSolutions = 0 ; 
        char solutions [ 100 ] = { 0 } ; 
        char s [ 100 ] = { 0 } ; 
        scanf ( "%s" , s ) ; 
        if ( isSolution ( 12 , s ) ) { 
            strcat ( solutions , " 1x12" ) ; 
            possibleSolutions ++ ; 
        } 
        if ( isSolution ( 6 , s ) ) { 
            strcat ( solutions , " 2x6" ) ; 
            possibleSolutions ++ ; 
        } 
        if ( isSolution ( 4 , s ) ) { 
            strcat ( solutions , " 3x4" ) ; 
            possibleSolutions ++ ; 
        } 
        if ( isSolution ( 3 , s ) ) { 
            strcat ( solutions , " 4x3" ) ; 
            possibleSolutions ++ ; 
        } 
        if ( isSolution ( 2 , s ) ) { 
            strcat ( solutions , " 6x2" ) ; 
            possibleSolutions ++ ; 
        } 
        if ( isSolution ( 1 , s ) ) { 
            strcat ( solutions , " 12x1" ) ; 
            possibleSolutions ++ ; 
        } 
        printf ( "%d %s" , possibleSolutions ++ , solutions ) ; 
    } 
    return 0 ; 
} 

