#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n ; // Declare the size of the array
    scanf ( "%d", &n ) ; // Read the size of the array
    int *arr = ( int * ) malloc ( n * sizeof ( int ) ) ; // Initialize the array of size n
    
    // Read n integers into the array
    for ( int i = 0 ; i < n ; i ++ ) {
        scanf ( "%d", &arr [ i ] ) ;
    }
    
    // Initialize ans with the value of the first element plus 1
    int ans = arr [ 0 ] + 1 ;
    
    // Iterate through the array and update ans
    for ( int i = 1 ; i < n ; i ++ ) {
        ans += abs ( arr [ i ] - arr [ i - 1 ] ) + 2 ;
    }
    
    // Print the final value of ans
    printf ( "%d\n", ans ) ;
    
    return 0 ;
}

