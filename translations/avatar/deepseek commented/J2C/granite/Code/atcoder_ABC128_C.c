

#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    // Create a Scanner object to read input from the standard input stream
    int N, M, k, s, x, ans = 0, t, p, i, j;
    scanf ( "%d %d", &N, &M ) ; 
    int *a = ( int * ) malloc ( sizeof ( int ) * N ) ; 
    for ( i = 0 ; i < N ; i ++ ) { 
        a [ i ] = 0 ; 
    } 

    // Read M groups of integers, where each group represents a switch and its corresponding states
    for ( i = 0 ; i < M ; i ++ ) { 
        scanf ( "%d", &k ) ; 
        for ( j = 0 ; j < k ; j ++ ) { 
            scanf ( "%d", &s ) ; 
            s -- ; 
            a [ s ] |= ( 1 << i ) ; 
        } 
    } 

    // Read the final state of each light
    p = 0 ; 
    for ( i = 0 ; i < M ; i ++ ) { 
        scanf ( "%d", &x ) ; 
        p |= ( x << i ) ; 
    } 

    // Calculate the number of possible configurations of switch states that match the final state of the lights
    for ( s = 0 ; s < ( 1 << N ) ; s ++ ) { 
        t = 0 ; 
        for ( i = 0 ; i < N ; i ++ ) { 
            if ( ( ( s >> i ) & 1 ) == 1 ) { 
                t ^= a [ i ] ; 
            } 
        } 
        if ( p == t ) { 
            ans ++ ; 
        } 
    } 

    // Print the result
    printf ( "%d\n", ans ) ; 

    // Free the memory allocated for the array 'a'
    free ( a ) ; 

    return 0 ; 
}
