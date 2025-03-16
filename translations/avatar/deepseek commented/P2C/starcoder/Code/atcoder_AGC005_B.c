#include <stdio.h>
#include <stdlib.h>

// Define the root function to find the root of a given element in a disjoint set
int root ( int x ) {
    return x == par [ x ]? x : root ( par [ x ] );
}

// Define the same function to check if two elements are in the same set
int same ( int x, int y ) {
    return root ( x ) == root ( y );
}

// Define the unite function to merge two sets containing the given elements
void unite ( int x, int y ) {
    int x_root = root ( x ), y_root = root ( y );
    if ( x_root!= y_root ) {
        if ( rank [ x_root ] < rank [ y_root ] ) {
            par [ x_root ] = y_root;
            size [ y_root ] += size [ x_root ];
        } else {
            par [ y_root ] = x_root;
            size [ x_root ] += size [ y_root ];
            if ( rank [ x_root ] == rank [ y_root ] ) rank [ x_root ] += 1;
        }
    }
}

// Read the input, initialize the disjoint set, and process the array
int main ( ) {
    int n, * a, * par, * rank, * size, * b, c = 0;
    scanf ( "%d", &n );
    a = ( int * ) malloc ( n * sizeof ( int ) );
    par = ( int * ) malloc ( n * sizeof ( int ) );
    rank = ( int * ) malloc ( n * sizeof ( int ) );
    size = ( int * ) malloc ( n * sizeof ( int ) );
    b = ( int * ) malloc ( n * sizeof ( int ) );
    for ( int i = 0 ; i < n ; i ++ ) {
        scanf ( "%d", &a [ i ] );
        b [ a [ i ] - 1 ] = i;
    }
    for ( int i = 0 ; i < n ; i ++ ) {
        par [ i ] = i;
        rank [ i ] = 1;
        size [ i ] = 1;
    }
    for ( int k = n - 1 ; k >= 0 ; k -- ) {
        int l = r = 1;
        if ( k > 0 && a [ k - 1 ] > a [ k ] ) {
            l += size [ root ( k - 1 ) ];
            unite ( k - 1, k );
        }
        if ( k + 1 < n && a [ k + 1 ] > a [ k ] ) {
            r += size [ root ( k + 1 ) ];
            unite ( k + 1, k );
        }
        c += l * r * a [ k ];
    }
    printf ( "%d", c );
    return 0;
}

