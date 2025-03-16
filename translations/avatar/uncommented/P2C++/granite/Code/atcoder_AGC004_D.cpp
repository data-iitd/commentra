
#include <bits/stdc++.h>
using namespace std;

int dfs ( vector < set < int >> &links, int n, int k, int v, int p ) {
    int height_from_leaf = 0;
    int cut_count = 0;
    for ( auto u : links [ v ] ) {
        if ( u == 0 ) {
            continue;
        }
        int hgt, cut = dfs ( links, n, k, u, v );
        height_from_leaf = max ( height_from_leaf, hgt );
        cut_count += cut;
    }
    height_from_leaf += 1;
    if ( p!= 0 && height_from_leaf == k ) {
        height_from_leaf = 0;
        cut_count += 1;
    }
    return height_from_leaf, cut_count;
}

int main ( ) {
    int n, k;
    cin >> n >> k;
    vector < set < int >> links ( n );
    for ( int i = 0 ; i < n ; i ++ ) {
        int a;
        cin >> a;
        a --;
        links [ a ].insert ( i );
    }
    int _, ans;
    tie ( _, ans ) = dfs ( links, n, k, 0, 0 );
    if ( ans == 0 ) {
        ans = 1;
    }
    cout << ans << endl;
}

