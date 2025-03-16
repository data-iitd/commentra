#include <bits/stdc++.h>

using namespace std ;

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( 0 ) ;
    cout.tie ( 0 ) ;

    int N ;
    cin >> N ;
    int A [ N ] ;
    for ( int n = 0 ; n < N ; n ++ ) {
        cin >> A [ n ] ;
    }

    sort ( A, A + N ) ;

    int min = A [ 0 ] ;
    int max = A [ N - 1 ] ;

    int mins = 0 ;
    int maxs = 0 ;

    for ( int value : A ) {
        if ( value == min ) {
            mins ++ ;
        }
        if ( value == max ) {
            maxs ++ ;
        }
    }

    if ( min == max ) {
        long result = ( max - min ) + 1 ;
        result *= mins ;
        result -= mins * ( mins - 1 ) / 2 ;
        cout << result << endl ;
    } else {
        long result = ( max - min ) ;
        result *= mins ;
        result *= maxs ;
        cout << result << endl ;
    }

    return 0 ;
}

