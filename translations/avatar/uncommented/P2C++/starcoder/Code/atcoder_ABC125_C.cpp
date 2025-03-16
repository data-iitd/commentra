#include <bits/stdc++.h>
using namespace std;
int gcd ( int a, int b ) {
    if ( b == 0 )
        return a;
    return gcd ( b, a % b );
}
int main ( ) {
    int n;
    cin >> n;
    vector < int > a ( n );
    for ( int i = 0 ; i < n ; i++ )
        cin >> a [ i ];
    vector < int > left ( n + 1, 0 );
    vector < int > right ( n + 1, 0 );
    for ( int i = 0 ; i < n ; i++ )
        left [ i + 1 ] = gcd ( left [ i ], a [ i ] );
    for ( int i = n - 1 ; i >= 0 ; i-- )
        right [ i ] = gcd ( right [ i + 1 ], a [ i ] );
    int ans = 0;
    for ( int i = 0 ; i < n ; i++ )
        ans = max ( gcd ( left [ i ], right [ i + 1 ] ), ans );
    cout << ans << endl;
    return 0;
}
