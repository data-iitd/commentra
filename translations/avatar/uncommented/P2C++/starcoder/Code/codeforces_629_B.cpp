#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    int N;
    cin >> N;
    int m [ N ], f [ N ];
    for ( int i = 0 ; i < N ; i ++ ) {
        cin >> m [ i ] >> f [ i ];
    }
    int a, b, c = 0;
    for ( int i = 0 ; i < N ; i ++ ) {
        a += m [ i ];
        b += f [ i ];
        c = min ( a, b );
    }
    cout << c << endl;
    return 0;
}
