
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main ( ) {
    vector < int > L;
    string s;
    int r = 1;
    getline ( cin, s );
    getline ( cin, s );
    for ( auto k : string ( s ) ) {
        L.insert ( L.end ( ), int ( k ) - 48, r );
        r += 1;
    }
    getline ( cin, s );
    getline ( cin, s );
    for ( auto j : string ( s ) ) {
        cout << L [ int ( j ) - 1 ] << endl;
    }
    return 0;
}

