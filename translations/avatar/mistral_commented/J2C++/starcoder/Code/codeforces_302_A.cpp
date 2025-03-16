
#include <bits/stdc++.h>
using namespace std;

int main ( ) {
    int n, k, arr [ ], o = 0, e = 0 ;
    cin >> n >> k ;
    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> arr [ i ] ;
        if ( arr [ i ] == 1 ) ++ o ;
        else ++ e ;
    }
    string res = "" ;
    for ( int i = 0 ; i < k ; i ++ ) {
        int l, r ;
        cin >> l >> r ;
        if ( ( r - l + 1 ) % 2 == 1 ) {
            res += "0\n" ;
        } else {
            if ( ( r - l + 1 ) / 2 <= o ) {
                res += "1\n" ;
            } else {
                res += "0\n" ;
            }
        }
    }
    cout << res ;
    return 0 ;
}

