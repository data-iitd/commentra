
#include <bits/stdc++.h>
using namespace std;

int main ( ) {
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vector < int > a ( x );
    vector < int > b ( y );
    vector < int > c ( z );
    vector < int > ab ( x * y );
    for ( int i = 0 ; i < x ; i++ ) {
        for ( int j = 0 ; j < y ; j++ ) {
            cin >> a [ i ] >> b [ j ];
            ab [ i * y + j ] = a [ i ] + b [ j ];
        }
    }
    sort ( ab.begin ( ), ab.end ( ), greater < int > ( ) );
    vector < int > abc ( min ( k, x * y ) );
    for ( int i = 0 ; i < min ( k, x * y ) ; i++ ) {
        for ( int j = 0 ; j < z ; j++ ) {
            cin >> c [ j ];
            abc [ i ] = ab [ i ] + c [ j ];
        }
    }
    sort ( abc.begin ( ), abc.end ( ), greater < int > ( ) );
    for ( int i = 0 ; i < k ; i++ ) {
        cout << abc [ i ] << endl;
    }
    return 0;
}

