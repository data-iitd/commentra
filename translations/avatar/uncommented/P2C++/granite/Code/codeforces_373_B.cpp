
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sum ( ll k ) {
    ll ret = 0;
    ll pw = 10;
    ll len = 1;
    while ( 1 == 1 ) {
        ll cur = min ( pw - 1, k ) ;
        ll prev = pw / 10 ;
        ret += ( cur - prev + 1 ) * len ;
        if ( pw - 1 >= k ) {
            break ;
        }
        len += 1 ;
        pw *= 10 ;
    }
    return ret ;
}

int main() {
    ll w, m, k ;
    cin >> w >> m >> k ;
    ll lo = 0 ;
    ll hi = 1e18 ;
    while ( hi - lo > 1 ) {
        ll md = ( lo + hi ) / 2 ;
        ll c = sum ( m + md - 1 ) - sum ( m - 1 ) ;
        if ( c * k <= w ) {
            lo = md ;
        } else {
            hi = md ;
        }
    }
    cout << lo << endl ;
    return 0 ;
}

