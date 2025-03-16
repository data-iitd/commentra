#include <bits/stdc++.h>
using namespace std;
int n, mod;
int memo [ 1001 ][ 4 ];
bool ok ( string last4 ) {
    for ( int i = 0 ; i < 4 ; i++ ) {
        string t = last4;
        if ( i >= 1 ) swap ( t [ i ], t [ i - 1 ] );
        if ( t.find ( "AGC" )!= string::npos ) return false;
    }
    return true;
}
int dfs ( int cur, string last3 ) {
    if ( memo [ cur ][ last3.length() - 1 ]!= -1 ) return memo [ cur ][ last3.length() - 1 ];
    if ( cur == n ) return 1;
    int ret = 0;
    for ( char c = 'A' ; c <= 'T' ; c++ ) {
        if ( ok ( last3 + c ) ) ret = ( ret + dfs ( cur + 1, last3.substr ( 1 ) + c ) ) % mod;
    }
    memo [ cur ][ last3.length() - 1 ] = ret;
    return ret;
}
int main ( ) {
    cin >> n;
    mod = 1000000007;
    memset ( memo, -1, sizeof memo );
    cout << dfs ( 0, "TTT" ) << endl;
    return 0;
}
