#include <iostream>
using namespace std;
int main ( ) {
    int n, m, r, c;
    cin >> n >> m;
    bool b [ 2 * n + 1 ];
    for ( int i = 0 ; i < 2 * n + 1 ; i ++ ) b [ i ] = 1;
    for ( int i = 0 ; i < m ; i ++ ) {
        cin >> r >> c;
        b [ r - 1 ] = b [ n + c - 1 ] = 0;
    }
    if ( n % 2 && b [ n / 2 ] && b [ n + n / 2 ] ) b [ n / 2 ] = 0;
    cout << sum ( b ) << endl;
    return 0;
}
