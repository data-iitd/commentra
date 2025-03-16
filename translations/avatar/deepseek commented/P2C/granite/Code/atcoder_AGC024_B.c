

#include <stdio.h>

void main ( ) {
    // Read the number of elements N
    int N;
    scanf ( "%d", & N ) ;
    // Read the list of integers P
    int P [ N ] ;
    for ( int i = 0 ; i < N ; i ++ ) {
        scanf ( "%d", & P [ i ] ) ;
    }
    // Call the editorial function with N and P as arguments
    editorial ( N, P ) ;
}

void editorial ( int N, int P [ ] ) {
    // If there is only one element, print 0 and return
    if ( N == 1 ) {
        printf ( "0\n" ) ;
        return ;
    }
    // Initialize an array to store positions of elements in P
    int a [ N + 1 ] ;
    for ( int i = 0 ; i <= N ; i ++ ) {
        a [ i ] = 0 ;
    }
    // Populate the array with positions of elements in P
    for ( int i = 0 ; i < N ; i ++ ) {
        a [ P [ i ] ] = i ;
    }
    // Initialize temporary and maximum length variables
    int tmp = 1 ;
    int max_len = 1 ;
    // Iterate through the positions to find the maximum length of consecutive increasing elements
    for ( int i = 1 ; i < N ; i ++ ) {
        if ( a [ i ] < a [ i + 1 ] ) {
            tmp ++ ;
            max_len = tmp > max_len? tmp : max_len ;
        } else {
            tmp = 1 ;
        }
    }
    // Calculate the answer as N - max_len
    int ans = N - max_len ;
    // Print the answer
    printf ( "%d\n", ans ) ;
}

void WA ( int N, int P [ ] ) {
    int tmp = 0 ;
    int ans = 0 ;
    for ( int i = 0 ; i < N ; i ++ ) {
        if ( i == 0 || P [ i - 1 ] + 1 == P [ i ] ) {
            tmp ++ ;
        } else {
            ans = ans > tmp? ans : tmp ;
            tmp = 1 ;
        }
    }
    printf ( "%d\n", N - ans ) ;
}

