
#include <bits/stdc++.h>
using namespace std;

int main ( ) {
    int n, m;
    cin >> n >> m;
    vector < vector < int > > li ( m );
    for ( int i = 0 ; i < m ; i ++ ) {
        li [ i ].resize ( n );
        for ( int j = 0 ; j < n ; j ++ ) {
            cin >> li [ i ] [ j ];
        }
    }
    vector < int > p ( n );
    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> p [ i ];
    }
    set < int > q;
    for ( int i = 0 ; i < m ; i ++ ) {
        for ( int j = 0 ; j < n ; j ++ ) {
            q.insert ( li [ i ] [ j ] );
        }
    }
    set < int > r;
    for ( int i = 1 ; i <= n ; i ++ ) {
        r.insert ( i );
    }
    set < int > v = r - q;
    int ans = 0;
    for ( int i = 0 ; i <= q.size ( ) ; i ++ ) {
        for ( auto s : itertools.combinations ( q, i ) ) {
            for ( int j = 0 ; j < m ; j ++ ) {
                set < int > s_ ( s.begin ( ), s.end ( ) );
                if ( ( s_.count ( li [ j ] [ 0 ] ) + s_.count ( li [ j ] [ 1 ] ) ) % 2!= p [ j ] ) {
                    break;
                }
            } else {
                ans += pow ( 2, v.size ( ) );
            }
        }
    }
    cout << ans << endl;
}
