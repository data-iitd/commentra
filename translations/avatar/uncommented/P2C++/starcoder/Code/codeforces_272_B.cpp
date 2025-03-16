#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main ( ) {
    int n;
    cin >> n;
    vector<int> sequence ( n );
    for ( int i = 0 ; i < n ; i++ )
        cin >> sequence [ i ];
    cout << nPairsWithCommonFX ( sequence ) << endl;
    return 0;
}
int nPairsWithCommonFX ( vector<int> sequence ) {
    map<int, vector<int>> storage;
    vector<int> FXs;
    for ( int value : sequence ) {
        int y = f ( value );
        if ( y not in storage ) {
            storage [ y ] = vector<int> ( { value } );
            FXs.push_back ( y );
        } else {
            storage [ y ].push_back ( value );
        }
    }
    return ( accumulate ( FXs.begin ( ), FXs.end ( ), 0, []( int x, int y ) { return x + y; } ) * accumulate ( FXs.begin ( ), FXs.end ( ), 0, []( int x, int y ) { return x + y; } ) - accumulate ( FXs.begin ( ), FXs.end ( ), 0, []( int x, int y ) { return x + y; } ) ) / 2;
}
int f ( int n ) {
    int y = 1;
    while ( n!= 1 ) {
        if ( n % 2 )
            y += 1;
        n /= 2;
    }
    return y;
}
