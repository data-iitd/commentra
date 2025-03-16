#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    int N;
    cin >> N;
    vector < pair < int, int > > XY ( N );
    for ( int i = 0 ; i < N ; i ++ ) {
        cin >> XY [ i ]. first >> XY [ i ]. second;
    }
    for ( int i = 0 ; i < N ; i ++ ) {
        double D [ N ];
        for ( int j = 0 ; j < N ; j ++ ) {
            if ( i == j ) continue;
            D [ j ] = atan2 ( XY [ i ]. first - XY [ j ]. first, XY [ i ]. second - XY [ j ]. second );
        }
        sort ( D, D + N );
        double ans = 0;
        for ( int j = 0 ; j < N ; j ++ ) {
            if ( j == N - 1 ) {
                ans += D [ j ] - D [ 0 ] + 2 * M_PI;
            } else {
                ans += D [ j + 1 ] - D [ j ];
            }
        }
        cout << ans / ( 2 * M_PI ) << endl;
    }
    return 0;
}
