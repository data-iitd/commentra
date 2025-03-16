
#include <stdio.h>
#include <stdlib.h>

// Define the root function to find the root of a given element in a disjoint set
int root ( int x, int * par ) {
    return x == par [ x ]? x : ( par [ x ] = root ( par [ x ], par ) );
}

// Define the same function to check if two elements are in the same set
int same ( int x, int y, int * par ) {
    return root ( x, par ) == root ( y, par );
}

// Define the unite function to merge two sets containing the given elements
void unite ( int x, int y, int * par, int * rank, int * size ) {
    x = root ( x, par );
    y = root ( y, par );
    if ( x!= y ) {
        if ( rank [ x ] < rank [ y ] ) {
            par [ x ] = y;
            size [ y ] += size [ x ];
        } else {
            par [ y ] = x;
            size [ x ] += size [ y ];
            if ( rank [ x ] == rank [ y ] ) rank [ x ] += 1;
        }
    }
}

// Read the input, initialize the disjoint set, and process the array
int main ( ) {
    int n, * a, * b, * par, * rank, * size, c = 0;
    scanf ( "%d", & n );
    a = ( int * ) malloc ( n * sizeof ( int ) );
    b = ( int * ) malloc ( n * sizeof ( int ) );
    par = ( int * ) malloc ( n * sizeof ( int ) );
    rank = ( int * ) malloc ( n * sizeof ( int ) );
    size = ( int * ) malloc ( n * sizeof ( int ) );
    for ( int i = 0 ; i < n ; i ++ ) {
        scanf ( "%d", a + i );
        b [ a [ i ] - 1 ] = i;
        par [ i ] = i;
        rank [ i ] = 1;
        size [ i ] = 1;
    }

    // Process the array in reverse order to calculate the result
    for ( int k = n - 1 ; ~ k ; k -- ) {
        int l = r = 1;
        if ( k > 0 && a [ k - 1 ] > a [ k ] ) {
            l += size [ root ( k - 1, par ) ];
            unite ( k - 1, k, par, rank, size );
        }
        if ( k + 1 < n && a [ k + 1 ] > a [ k ] ) {
            r += size [ root ( k + 1, par ) ];
            unite ( k + 1, k, par, rank, size );
        }
        c += l * r * a [ k ];
    }

    // Print the final result
    printf ( "%d\n", c );
    return 0;
}

