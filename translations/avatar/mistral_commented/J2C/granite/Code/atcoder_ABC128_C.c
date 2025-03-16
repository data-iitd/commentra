

#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int N, M ;
    scanf ( "%d %d", & N, & M ) ;

    int * a = ( int * ) malloc ( N * sizeof ( int ) ) ; // Dynamically allocating memory for the ArrayList

    for ( int i = 0 ; i < N ; i ++ ) {
        a [ i ] = 0 ; // Initializing the ArrayList with zeros
    }

    for ( int i = 0 ; i < M ; i ++ ) {
        int k ;
        scanf ( "%d", & k ) ;

        for ( int j = 0 ; j < k ; j ++ ) {
            int s ;
            scanf ( "%d", & s ) ;
            s -- ; // Decreasing the index by 1 as the ArrayList index starts from 0

            a [ s ] |= ( 1 << i ) ; // Updating the value of the element at the given index
        }
    }

    int p = 0 ; // Initializing a variable to store the XOR of all given integers

    for ( int i = 0 ; i < M ; i ++ ) {
        int x ;
        scanf ( "%d", & x ) ;
        p |= ( x << i ) ; // Computing the XOR of the current integer with the previous result
    }

    int ans = 0 ; // Initializing a variable to store the count of valid answers

    for ( int s = 0 ; s < ( 1 << N ) ; s ++ ) { // 1 << N represents 2^N
        int t = 0 ; // Initializing a variable to store the XOR of the current combination with the ArrayList elements

        for ( int i = 0 ; i < N ; i ++ ) {
            if ( ( ( s >> i ) & 1 ) == 1 ) { // Checking if the i-th bit of the current combination is set
                t ^= a [ i ] ; // Updating the XOR of the current combination
            }
        }

        if ( p == t ) {
            ans ++ ; // Incrementing the count of valid answers
        }
    }

    printf ( "%d\n", ans ) ; // Printing the count of valid answers

    free ( a ) ; // Freeing the dynamically allocated memory for the ArrayList

    return 0 ;
}
