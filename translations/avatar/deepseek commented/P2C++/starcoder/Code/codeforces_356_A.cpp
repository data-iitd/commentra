
#include <bits/stdc++.h>
using namespace std;

int main ( ) {
    int n, m, l, r, x, t, next_val ;
    cin >> n >> m ;
    vector < int > out ( n, 0 ), comp ( n, 0 ) ;
    for ( int i = 0 ; i < n ; i ++ )
        comp [ i ] = i + 2 ;
    for ( int i = 0 ; i < m ; i ++ ) {
        cin >> l >> r >> x ;
        t = l ;
        while ( t <= r ) {
            next_val = comp [ t - 1 ] ;
            if ( out [ t - 1 ] == 0 && t!= x )
                out [ t - 1 ] = x ;
            comp [ t - 1 ] = r + 1 if t >= x else x ;
            t = next_val ;
        }
    }
    for ( int i = 0 ; i < n ; i ++ )
        cout << out [ i ] << " " ;
    return 0 ;
}

