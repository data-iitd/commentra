#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string l [ n ];
    for ( int i = 0; i < n; i++ ) {
        cin >> l [ i ];
    }
    string f = "Yes";
    for ( int i = 0; i < n; i++ ) {
        if ( l [ i ] [ 0 ]!= s [ 0 ] ) {
            f = "No";
        }
    }
    for ( int i = 0; i < n - 1; i++ ) {
        if ( l [ i ] [ - 1 ]!= l [ i + 1 ] [ 0 ] ) {
            f = "No";
        }
    }
    cout << f << endl;
    return 0;
}
