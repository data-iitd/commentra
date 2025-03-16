#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int N, K;
vector < int > graph [ 100001 ];
int dfs ( int fro, int to, int f ) {
    int caseNum = f;
    int colorNum = K - 1 if ( f == K ) else K - 2;
    for ( int u : graph [ fro ] ) {
        if ( u == to ) continue;
        int pat = dfs ( u, fro, colorNum );
        if ( pat == 0 ) {
            caseNum = 0;
            break;
        }
        caseNum = ( caseNum * pat ) % mod;
        colorNum -= 1;
    }
    return caseNum;
}
int main ( ) {
    cin >> N >> K;
    for ( int i = 0 ; i < N - 1 ; i++ ) {
        int a, b;
        cin >> a >> b;
        graph [ a ].push_back ( b );
        graph [ b ].push_back ( a );
    }
    int ans = dfs ( 0, -1, K );
    cout << ans << endl;
    return 0;
}
