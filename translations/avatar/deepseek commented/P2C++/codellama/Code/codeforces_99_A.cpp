
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main () {
    string l;
    cin >> l;
    stringstream ss ( l );
    string s, p;
    getline ( ss, s, '.' );
    getline ( ss, p, '.' );
    int i = stoi ( p.substr ( 0, 1 ) );
    if ( s.substr ( s.length ( ) - 1, 1 ) == "9" ) {
        cout << "GOTO Vasilisa." << endl;
    } else if ( s.substr ( s.length ( ) - 1, 1 ) != "9" && i < 5 ) {
        cout << s << endl;
    } else {
        s = to_string ( stoi ( s ) + 1 );
        cout << s << endl;
    }
    return 0;
}

