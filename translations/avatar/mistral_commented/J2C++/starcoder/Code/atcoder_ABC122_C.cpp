
#include <bits/stdc++.h>

using namespace std ;

int main ( ) {
    int n, q ;
    cin >> n >> q ;
    char c [ n + 1 ] ;
    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> c [ i ] ;
    }
    int range [ q ] [ 2 ] ;
    for ( int i = 0 ; i < q ; i ++ ) {
        cin >> range [ i ] [ 0 ] >> range [ i ] [ 1 ] ;
    }
    int frag [ n + 1 ], rui [ n + 1 ] ;
    for ( int i = 2 ; i <= n ; i ++ ) {
        if ( c [ i - 2 ] == 'A' && c [ i - 1 ] == 'C' ) {
            frag [ i ] ++ ;
        }
        rui [ i ] = rui [ i - 1 ] + frag [ i ] ;
    }
    for ( int i = 0 ; i < q ; i ++ ) {
        int left = range [ i ] [ 0 ], right = range [ i ] [ 1 ] ;
        cout << rui [ right ] - rui [ left ] << endl ;
    }
    return 0 ;
}

