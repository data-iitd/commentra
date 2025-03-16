
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

#define N 200 + 10 

int f [ N ] ; 
char b [ N ] ; 

// Computes the failure array for the given pattern
void getFail ( char b [ ] , int m ) { 
    int j = 0 ; 
    f [ 0 ] = f [ 1 ] = 0 ; 
    for ( int i = 2 ; i <= m ; i ++ ) { 
        while ( j > 0 && b [ j + 1 ] != b [ i ] ) 
            j = f [ j ] ; 
        if ( b [ j + 1 ] == b [ i ] ) 
            j ++ ; 
        f [ i ] = j ; 
    } 
} 

int main ( ) { 
    int n ; 
    char s1 [ N ] , str [ N ] ; 
    
    // Read input values
    scanf ( "%d" , & n ) ; 
    scanf ( "%s" , s1 ) ; 
    scanf ( "%s" , str ) ; 
    
    // Construct a combined string
    int cnt = 0 ; 
    for ( int i = 0 ; i < n ; i ++ ) 
        b [ ++ cnt ] = str [ i ] ; 
    for ( int i = 0 ; i < n ; i ++ ) 
        b [ ++ cnt ] = s1 [ i ] ; 
    
    // Compute the failure array for the combined string
    getFail ( b , cnt ) ; 
    
    // Calculate the result based on the failure array
    int len = ( f [ cnt ] < n ) ? f [ cnt ] : n ; 
    
    // Print the result
    printf ( "%d\n" , 2 * n - len ) ; 
    
    return 0 ; 
} 

