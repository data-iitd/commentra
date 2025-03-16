
#include <bits/stdc++.h>
using namespace std;

int twos_in_factorial ( int n ) {
    return n - __builtin_popcount ( n ) ;
}

bool parity_of_nCr ( int n, int i ) {
    int f = twos_in_factorial ;
    return f ( n ) - f ( n - i ) - f ( i ) > 0 ;
}

int main ( ) {
    int n ;
    cin >> n ;
    vector < int > nums ( n ) ;
    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> nums [ i ] ;
        nums [ i ] -- ;
    }
    bool no_one = false ;
    if ( find ( nums. begin ( ), nums. end ( ), 1 ) == nums. end ( ) ) {
        nums = vector < int > ( nums. begin ( ), nums. end ( ) ) ;
        transform ( nums. begin ( ), nums. end ( ), nums. begin ( ), [ ] ( int x ) { return x / 2 ; } ) ;
        no_one = true ;
    }
    bool is_odd = false ;
    for ( int i = 0 ; i < nums. size ( ) ; i ++ ) {
        if (! parity_of_nCr ( n - 1, i ) && nums [ i ] % 2 == 1 ) {
            is_odd ^= 1 ;
        }
    }
    if (! is_odd ) {
        cout << 0 << endl ;
    } else {
        cout << ( 1 << no_one ) << endl ;
    }
    return 0 ;
}

