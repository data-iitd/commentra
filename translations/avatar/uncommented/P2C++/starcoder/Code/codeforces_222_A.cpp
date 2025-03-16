#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    int n, k;
    cin >> n >> k;
    vector < int > elems ( n );
    for ( int i = 0 ; i < n ; i++ )
        cin >> elems [ i ];
    auto all_same = [&] ( vector < int > arr ) {
        return all ( [ x == arr [ 0 ] for x in arr ] );
    };
    if ( all_same ( elems ) ) {
        cout << 0 << endl;
        return 0;
    }
    if ( k == 1 ) {
        cout << -1 << endl;
        return 0;
    }
    if (! all_same ( elems.end ( ) - k ) ) {
        cout << -1 << endl;
        return 0;
    }
    int target = elems [ n - 1 ];
    vector < int > to_delete;
    for ( int i = 0 ; i < k - 1 ; i++ )
        to_delete.push_back ( elems [ i ] );
    while ( to_delete.size ( ) && to_delete [ to_delete.size ( ) - 1 ] == target )
        to_delete.pop_back ( );
    cout << to_delete.size ( ) << endl;
    return 0;
}
