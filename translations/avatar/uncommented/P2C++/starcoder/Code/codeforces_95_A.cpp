#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
int main ( ) {
    int pya;
    cin >> pya;
    vector<string> arre;
    while ( pya ) {
        pya--;
        arre.push_back ( cin.get ( ).lower ( ) );
    }
    string oString;
    cin >> oString;
    string lowString = oString.lower ( );
    char letter1 = cin.get ( ) [ 0 ].lower ( );
    char letter2 = 'a' if letter1.lower ( )!= 'a' else 'b';
    vector<int> valid ( oString.size ( ), 0 );
    set<int> setcito;
    for ( auto x : arre ) {
        if ( lowString.find ( x ) >= 0 ) {
            int wat = 0;
            while ( true ) {
                int index = lowString.find ( x, wat );
                if ( index < 0 ) {
                    break;
                }
                for ( int i = index ; i < index + x.size ( ) ; i++ ) {
                    setcito.insert ( i );
                }
                wat = index + 1;
            }
        }
    }
    for ( int i : setcito ) {
        char letter = letter1 if lowString [ i ]!= letter1 else letter2;
        oString [ i ] = letter if oString [ i ].islower ( ) else letter.upper ( );
    }
    for ( char x : oString ) {
        cout << x;
    }
    cout << endl;
    return 0;
}
