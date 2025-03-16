
#include <bits/stdc++.h>
using namespace std;

int main ( ) {
    int n, m, ans = -1;
    cin >> n >> m;
    vector < vector < int > > count ( n, vector < int > ( n, 0 ) );
    for ( int k = 0 ; k < m ; k++ ) {
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        bool found = false;
        for ( int i = x - 2 ; i <= x + 1 ; i++ ) {
            for ( int j = y - 2 ; j <= y + 1 ; j++ ) {
                if ( i >= 0 and i < n and j >= 0 and j < n ) {
                    count [ i ] [ j ] += 1;
                    if ( count [ i ] [ j ] == 9 ) {
                        found = true;
                        break;
                    }
                }
            }
            if ( found ) break;
        }
        if ( found ) {
            ans = k + 1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
