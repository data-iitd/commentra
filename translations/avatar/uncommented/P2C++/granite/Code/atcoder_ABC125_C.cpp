
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd ( int a, int b ) {
    if ( b == 0 ) return a;
    return gcd ( b, a % b );
}

void ruiseki_lr ( vector < int > &array ) {
    int e = 0;
    int n = array.size ( );
    vector < int > left ( n + 1, e );
    vector < int > right ( n + 1, e );
    auto op = [ & ] ( int a, int b ) { return gcd ( a, b ); };
    for ( int i = 0; i < n; i++ ) {
        left [ i + 1 ] = op ( left [ i ], array [ i ] );
    }
    for ( int i = n - 1; i >= 0; i-- ) {
        right [ i ] = op ( right [ i + 1 ], array [ i ] );
    }
}

int main ( ) {
    int n;
    cin >> n;
    vector < int > a ( n );
    for ( int i = 0; i < n; i++ ) {
        cin >> a [ i ];
    }
    ruiseki_lr ( a );
    int ans = 0;
    for ( int i = 0; i < n; i++ ) {
        ans = max ( gcd ( a [ i ], right [ i + 1 ] ), ans );
    }
    cout << ans << endl;
}
