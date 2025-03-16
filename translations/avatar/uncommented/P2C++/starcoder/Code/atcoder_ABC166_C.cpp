#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    int n, m ;
    cin >> n >> m ;
    vector < int > p ( n, 0 ) ;
    vector < int > h ( n, 0 ) ;
    map < int, int > hp ;
    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> p [ i ] >> h [ i ] ;
        hp [ p [ i ] ] = h [ i ] ;
    }
    map < int, vector < int > > path ;
    for ( int i = 0 ; i < m ; i ++ ) {
        int a, b ;
        cin >> a >> b ;
        path [ a ].push_back ( b ) ;
        path [ b ].push_back ( a ) ;
    }
    int c = 0 ;
    for ( auto i : path ) {
        int f = 0 ;
        for ( auto j : i.second ) {
            if ( hp [ i.first ] <= hp [ j ] ) {
                f = 1 ;
                break ;
            }
        }
        if ( f == 0 ) {
            c ++ ;
        }
    }
    cout << c << endl ;
}
