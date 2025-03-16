#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    int N;
    cin >> N;
    vector < int > A ( N );
    for ( int i = 0 ; i < N ; i++ ) {
        cin >> A [ i ];
    }
    int mn = N + 1, mx = - 1;
    for ( int i = 0 ; i < N ; i++ ) {
        if ( i + 1!= A [ i ] ) {
            mn = min ( mn, i );
            mx = max ( mx, i );
        }
    }
    if ( mx == - 1 ) {
        cout << "0 0" << endl;
    } else {
        vector < int > B ( A );
        for ( int i = 0 ; i < mn ; i++ ) {
            B [ i ] = A [ mn + i ];
        }
        for ( int i = 0 ; i < mx ; i++ ) {
            B [ mn + i ] = A [ mx - i - 1 ];
        }
        if ( B == A ) {
            cout << mn + 1 << " " << mx + 1 << endl;
        } else {
            cout << "0 0" << endl;
        }
    }
    return 0;
}
