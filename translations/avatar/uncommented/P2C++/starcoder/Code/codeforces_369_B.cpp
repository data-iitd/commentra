#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    int n, k, l, r, sa, sk ;
    cin >> n >> k >> l >> r >> sa >> sk ;
    int ans [ n ] ;
    for ( int i = 0 ; i < k ; i++ ) ans [ i ] = sk + 1 ;
    for ( int i = k ; i < n ; i++ ) ans [ i ] = sa - sk + 1 ;
    for ( int i = 0 ; i < n ; i++ ) cout << ans [ i ] << " " ;
    return 0 ;
}
