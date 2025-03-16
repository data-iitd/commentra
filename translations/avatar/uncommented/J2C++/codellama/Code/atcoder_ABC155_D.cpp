
#include <bits/stdc++.h>
using namespace std;

int mod = ( int ) 1e9 + 7 ;
int DX [ ] = { - 1 , 0 , 1 , 0 } , DY [ ] = { 0 , - 1 , 0 , 1 } ;
int n ;
long k ;
long a [ ] ;

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    cout.tie ( NULL ) ;
    cin >> n >> k ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a [ i ] ;
    }
    sort ( a , a + n ) ;
    long INF = ( long ) ( 1e18 ) + 1 ;
    long l = - INF ;
    long r = INF ;
    while ( l + 1 < r ) {
        long c = ( l + r ) / 2 ;
        if ( check ( c ) ) l = c ;
        else r = c ;
    }
    cout << l << endl ;
}

bool check ( long x ) {
    long tot = 0 ;
    for ( int i = 0 ; i < n ; i ++ ) {
        long now = a [ i ] ;
        int l = 0 , r = n ;
        if ( now >= 0 ) {
            while ( l < r ) {
                int c = ( l + r ) / 2 ;
                if ( now * a [ c ] < x ) l = c + 1 ;
                else r = c ;
            }
            tot += l ;
        }
        else {
            while ( l < r ) {
                int c = ( l + r ) / 2 ;
                if ( now * a [ c ] >= x ) l = c + 1 ;
                else r = c ;
            }
            tot += ( n - l ) ;
        }
        if ( ( long ) a [ i ] * a [ i ] < x ) tot -- ;
    }
    if ( tot / 2 < k ) return true ;
    else return false ;
}

