#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main ( ) { 
    // Read the number of elements
    int n ; 
    scanf ( "%d", & n ) ; 
    
    // Initialize arrays to store the input values
    int a [ n + 1 ] ; 
    int b [ n + 1 ] ; 
    int num [ n + 1 ] ; 
    
    // Read the elements of array a
    for ( int i = 1 ; i <= n ; i ++ ) 
        scanf ( "%d", & a [ i ] ) ; 
    
    // Read the elements of array b
    for ( int i = 1 ; i <= n ; i ++ ) 
        scanf ( "%d", & b [ i ] ) ; 
    
    // Count the occurrences of each element in array b
    for ( int i = 1 ; i <= n ; i ++ ) 
        num [ b [ i ] ] ++ ; 
    
    // Initialize variables to store the result
    char ss [ 1000 ] = "" ; 
    int ans = 0 ; 
    bool st [ n + 1 ] ; 
    
    // Iterate through the elements of array a
    for ( int i = 1 ; i <= n ; i ++ ) { 
        if ( a [ i ] == 1 ) { 
            // Mark the current element as visited
            st [ i ] = true ; 
            
            // Build the sequence of indices
            char sb [ 1000 ] = "" ; 
            int x = b [ i ] ; 
            char sss [ 1000 ] = "" ; 
            sprintf ( sss, "%d", i ) ; 
            sprintf ( sb, " %s", sss ) ; 
            int s = 1 ; 
            
            // Continue building the sequence until a visited element or mismatch is found
            while ( ! st [ x ] && num [ x ] == 1 && x != 0 && a [ x ] != 1 ) { 
                sss = "" ; 
                sprintf ( sss, "%d", x ) ; 
                sprintf ( sb, " %s", sss ) ; 
                st [ x ] = true ; 
                x = b [ x ] ; 
                s ++ ; 
            } 
            
            // Update the result if a longer sequence is found
            if ( s > ans ) { 
                ans = s ; 
                strcpy ( ss, sb ) ; 
            } 
        } 
    } 
    
    // Print the result
    printf ( "%d\n", ans ) ; 
    printf ( "%s\n", ss ) ; 
    
    return 0 ; 
} 

