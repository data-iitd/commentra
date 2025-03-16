#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main ( ) {
    vector < int > a;
    string s;
    while ( cin >> s ) {
        a.push_back ( stoi ( s ) );
    }
    for ( int e = 0 ; e < a.size ( ) ; e++ ) {
        if ( a[e] == 0 ) {
            cout << e + 1 << endl;
            break;
        }
    }
    return 0;
}
