#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    int h, w;
    cin >> h >> w;
    vector < vector < int > > graph ( h, vector < int > ( w, 0 ) );
    for ( int i = 0 ; i < h ; i++ ) {
        for ( int j = 0 ; j < w ; j++ ) {
            char c;
            cin >> c;
            if ( c == '#' ) {
                graph [ i ] [ j ] = 0;
            }
        }
    }
    for ( int i = 0 ; i < w - 1 ; i++ ) {
        for ( int j = 0 ; j < h ; j++ ) {
            if ( graph [ j ] [ i ] == 0 ) {
                graph [ j ] [ i + 1 ] = 1;
            } else {
                graph [ j ] [ i + 1 ] = 0;
            }
        }
    }
    for ( int i = 0 ; i < w - 1 ; i++ ) {
        for ( int j = 0 ; j < h ; j++ ) {
            if ( graph [ j ] [ i ] == 0 ) {
                graph [ j ] [ i - 1 ] = 1;
            } else {
                graph [ j ] [ i - 1 ] = 0;
            }
        }
    }
    for ( int i = 0 ; i < h - 1 ; i++ ) {
        for ( int j = 0 ; j < w ; j++ ) {
            if ( graph [ i ] [ j ] == 0 ) {
                graph [ i + 1 ] [ j ] = 1;
            } else {
                graph [ i + 1 ] [ j ] = 0;
            }
        }
    }
    for ( int i = 0 ; i < h - 1 ; i++ ) {
        for ( int j = 0 ; j < w ; j++ ) {
            if ( graph [ i ] [ j ] == 0 ) {
                graph [ i - 1 ] [ j ] = 1;
            } else {
                graph [ i - 1 ] [ j ] = 0;
            }
        }
    }
    int ans = 0;
    for ( int i = 0 ; i < h ; i++ ) {
        for ( int j = 0 ; j < w ; j++ ) {
            if ( graph [ i ] [ j ] > ans ) {
                ans = graph [ i ] [ j ];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
