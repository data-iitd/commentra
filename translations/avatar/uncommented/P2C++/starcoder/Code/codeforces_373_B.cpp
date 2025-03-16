#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    int w, m, k ;
    cin >> w >> m >> k ;
    int lo = 0, hi = 1e18 ;
    while ( hi - lo > 1 ) {
        int md = ( lo + hi ) / 2 ;
        int c = sum ( m + md - 1 ) - sum ( m - 1 ) ;
        if ( c * k <= w ) {
            lo = md ;
        } else {
            hi = md ;
        }
    }
    cout << lo << endl ;
    return 0 ;
}
