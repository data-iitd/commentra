#include <iostream>
#include <string>
#include <set>
using namespace std;
int main ( ) {
    int pya;
    cin >> pya;
    string arre [ ] = { };
    while ( pya ) {
        pya -= 1;
        string x;
        cin >> x;
        arre [ pya ] = x;
    }
    string oString;
    cin >> oString;
    string lowString = oString;
    transform ( lowString.begin ( ) , lowString.end ( ) , lowString.begin ( ) , ::tolower );
    string letter1;
    cin >> letter1;
    string letter2 = "a";
    if ( letter1 != "a" ) {
        letter2 = "b";
    }
    bool valid [ ] = { 0 };
    set < int > setcito;
    for ( int i = 0 ; i < arre [ ] ; i++ ) {
        string x = arre [ i ];
        transform ( x.begin ( ) , x.end ( ) , x.begin ( ) , ::tolower );
        int wat = 0;
        while ( true ) {
            int index = lowString.find ( x , wat );
            if ( index < 0 ) {
                break;
            }
            for ( int i = index ; i < index + x.length ( ) ; i++ ) {
                setcito.insert ( i );
            }
            wat = index + 1;
        }
    }
    oString = string ( oString );
    for ( int i : setcito ) {
        string letter = letter1;
        if ( lowString [ i ] != letter1 ) {
            letter = letter2;
        }
        oString [ i ] = letter;
    }
    for ( char x : oString ) {
        cout << x;
    }
    cout << endl;
    return 0;
}
