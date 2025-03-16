
#include <bits/stdc++.h>
using namespace std;

string run ( string s, string t ) {
    map < char, int > m;
    for ( char c : s ) {
        m [ c ] += 1;
    }
    vector < int > v;
    for ( auto it : m ) {
        v.push_back ( it.second );
    }
    sort ( v.begin ( ), v.end ( ) );
    map < char, int > n;
    for ( char c : t ) {
        n [ c ] += 1;
    }
    vector < int > w;
    for ( auto it : n ) {
        w.push_back ( it.second );
    }
    sort ( w.begin ( ), w.end ( ) );
    if ( v == w ) {
        return "Yes";
    } else {
        return "No";
    }
}

int main ( ) {
    string s;
    string t;
    cin >> s;
    cin >> t;
    cout << run ( s, t ) << endl;
}

