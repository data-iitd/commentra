
#include <iostream>
#include <string>

using namespace std;

int main ( ) {
    string l;
    cin >> l;
    l = l.substr ( 0, l.find ( '.' ) );
    string s = l.substr ( 0, 1 );
    string p = l.substr ( 2, 1 );
    int i = stoi ( p );
    if ( s.back ( ) == '9' ) {
        cout << "GOTO Vasilisa." << endl;
    } else if ( s.back ( )!= '9' && i < 5 ) {
        cout << s << endl;
    } else {
        s = to_string ( stoi ( s ) + 1 );
        cout << s << endl;
    }
    return 0;
}

