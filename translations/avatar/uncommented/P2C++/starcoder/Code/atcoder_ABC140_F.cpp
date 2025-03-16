#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    int N;
    cin >> N;
    vector < int > S ( N );
    for ( int i = 0 ; i < N ; i ++ ) {
        cin >> S [ i ];
    }
    sort ( S.begin ( ), S.end ( ), greater < int > ( ) );
    vector < int > cur;
    cur.push_back ( S [ 0 ] );
    for ( int i = 1 ; i < N ; i ++ ) {
        int j = 0;
        int jM = cur.size ( );
        for ( int k = 0 ; k < N ; k ++ ) {
            if ( S [ k ] < cur [ j ] ) {
                cur.push_back ( S [ k ] );
                j += 1;
                if ( j == jM ) {
                    break;
                }
            }
        }
        sort ( cur.begin ( ), cur.end ( ), greater < int > ( ) );
    }
    if ( cur.size ( ) == N ) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
