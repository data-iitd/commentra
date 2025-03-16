
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main ( ) {
    string line;
    getline ( cin, line ) ;
    stringstream ss ( line ) ;
    vector < int > sequence;
    int value;
    while ( ss >> value ) {
        sequence.push_back ( value ) ;
    }
    return nPairsWithCommonFX ( sequence ) ;
}

int nPairsWithCommonFX ( vector < int > sequence ) {
    map < int, vector < int > > storage;
    vector < int > FXs;
    for ( int value : sequence ) {
        int y = f ( value ) ;
        if ( storage.find ( y ) == storage.end ( ) ) {
            storage [ y ] = vector < int > ( ) ;
            FXs.push_back ( y ) ;
        }
        storage [ y ].push_back ( value ) ;
    }
    int result = 0 ;
    for ( int y : FXs ) {
        result += storage [ y ].size ( ) * storage [ y ].size ( ) ;
    }
    result -= FXs.size ( ) ;
    return result / 2 ;
}

int f ( int n ) {
    int y = 1 ;
    while ( n!= 1 ) {
        if ( n % 2 ) {
            y += 1 ;
        }
        n /= 2 ;
    }
    return y ;
}

// END-OF-CODE