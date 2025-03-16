#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    int n, m, x;
    cin >> n >> m >> x;
    int c[n][m];
    for ( int i = 0 ; i < n ; i++ )
        for ( int j = 0 ; j < m ; j++ )
            cin >> c[i][j];
    int pre[n];
    for ( int i = 0 ; i < n ; i++ )
        pre[i] = i;
    vector<vector<int>> l;
    for ( int i = 1 ; i <= m ; i++ ) {
        vector<int> temp;
        for ( int j = 0 ; j < (1 << i) ; j++ ) {
            int ca = 0;
            for ( int ii = 0 ; ii < i ; ii++ )
                ca += c[pre[j]][i];
            if ( ca < x )
                temp.push_back(j);
        }
        l.push_back(temp);
    }
    int ans = 0;
    for ( int i = 0 ; i < l.size() ; i++ ) {
        if ( l[i].size() == 0 ) {
            cout << -1 << endl;
            return 0;
        }
        int ca = 0;
        for ( int j = 0 ; j < l[i].size() ; j++ )
            ca += c[pre[l[i][j]]][0];
        if ( ans == 0 )
            ans = ca;
        else
            ans = min ( ans, ca );
    }
    cout << ans << endl;
    return 0;
}
