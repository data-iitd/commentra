
#include <bits/stdc++.h>
using namespace std;

int main ( ) {
    string S;
    cin >> S;
    map < char, int > c;
    for ( char i : S ) {
        c [ i ] += 1;
    }
    set < char > Sa ( S.begin ( ), S.end ( ) );
    if ( Sa.size ( )!= 2 ) {
        cout << "No" << endl;
        return 0;
    }
    for ( char i : Sa ) {
        if ( c [ i ]!= 2 ) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}

