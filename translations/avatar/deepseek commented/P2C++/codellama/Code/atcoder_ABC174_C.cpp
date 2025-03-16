#include <bits/stdc++.h>
using namespace std;

int main ( ) {
    int k , t = 0;
    cin >> k;
    for ( int i = 1 ; i <= k ; i++ ) {
        t = ( t % k ) * 10 + 7;
        if ( t % k == 0 ) {
            cout << i << endl;
            break;
        }
    }
    if ( i > k ) {
        cout << - 1 << endl;
    }
    return 0;
}

