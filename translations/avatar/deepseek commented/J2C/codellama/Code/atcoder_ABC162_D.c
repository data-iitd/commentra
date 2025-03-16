
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int n ; // Read the integer n
    char s [ 1000000 ] ; // Read the string s
    scanf ( "%d %s" , &n , s ) ;
    
    long rc = 0 ; // Counter for 'R' characters
    long gc = 0 ; // Counter for 'G' characters
    long bc = 0 ; // Counter for 'B' characters
    
    // Count the number of 'R', 'G', and 'B' characters in the string s
    for ( int i = 0 ; i < strlen ( s ) ; i ++ ) {
        if ( s [ i ] == 'R' ) {
            rc ++ ;
        } else if ( s [ i ] == 'G' ) {
            gc ++ ;
        } else {
            bc ++ ;
        }
    }
    
    long result = rc * gc * bc ; // Calculate the initial product of counts
    
    // Iterate through possible pairs of indices i and k where i < k
    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int k = i + 1 ; k <= n ; k ++ ) {
            if ( ( i + k ) % 2 == 0 ) { // Check if the sum of indices is even
                char is = s [ i - 1 ] ; // Character at index i-1
                char ks = s [ k - 1 ] ; // Character at index k-1
                char js = s [ ( ( i + k ) / 2 ) - 1 ] ; // Character at the middle index
                
                // Check if the characters are all different and not equal to each other
                if ( is != ks && ks != js && js != is ) {
                    result -- ; // Decrement the result if conditions are met
                }
            }
        }
    }
    
    printf ( "%ld\n" , result ) ; // Print the final result
    
    return 0 ;
}

