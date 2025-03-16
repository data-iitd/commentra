#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define N 1000000
#define Nsq 1000
int main ( ) {
    int N;
    cin >> N;
    int A [ N ];
    for ( int i = 0 ; i < N ; i ++ )
        cin >> A [ i ];
    int M = 1000000;
    int fact [ M ] = { 1 };
    for ( int i = 1 ; i < M ; i ++ )
        fact [ i ] = ( fact [ i - 1 ] * i ) % MOD;
    int inv [ N ] = { 0 };
    inv [ 0 ] = 1;
    for ( int i = 1 ; i < N ; i ++ )
        inv [ i ] = ( inv [ i - 1 ] * ( i + 1 ) ) % MOD;
    for ( int i = 1 ; i < N ; i ++ )
        inv [ i ] = ( inv [ i ] * inv [ i - 1 ] ) % MOD;
    for ( int i = 0 ; i < N ; i ++ )
        inv [ i ] = ( inv [ i ] + MOD - inv [ N - 1 - i ] ) % MOD;
    int ans = 0;
    for ( int i = 0 ; i < N ; i ++ )
        ans = ( ans + A [ i ] * inv [ i ] ) % MOD;
    ans = ( ans * fact [ N ] ) % MOD;
    cout << ans << endl;
    return 0;
}
