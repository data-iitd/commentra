
#include <iostream>
#include <string>

using namespace std ;

int main ( ) {

    int K ;

    cin >> K ;

    string S ;

    cin >> S ;

    if ( S.length ( ) <= K ) {

        cout << S << endl ;

    } else {

        cout << S.substr ( 0, K ) << "..." << endl ;

    }

    return 0 ;

}

