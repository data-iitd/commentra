#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main ( ) {
    int n, k;
    cin >> n >> k;
    vector < int > coef;
    for ( int i = 1 ; i <= sqrt ( n ) ; i++ ) {
        coef.push_back ( ( n / i ) - ( n / ( i + 1 ) ) );
    }
    coef.push_back ( 1 );
    for ( int i = 0 ; i < coef.size ( ) ; i++ ) {
        coef [ i ] = coef [ i ] * ( n - sum ( coef ) );
    }
    coef.pop_back ( );
    reverse ( coef.begin ( ), coef.end ( ) );
    vector < vector < int > > dp ( k + 1, vector < int > ( coef.size ( ), 0 ) );
    dp [ 0 ] [ 0 ] = 1;
    for ( int i = 1 ; i <= k ; i++ ) {
        for ( int j = 0 ; j < coef.size ( ) ; j++ ) {
            int tmp = 0;
            for ( int l = j ; l < coef.size ( ) ; l++ ) {
                tmp += dp [ i - 1 ] [ l ];
                tmp %= mod;
            }
            dp [ i ] [ j ] = coef [ j ] * tmp;
            dp [ i ] [ j ] %= mod;
        }
    }
    cout << dp [ k ] [ 0 ];
    return 0;
}
