#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
string run ( string s , string t ) {
    map < int , int > m;
    for ( int i = 0 ; i < s.size ( ) ; i++ ) {
        m [ s [ i ] ]++;
    }
    for ( int i = 0 ; i < t.size ( ) ; i++ ) {
        m [ t [ i ] ]--;
    }
    for ( auto it = m.begin ( ) ; it != m.end ( ) ; it++ ) {
        if ( it -> second != 0 ) {
            return "No";
        }
    }
    return "Yes";
}
int main ( ) {
    string s , t;
    cin >> s >> t;
    cout << run ( s , t ) << endl;
    return 0;
}
