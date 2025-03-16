
#include <iostream>
#include <string>

using namespace std;

string main ( ) {
    int K;
    string S;
    cin >> K >> S;
    if ( S.length ( ) <= K ) {
        return S;
    }
    return S.substr ( 0, K ) + "...";
}

int main ( ) {
    cout << main ( ) << endl;
    return 0;
}

// END-OF-CODE