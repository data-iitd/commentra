#include <bits/stdc++.h>
using namespace std;
int solve ( int n, vector < vector < int > > ls_xyh ) {
    int x0 = -1;
    for ( int i = 0 ; i < n ; i++ ) {
        if ( ls_xyh [ i ] [ 2 ] > 0 ) {
            x0 = ls_xyh [ i ] [ 0 ];
            break;
        }
    }
    vector < vector < int > > cands;
    for ( int i = 0 ; i < 101 ; i++ ) {
        for ( int j = 0 ; j < 101 ; j++ ) {
            int h = 0;
            for ( int k = 0 ; k < n ; k++ ) {
                h = max ( h, ls_xyh [ k ] [ 2 ] - abs ( ls_xyh [ k ] [ 0 ] - i ) - abs ( ls_xyh [ k ] [ 1 ] - j ) );
            }
            cands.push_back ( { i, j, h } );
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        int x = ls_xyh [ i ] [ 0 ];
        int y = ls_xyh [ i ] [ 1 ];
        int h = ls_xyh [ i ] [ 2 ];
        vector < vector < int > > cands2;
        for ( int j = 0 ; j < cands.size ( ) ; j++ ) {
            int cx = cands [ j ] [ 0 ];
            int cy = cands [ j ] [ 1 ];
            int ch = cands [ j ] [ 2 ];
            if ( ch - abs ( cx - x ) - abs ( cy - y ) >= 0 ) {
                cands2.push_back ( { cx, cy, ch } );
            }
        }
        cands = cands2;
    }
    int xx = cands [ 0 ] [ 0 ];
    int yy = cands [ 0 ] [ 1 ];
    int hh = cands [ 0 ] [ 2 ];
    return to_string ( xx ) + " " + to_string ( yy ) + " " + to_string ( hh );
}
int main ( ) {
    int n;
    cin >> n;
    vector < vector < int > > ls_xyh;
    for ( int i = 0 ; i < n ; i++ ) {
        int x, y, h;
        cin >> x >> y >> h;
        ls_xyh.push_back ( { x, y, h } );
    }
    cout << solve ( n, ls_xyh ) << endl;
    return 0;
}
