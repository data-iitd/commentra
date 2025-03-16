
#include <bits/stdc++.h>
using namespace std;
string solve ( int n, vector < vector < int > > ls_xyh ) {
    int x0 = -1;
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( ls_xyh [ i ] [ 2 ] > 0 ) {
            x0 = i;
            break;
        }
    }
    vector < vector < int > > cands;
    for ( int cx = 0 ; cx <= 100 ; cx ++ ) {
        for ( int cy = 0 ; cy <= 100 ; cy ++ ) {
            cands.push_back ( { cx, cy, ls_xyh [ x0 ] [ 2 ] + abs ( cx - ls_xyh [ x0 ] [ 0 ] ) + abs ( cy - ls_xyh [ x0 ] [ 1 ] ) } );
        }
    }
    for ( int i = 0 ; i < n ; i ++ ) {
        vector < vector < int > > ncands;
        for ( auto cand : cands ) {
            if ( max ( cand [ 2 ] - abs ( cand [ 0 ] - ls_xyh [ i ] [ 0 ] ) - abs ( cand [ 1 ] - ls_xyh [ i ] [ 1 ] ), 0 ) == ls_xyh [ i ] [ 2 ] ) {
                ncands.push_back ( cand );
            }
        }
        cands = ncands;
    }
    return to_string ( cands [ 0 ] [ 0 ] ) + " " + to_string ( cands [ 0 ] [ 1 ] ) + " " + to_string ( cands [ 0 ] [ 2 ] );
}
vector < vector < int > > readQuestion ( ) {
    int n;
    cin >> n;
    vector < vector < int > > ls_xyh ( n );
    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < 3 ; j ++ ) {
            cin >> ls_xyh [ i ] [ j ];
        }
    }
    return ls_xyh;
}
int main ( ) {
    cout << solve ( readQuestion ( ) ) << endl;
    return 0;
}
