#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    int n, m;
    cin >> n >> m;
    vector < int > l ( n );
    for ( int i = 0; i < n; i++ )
        cin >> l [ i ];
    vector < int > l2 ( n );
    for ( int i = 0; i < n; i++ )
        l2 [ i ] = l [ i ] / m;
    int mx = *max_element ( l2.begin ( ), l2.end ( ) );
    for ( int i = 0; i < n; i++ )
        if ( l2 [ i ] == mx )
            ind = i;
    cout << ind + 1 << endl;
    return 0;
}
