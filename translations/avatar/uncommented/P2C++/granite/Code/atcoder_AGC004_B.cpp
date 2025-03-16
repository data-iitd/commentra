
#include <bits/stdc++.h>
using namespace std;

int main ( ) {
    int n, x;
    cin >> n >> x;
    vector < int > a ( n );
    for ( int i = 0; i < n; i ++ ) {
        cin >> a [ i ];
    }
    vector < vector < int > > b ( n, vector < int > ( n ) );
    for ( int i = 0; i < n; i ++ ) {
        int m = a [ i ];
        for ( int j = 0; j < n; j ++ ) {
            int k = i - j;
            if ( k < 0 ) {
                k += n;
            }
            m = min ( m, a [ k ] );
            b [ j ] [ i ] = m;
        }
    }
    int m = 1000000000;
    for ( int i = 0; i < n; i ++ ) {
        int sum = 0;
        for ( int j = 0; j < n; j ++ ) {
            sum += b [ j ] [ i ];
        }
        sum += x * i;
        m = min ( m, sum );
    }
    cout << m << endl;
}
END-OF-CODE