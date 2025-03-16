#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main ( ) {
    int N;
    cin >> N;
    vector < int > A ( N );
    for ( int i = 0 ; i < N ; i ++ )
        cin >> A[i];
    int _lcm = 1;
    for ( int i = 0 ; i < N ; i ++ )
        _lcm = _lcm * A[i] / __gcd ( _lcm, A[i] );
    int ans = _lcm * accumulate ( A.begin ( ), A.end ( ), 0, [ ]( int a, int b ) { return ( a + b ) % MOD; } ) % MOD;
    cout << ans << endl;
    return 0;
}
