
#include <bits/stdc++.h>

using namespace std ;

long long min = LLONG_MAX ;

int main ( ) {
    long long a, b, c, d ;
    cin >> a >> b >> c >> d ;
    vector < long long > arr = { a, b, c, d } ;
    string [ ] ops = { "+", "*", "*" } ;
    util ( arr, ops, 0 ) ;
    cout << min << endl ;
    return 0 ;
}

void util ( vector < long long > arr, string [ ] ops, int idx ) {
    if ( idx == 3 ) {
        min = min < arr [ 0 ]? min : arr [ 0 ] ;
        return ;
    }
    for ( int i = 0 ; i < arr.size ( ) ; i ++ ) {
        for ( int j = i + 1 ; j < arr.size ( ) ; j ++ ) {
            vector < long long > a ;
            for ( int k = 0 ; k < arr.size ( ) ; k ++ ) {
                if ( k!= j && k!= i ) {
                    a.push_back ( arr [ k ] ) ;
                }
            }
            long long res ;
            if ( idx < 3 && ops [ idx ].compare ( "+" ) == 0 ) {
                res = arr [ i ] + arr [ j ] ;
            } else {
                res = arr [ i ] * arr [ j ] ;
            }
            a.push_back ( res ) ;
            util ( a, ops, idx + 1 ) ;
        }
    }
}

