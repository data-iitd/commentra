#include <bits/stdc++.h>
using namespace std;
string run ( string s, string t ) {
    vector <int> ss = vector <int> ( ), tt = vector <int> ( ) ;
    for ( int i = 0 ; i < s.size ( ) ; i++ ) {
        ss.push_back ( s[i] - 'a' ) ;
    }
    for ( int i = 0 ; i < t.size ( ) ; i++ ) {
        tt.push_back ( t[i] - 'a' ) ;
    }
    sort ( ss.begin ( ), ss.end ( ) ) ;
    sort ( tt.begin ( ), tt.end ( ) ) ;
    if ( ss == tt ) {
        return "Yes" ;
    }
    else {
        return "No" ;
    }
}
int main ( ) {
    string s, t ;
    cin >> s >> t ;
    cout << run ( s, t ) << endl ;
}
