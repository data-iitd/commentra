#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    int N, X, A [ 100005 ];
    cin >> N >> X;
    for ( int i = 0 ; i < N ; i ++ )
        cin >> A [ i ];
    int S [ 100005 ];
    S [ 0 ] = 0;
    for ( int i = 1 ; i <= N ; i ++ )
        S [ i ] = S [ i - 1 ] + A [ i - 1 ];
    int ans = INT_MAX;
    for ( int k = 1 ; k <= N ; k ++ ) {
        int E = k * X + 2 * accumulate ( S + k, S + N - 2 * k + 1, 0 );
        ans = min ( ans, E );
    }
    cout << ans + N * X + 5 * S [ N - 1 ] << endl;
    return 0;
}
