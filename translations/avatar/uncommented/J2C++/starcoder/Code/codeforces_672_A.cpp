#include <iostream>
#include <string>
using namespace std;

char generateString ( ) {
    string s = "" ;
    for ( int i = 1 ; i <= 1000 ; i ++ ) {
        s += to_string ( i ) ;
    }
    return s [ 1000 - 1 ] ;
}

int main ( ) {
    int n ;
    cin >> n ;
    cout << generateString ( ) [ n - 1 ] << endl ;
    return 0 ;
}

