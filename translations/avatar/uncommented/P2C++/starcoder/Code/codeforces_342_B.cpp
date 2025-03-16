#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    int n, m, s, f, d, i, j, t, l, r, k ;
    cin >> n >> m >> s >> f ;
    if ( s < f ) {
        d = 1 ;
        c = 'R' ;
    }
    else {
        d = - 1 ;
        c = 'L' ;
    }
    string res = "" ;
    i = 1 ;
    j = s ;
    cin >> t >> l >> r ;
    k = 1 ;
    while ( j!= f ) {
        if ( i > t and k < m ) {
            cin >> t >> l >> r ;
            k += 1 ;
        }
        if ( i == t and ( l <= j <= r or l <= j + d <= r ) ) {
            res += 'X' ;
        }
        else {
            res += c ;
            j += d ;
        }
        i += 1 ;
    }
    cout << res ;
    return 0 ;
}
