#include <bits/stdc++.h>
using namespace std;

// Define the root function to find the root of a given element in a disjoint set
int root ( int x ) { return x if ( par [ x ] == x ) else root ( par [ x ] ); }

// Define the same function to check if two elements are in the same set
bool same ( int x, int y ) { return root ( x ) == root ( y ); }

// Define the unite function to merge two sets containing the given elements
void unite ( int x, int y ) {
    int x = root ( x ), y = root ( y ) ;
    if ( x!= y ) {
        if ( rank [ x ] < rank [ y ] ) {
            par [ x ] = y ;
            size [ y ] += size [ x ] ;
        } else {
            par [ y ] = x ;
            size [ x ] += size [ y ] ;
            if ( rank [ x ] == rank [ y ] ) rank [ x ] += 1 ;
        }
    }
}

// Read the input, initialize the disjoint set, and process the array
int main ( ) {
    int n ;
    cin >> n ;
    int a [ n ] ;
    for ( int i = 0 ; i < n ; i ++ ) cin >> a [ i ] ;
    int par [ n ], rank [ n ], size [ n ] ;
    for ( int i = 0 ; i < n ; i ++ ) {
        par [ i ] = i ;
        rank [ i ] = 1 ;
        size [ i ] = 1 ;
    }
    int b [ n ] ;
    for ( int i = 0 ; i < n ; i ++ ) b [ a [ i ] - 1 ] = i ;
    int c = 0 ;

    // Process the array in reverse order to calculate the result
    for ( int k = n - 1 ; k >= 0 ; k -- ) {
        int l = r = 1 ;
        if ( k > 0 and a [ k - 1 ] > a [ k ] ) {
            l += size [ root ( k - 1 ) ] ;
            unite ( k - 1, k ) ;
        }
        if ( k + 1 < n and a [ k + 1 ] > a [ k ] ) {
            r += size [ root ( k + 1 ) ] ;
            unite ( k + 1, k ) ;
        }
        c += l * r * a [ k ] ;
    }

    // Print the final result
    cout << c << endl ;
}

