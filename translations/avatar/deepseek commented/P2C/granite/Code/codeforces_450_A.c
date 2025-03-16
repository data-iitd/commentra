

#include <stdio.h>

int main ( void ) {
    int n, m, i, mx, ind;
    scanf ( "%d %d", &n, &m );  // Read two integers n and m from input
    int l [ n ];  // Declare an array l of size n to store the input integers
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d", &l [ i ] );  // Read n integers and store them in the array l
    }
    int l2 [ n ];  // Declare an array l2 of size n to store the results
    for ( i = 0 ; i < n ; i ++ ) {
        if ( l [ i ] % m == 0 ) {  // Check if the element is divisible by m
            l2 [ i ] = l [ i ] / m;  // Store the quotient in l2
        } else {
            l2 [ i ] = l [ i ] / m + 1;  // Store the quotient plus one in l2
        }
    }
    mx = l2 [ 0 ];  // Initialize mx to the first element of l2
    for ( i = 1 ; i < n ; i ++ ) {
        if ( l2 [ i ] > mx ) {  // Check if the current element is greater than mx
            mx = l2 [ i ];  // Update mx to the current element
        }
    }
    for ( i = 0 ; i < n ; i ++ ) {
        if ( l2 [ i ] == mx ) {  // Check if the current element is equal to mx
            ind = i;  // Store the index of the current element in ind
        }
    }
    printf ( "%d", ind + 1 );  // Print the index of the maximum value plus one
    return 0;
}
