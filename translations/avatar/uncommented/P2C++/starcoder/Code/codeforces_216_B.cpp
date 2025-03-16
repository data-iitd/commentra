#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    int n, m, ans = 0;
    cin >> n >> m;
    vector < set < int > > g ( n + 1 );
    for ( int i = 0 ; i < m ; i++ ) {
        int a, b;
        cin >> a >> b;
        g [ a ].insert ( b );
        g [ b ].insert ( a );
    }
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( g [ i ].size ( ) == 0 ) {
            ans++;
            continue;
        }
        set < int > seen;
        int nodes = 0, edges = 0;
        queue < int > q;
        q.push ( i );
        seen.insert ( i );
        while (!q.empty ( ) ) {
            int u = q.front ( );
            q.pop ( );
            nodes++;
            for ( int v : g [ u ] ) {
                if ( v not in seen ) {
                    q.push ( v );
                    seen.insert ( v );
                }
            }
        }
        edges = seen.size ( );
        if ( nodes > 1 and nodes % 2 == 1 and 2 * nodes == edges ) {
            ans++;
        }
    }
    if ( ( n - ans ) % 2 == 1 ) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}
