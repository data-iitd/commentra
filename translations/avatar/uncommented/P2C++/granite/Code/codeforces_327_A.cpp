
#include <bits/stdc++.h>
using namespace std;

vector < int > find ( string s, char ch ) {
    vector < int > indices;
    for ( int i = 0 ; i < s.length ( ) ; i ++ ) {
        if ( s [ i ] == ch ) {
            indices.push_back ( i );
        }
    }
    return indices;
}

int main ( ) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if ( count ( s.begin ( ), s.end ( ), '0' ) == 0 ) {
        cout << n - 1 << endl;
    } else {
        vector < int > indices = find ( s, '0' );
        if ( indices.size ( ) == 1 ) {
            cout << n << endl;
        } else {
            int maximum = 0;
            for ( int i = 0 ; i < indices.size ( ) ; i ++ ) {
                for ( int j = i + 1 ; j < indices.size ( ) ; j ++ ) {
                    maximum = max ( maximum, 2 + 2 * ( abs ( indices [ i ] - indices [ j ] ) ) - ( abs ( indices [ i ] - indices [ j ] ) - 1 );
                }
            }
            cout << count ( s.begin ( ), s.end ( ), '1' ) + maximum << endl;
        }
    }
    return 0;
}

