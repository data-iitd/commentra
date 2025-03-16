
#include <iostream>
#include <cmath>

using namespace std ;

int main ( ) {
    int max = 0 ;
    int n ;
    int beacon [ 1000001 ] ;
    int dp [ 1000001 ] ;

    cin >> n ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int a ;
        cin >> a ;
        beacon [ a ] = i ;
    }

    if ( beacon [ 0 ] != 0 ) dp [ 0 ] = 1 ;

    for ( int i = 1 ; i < 1000001 ; i ++ ) {
        if ( beacon [ i ] != 0 && beacon [ i ] < i ) {
            dp [ i ] = dp [ i - beacon [ i ] - 1 ] + 1 ;
        } else if ( beacon [ i ] != 0 ) {
            dp [ i ] = 1 ;
        } else {
            dp [ i ] = dp [ i - 1 ] ;
        }
        max = max ( max , dp [ i ] ) ;
    }

    cout << n - max ;

    return 0 ;
}

