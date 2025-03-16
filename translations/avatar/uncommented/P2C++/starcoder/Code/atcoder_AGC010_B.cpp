#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    int n, a [ ], k = 0 ;
    cin >> n ;
    for ( int i = 0 ; i < n ; i ++ )
        cin >> a [ i ] ;
    if ( sum ( a ) % ( n * ( n + 1 ) / 2 ) ) {
        cout << "NO" << endl ;
        return 0 ;
    }
    k = sum ( a ) / ( n * ( n + 1 ) / 2 ) ;
    a [ n ] = a [ 0 ] ;
    if ( sum ( [ ( k - i + j ) % n for i, j in zip ( a + 1, a ) ] ) or sum ( [ ( k - i + j ) / n >= 0 for i, j in zip ( a + 1, a ) ] )!= n ) {
        cout << "NO" << endl ;
        return 0 ;
    }
    cout << "YES" << endl ;
    return 0 ;
}
