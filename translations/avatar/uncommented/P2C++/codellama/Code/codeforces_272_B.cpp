#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;
int main ( ) {
    string input;
    getline ( cin , input );
    vector < int > sequence;
    stringstream ss ( input );
    int value;
    while ( ss >> value ) {
        sequence.push_back ( value );
    }
    map < int , vector < int > > storage;
    vector < int > FXs;
    for ( int value : sequence ) {
        int y = f ( value );
        if ( storage.find ( y ) == storage.end ( ) ) {
            storage [ y ] = { value };
            FXs.push_back ( y );
        } else {
            storage [ y ].push_back ( value );
        }
    }
    int result = 0;
    for ( int y : FXs ) {
        result += ( storage [ y ].size ( ) * storage [ y ].size ( ) ) - storage [ y ].size ( );
    }
    result /= 2;
    cout << result << endl;
    return 0;
}
int f ( int n ) {
    int y = 1;
    while ( n != 1 ) {
        if ( n % 2 ) {
            y += 1;
        }
        n /= 2;
    }
    return y;
}
