#include <iostream>
#include <string>
#include <map>
using namespace std;
int main ( ) {
    int n;
    cin >> n;
    map < string, int > s;
    string l [ n ];
    for ( int i = 0; i < n; i++ ) {
        cin >> l [ i ];
        s [ l [ i ] ] += 1;
        if ( s [ l [ i ] ] >= 2 ) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}
