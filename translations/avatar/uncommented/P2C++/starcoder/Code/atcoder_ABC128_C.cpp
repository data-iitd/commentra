#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    int n, m ;
    cin >> n >> m ;
    vector < vector < int > > li ( m ) ;
    for ( int i = 0 ; i < m ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            int x ;
            cin >> x ;
            li [ i ].push_back ( x ) ;
        }
    }
    vector < int > p ( n ) ;
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> p [ i ] ;
    }
    set < int > q ( accumulate ( li.begin ( ), li.end ( ), vector < int > ( ) ).begin ( ), accumulate ( li.begin ( ), li.end ( ), vector < int > ( ) ).end ( ) ) ;
    set < int > r ( accumulate ( p.begin ( ), p.end ( ), vector < int > ( ) ).begin ( ), accumulate ( p.begin ( ), p.end ( ), vector < int > ( ) ).end ( ) ) ;
    set < int > v ( accumulate ( r.begin ( ), r.end ( ), vector < int > ( ) ).begin ( ), accumulate ( r.begin ( ), r.end ( ), vector < int > ( ) ).end ( ) ) ;
    v.erase ( q.begin ( ), q.end ( ) ) ;
    int ans = 0 ;
    for ( int i = 0 ; i <= q.size ( ) ; i++ ) {
        for ( auto s : combinations ( q, i ) ) {
            for ( auto u : li ) {
                if ( ( set < int > ( s ) & set < int > ( u ) ).size ( ) % 2!= p [ u.size ( ) - 1 ] ) {
                    break ;
                }
            } else {
                ans += 1 ;
            }
        }
    }
    cout << ans << endl ;
}
