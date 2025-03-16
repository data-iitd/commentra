
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int N = 1e5 + 10;

bool ok ( string last4 ) {
    for ( int i = 0; i < 4; i++ ) {
        string t = last4;
        if ( i >= 1 ) swap ( t [ i ], t [ i - 1 ] );
        if ( count ( t.begin(), t.end(), 'A' ) + count ( t.begin(), t.end(), 'G' ) + count ( t.begin(), t.end(), 'C' ) >= 1 ) return false;
    }
    return true;
}

int dfs ( int cur, string last3 ) {
    if ( memo [ cur ]. count ( last3 ) ) return memo [ cur ] [ last3 ];
    if ( cur == n ) return 1;
    int ret = 0;
    for ( char c : "ACGT" ) {
        if ( ok ( last3 + c ) ) {
            ret = ( ret + dfs ( cur + 1, last3.substr ( 1 ) + c ) ) % mod;
        }
    }
    memo [ cur ] [ last3 ] = ret;
    return ret;
}

int main () {
    ios_base::sync_with_stdio ( false );
    cin.tie ( 0 );
    cout.tie ( 0 );
    cin >> n;
    cout << dfs ( 0, "TTT" ) << endl;
    return 0;
}

