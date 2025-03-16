#include <bits/stdc++.h>
using namespace std;

int main ( ) {
    int n;
    cin >> n;
    vector < int > c ( n );
    for ( int i = 0 ; i < n ; i++ )
        cin >> c [ i ];
    sort ( c.begin ( ), c.end ( ), greater < int > ( ) );
    int mod = 1000000007;
    int b = pow ( 2, 2 * n - 2, mod );
    int a = 2 * b % mod;
    int ans = 0;
    for ( int i = 0 ; i < n ; i++ )
        ans += c [ i ] * ( a + i * b );
    cout << ans << endl;
    return 0;
}
