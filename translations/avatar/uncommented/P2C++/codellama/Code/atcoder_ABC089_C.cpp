
#include <bits/stdc++.h>
using namespace std;

int main ( ) {
    int N;
    cin >> N;
    vector < string > S ( N );
    for ( int i = 0 ; i < N ; i++ ) cin >> S [ i ];
    vector < string > march ( 5 , "M" );
    march [ 1 ] = "A";
    march [ 2 ] = "R";
    march [ 3 ] = "C";
    march [ 4 ] = "H";
    vector < int > march_lis ( 5 , 0 );
    for ( int i = 0 ; i < N ; i++ ) {
        if ( S [ i ][ 0 ] == 'M' || S [ i ][ 0 ] == 'm' ) march_lis [ 0 ]++;
        else if ( S [ i ][ 0 ] == 'A' || S [ i ][ 0 ] == 'a' ) march_lis [ 1 ]++;
        else if ( S [ i ][ 0 ] == 'R' || S [ i ][ 0 ] == 'r' ) march_lis [ 2 ]++;
        else if ( S [ i ][ 0 ] == 'C' || S [ i ][ 0 ] == 'c' ) march_lis [ 3 ]++;
        else if ( S [ i ][ 0 ] == 'H' || S [ i ][ 0 ] == 'h' ) march_lis [ 4 ]++;
    }
    int ans = 0;
    for ( int i = 0 ; i < 3 ; i++ ) {
        for ( int j = i + 1 ; j < 4 ; j++ ) {
            for ( int k = j + 1 ; k < 5 ; k++ ) {
                ans += march_lis [ i ] * march_lis [ j ] * march_lis [ k ];
            }
        }
    }
    cout << ans << endl;
    return 0;
}



