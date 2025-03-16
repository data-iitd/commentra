#include <iostream>
#include <algorithm>
using namespace std;
int I ( ) {
    int x;
    cin >> x;
    return x;
}
int LI ( ) {
    int x;
    cin >> x;
    return x;
}
int main ( ) {
    int N = I ( );
    int S [ N ];
    for ( int i = 0; i < N; i++ ) {
        cin >> S [ i ];
    }
    sort ( S, S + N, greater < int > ( ) );
    bool flag [ N ];
    for ( int i = 0; i < N; i++ ) {
        flag [ i ] = true;
    }
    int cur [ N ];
    cur [ 0 ] = S [ 0 ];
    flag [ 0 ] = false;
    for ( int i = 0; i < N; i++ ) {
        int j = 0;
        int jM = i + 1;
        for ( int k = 0; k < N; k++ ) {
            if ( flag [ k ] && S [ k ] < cur [ j ] ) {
                cur [ j ] = S [ k ];
                j++;
                flag [ k ] = false;
                if ( j == jM ) {
                    break;
                }
            }
        }
        if ( j != jM ) {
            return cout << "No" << endl;
        }
        sort ( cur, cur + N, greater < int > ( ) );
    }
    return cout << "Yes" << endl;
}



