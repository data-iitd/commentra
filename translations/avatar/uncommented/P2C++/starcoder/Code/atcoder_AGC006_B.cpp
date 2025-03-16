#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main ( ) {
    int N, X;
    cin >> N >> X;
    vector < int > xs;
    for ( int i = 1 ; i <= N ; i ++ )
        xs.push_back ( i );
    for ( int i = 1 ; i <= N ; i ++ )
        xs.push_back ( N * 2 - i );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i ], xs [ N - 3 + i ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + 2 * ( N - 3 ) ], xs [ i + N - 3 ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        swap ( xs [ i + N - 3 ], xs [ i + 2 * ( N - 3 ) ] );
    for ( int i = 0 ; i < N - 3 ; i ++ )
        sw