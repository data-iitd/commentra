#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool debug = false;
void log ( string text ) {
    if ( debug ) {
        cout << text << endl;
    }
}
void parse_input ( vector < string > & lines ) {
    string line;
    if ( lines.size ( ) == 0 ) {
        debug = false;
        getline ( cin , line );
        lines.push_back ( line );
    } else {
        debug = true;
        lines = vector < string > ( lines.begin ( ) + 1 , lines.end ( ) - 1 );
    }
}
string solve ( string c ) {
    string a = "abcdefghijklmnopqrstuvwxyz";
    int i = a.find ( c );
    return a [ i + 1 ];
}
int main ( ) {
    vector < string > lines;
    parse_input ( lines );
    string result = solve ( lines [ 0 ] );
    if ( result.size ( ) > 1 ) {
        for ( int i = 0 ; i < result.size ( ) ; i ++ ) {
            cout << result [ i ];
        }
    } else {
        cout << result;
    }
    cout << endl;
    return 0;
}
