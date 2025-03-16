#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    int n, m ;
    cin >> n >> m ;
    vector < int > lst ( n ) ;
    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> lst [ i ] ;
    }
    map < int, int > l ;
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( l [ lst [ i ] ] == 0 ) {
            l [ lst [ i ] ] = 1 ;
        }
        else {
            l [ lst [ i ] ] += 1 ;
        }
    }
    int res = 0 ;
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( l [ lst [ i ] ] > 1 ) {
            res += n - i - l [ lst [ i ] ] ;
            l [ lst [ i ] ] -= 1 ;
        }
        else {
            res += n - i - 1 ;
        }
    }
    cout << res << endl ;
}
