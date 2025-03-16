#include <iostream>
#include <string>
#include <map>
using namespace std;

int ok ( string last4 ) {
    for ( int i = 0 ; i < 4 ; i ++ ) {
        string t = last4;
        if ( i >= 1 ) {
            t [ i ] , t [ i - 1 ] = t [ i - 1 ] , t [ i ];
        }
        if ( t.find ( "AGC" ) != string::npos ) {
            return false;
        }
    }
    return true;
}

int dfs ( int cur , string last3 ) {
    if ( memo [ cur ] [ last3 ] != -1 ) {
        return memo [ cur ] [ last3 ];
    }
    if ( cur == n ) {
        return 1;
    }
    int ret = 0;
    for ( int i = 0 ; i < 4 ; i ++ ) {
        string c = "ACGT" [ i ];
        if ( ok ( last3 + c ) ) {
            ret = ( ret + dfs ( cur + 1 , last3.substr ( 1 ) + c ) ) % mod;
        }
    }
    memo [ cur ] [ last3 ] = ret;
    return ret;
}

int main ( ) {
    int n , mod , ret;
    cin >> n >> mod;
    map < string , int > memo [ n + 1 ];
    for ( int i = 0 ; i <= n ; i ++ ) {
        for ( int j = 0 ; j < 4 ; j ++ ) {
            memo [ i ] [ "ACGT" [ j ] ] = -1;
        }
    }
    ret = dfs ( 0 , "TTT" );
    cout << ret << endl;
    return 0;
}

