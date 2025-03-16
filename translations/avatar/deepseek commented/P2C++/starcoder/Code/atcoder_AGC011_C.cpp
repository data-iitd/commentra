#include <bits/stdc++.h>
using namespace std;

int main ( ) {
    int n, m, ci, cb, cc, vis [ 10001 ], g [ 10001 ] [ 10001 ], u, v ;
    cin >> n >> m ;
    ci = cb = cc = 0 ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 1 ; j <= n ; j ++ ) {
            g [ i ] [ j ] = 0 ;
        }
    }
    for ( int i = 0 ; i < m ; i ++ ) {
        cin >> u >> v ;
        g [ u ] [ v ] = 1 ;
        g [ v ] [ u ] = 1 ;
    }
    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( vis [ i ] == 0 ) {
            if ( g [ i ] [ i ] == 0 ) {
                ci ++ ;
            }
            else {
                if ( dfs ( i, 1 ) ) {
                    cb ++ ;
                }
                else {
                    cc ++ ;
                }
            }
        }
    }
    cout << ci * ci + 2 * ci * ( n - ci ) + cc * cc + 2 * cb * cc + 2 * cb * cb << endl ;
}

int dfs ( int u, int col ) {
    vis [ u ] = col ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( g [ u ] [ i ] == 1 && vis [ i ] == 0 ) {
            if ( dfs ( i, 3 - col ) == 0 ) {
                return 0 ;
            }
        }
    }
    return 1 ;
}

