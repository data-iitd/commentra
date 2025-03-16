
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) { 
    int N ; 
    scanf ( "%d" , & N ) ; // Read the size of the array
    int * arr = ( int * ) malloc ( N * sizeof ( int ) ) ; 
    for ( int i = 0 ; i < N ; i ++ ) 
        scanf ( "%d" , & arr [ i ] ) ; // Read the array elements
    
    int * sorted = ( int * ) malloc ( N * sizeof ( int ) ) ; 
    memcpy ( sorted , arr , N * sizeof ( int ) ) ; // Create a copy of the array and sort it
    qsort ( sorted , N , sizeof ( int ) , cmp ) ; 
    
    long total = ( long ) N * ( N + 1 ) / 2 ; // Calculate the total number of elements
    int l = 0 , r = N - 1 ; 
    
    // Implement binary search to find the median
    while ( l < r ) { 
        int mid = l + ( r - l ) / 2 ; 
        int target = sorted [ mid ] ; 
        int cur = 0 ; 
        long cnt = 0 ; 
        long * bit = ( long * ) malloc ( 2 * N + 2 * sizeof ( long ) ) ; 
        
        for ( int x = N + 1 ; x < 2 * N + 2 ; x += x & - x ) 
            bit [ x ] ++ ; // Initialize the binary indexed tree
        
        for ( int i = 0 ; i < N ; i ++ ) { 
            cur += arr [ i ] <= target ? 1 : - 1 ; 
            for ( int x = cur + N + 1 ; x < 2 * N + 2 ; x += x & - x ) 
                bit [ x ] ++ ; // Update the binary indexed tree
            for ( int x = cur + N ; x > 0 ; x -= x & - x ) 
                cnt += bit [ x ] ; // Calculate the count of elements less than or equal to the target
        } 
        
        if ( cnt >= total / 2 + 1 ) 
            r = mid ; // Adjust the search range if the count is sufficient
        else 
            l = mid + 1 ; 
    } 
    
    printf ( "%d\n" , sorted [ l ] ) ; // Return the median value
    free ( arr ) ; 
    free ( sorted ) ; 
    free ( bit ) ; 
    return 0 ; 
} 

int cmp ( const void * a , const void * b ) { 
    return ( * ( int * ) a ) - ( * ( int * ) b ) ; 
} 

