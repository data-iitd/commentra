
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    // Read the number of elements N
    int N;
    scanf ( "%d", &N );
    // Read the list of integers P
    int *P = ( int * ) malloc ( N * sizeof ( int ) );
    for ( int i = 0 ; i < N ; i++ ) {
        scanf ( "%d", &P [ i ] );
    }
    // Call the editorial function with N and P as arguments
    editorial ( N, P );
    // Free the memory
    free ( P );
    return 0;
}

int editorial ( int N, int *P ) {
    // If there is only one element, print 0 and return
    if ( N == 1 ) {
        printf ( "0\n" );
        return 0;
    }
    // Initialize an array to store positions of elements in P
    int *a = ( int * ) malloc ( ( N + 1 ) * sizeof ( int ) );
    // Populate the array with positions of elements in P
    for ( int i = 0 ; i < N ; i++ ) {
        a [ P [ i ] ] = i;
    }
    // Initialize temporary and maximum length variables
    int tmp = 1;
    int max_len = 1;
    // Iterate through the positions to find the maximum length of consecutive increasing elements
    for ( int i = 0 ; i < N - 1 ; i++ ) {
        if ( a [ i ] < a [ i + 1 ] ) {
            tmp += 1;
            max_len = max ( max_len, tmp );
        } else {
            tmp = 1;
        }
    }
    // Calculate the answer as N - max_len
    int ans = N - max_len;
    // Print the answer
    printf ( "%d\n", ans );
    // Free the memory
    free ( a );
    return 0;
}

