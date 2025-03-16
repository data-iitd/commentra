#include <stdio.h> 
#include <string.h> 

int main ( ) { 
    // Read the input string
    char s [ 100000 ] ; 
    scanf ( "%s" , s ) ; 
    
    // Initialize the cumulative array to store counts of consecutive identical characters
    int cum [ 100000 ] ; 
    cum [ 0 ] = cum [ strlen ( s ) ] = 0 ; 
    
    // Fill the cumulative array with counts of consecutive identical characters
    for ( int i = 1 ; i < strlen ( s ) ; i ++ ) { 
        if ( s [ i ] == s [ i - 1 ] ) 
            cum [ i ] = cum [ i - 1 ] + 1 ; 
        else 
            cum [ i ] = cum [ i - 1 ] ; 
    } 
    
    // Read the number of queries
    int q ; 
    scanf ( "%d" , &q ) ; 
    
    // Process each query
    while ( q -- != 0 ) { 
        int l , r ; 
        scanf ( "%d %d" , &l , &r ) ; 
        
        // Calculate and print the result for the query
        printf ( "%d\n" , cum [ r ] - cum [ l - 1 ] ) ; 
    } 
    
    return 0 ; 
} 

