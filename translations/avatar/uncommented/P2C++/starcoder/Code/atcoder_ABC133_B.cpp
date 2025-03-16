#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    int n, d ;
    cin >> n >> d ;
    vector < vector < int > > points ( n ) ;
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < d ; j++ ) {
            int tmp ;
            cin >> tmp ;
            points [ i ].push_back ( tmp ) ;
        }
    }
    int count = 0 ;
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = i + 1 ; j < n ; j++ ) {
            if ( dist ( points [ i ], points [ j ] ).is_integer ( ) ) {
                count++ ;
            }
        }
    }
    cout << count << endl ;
    return 0 ;
}
