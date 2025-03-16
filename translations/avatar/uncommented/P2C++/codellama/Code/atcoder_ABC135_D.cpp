#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main ( ) {
    string S;
    cin >> S;
    int n = S.length ( );
    if ( n == 1 ) {
        if ( S [ 0 ] == '5' || S [ 0 ] == '?' ) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
        return 0;
    }
    vector < vector < ll > > dp ( n , vector < ll > ( 13 , 0 ) );
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( i == 0 ) {
            if ( S [ i ] != '?' ) {
                dp [ i ] [ S [ i ] - '0' ] ++;
            } else {
                for ( int j = 0 ; j < 10 ; j ++ ) {
                    dp [ i ] [ j ] ++;
                }
            }
        } else {
            if ( S [ i ] != '?' ) {
                for ( int k = 0 ; k < 13 ; k ++ ) {
                    dp [ i ] [ ( k * 10 + S [ i ] - '0' ) % 13 ] += dp [ i - 1 ] [ k ];
                }
            } else {
                for ( int j = 0 ; j < 10 ; j ++ ) {
                    for ( int k = 0 ; k < 13 ; k ++ ) {
                        dp [ i ] [ ( k * 10 + j ) % 13 ] += dp [ i - 1 ] [ k ];
                    }
                }
            }
            for ( int k = 0 ; k < 13 ; k ++ ) {
                dp [ i ] [ k ] %= mod;
            }
        }
    }
    cout << dp [ n - 1 ] [ 5 ] << endl;
    return 0;
}



