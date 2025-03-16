
#include <bits/stdc++.h>
using namespace std;

// Method to check if there's a column filled with 'X' characters in the given string
bool isSolution ( int columnsCount, string x ) {
    bool allXs [ ] = new bool [ columnsCount ] ;
    Arrays.fill ( allXs, true ) ;
    for ( int i = 0 ; i < 12 ; i ++ ) {
        if ( x.charAt ( i )!= 'X' )
            allXs [ i % columnsCount ] = false ;
    }
    for ( int i = 0 ; i < columnsCount ; i ++ )
        if ( allXs [ i ] )
            return true ;
    return false ;
}

// Main method where the program starts
int main ( ) {
    int t ;
    cin >> t ;
    for ( int i = 0 ; i < t ; i ++ ) {
        int possibleSolutions = 0 ;
        string s ;
        cin >> s ;
        if ( isSolution ( 12, s ) ) {
            cout << " 1x12" ;
            possibleSolutions ++ ;
        }
        if ( isSolution ( 6, s ) ) {
            cout << " 2x6" ;
            possibleSolutions ++ ;
        }
        if ( isSolution ( 4, s ) ) {
            cout << " 3x4" ;
            possibleSolutions ++ ;
        }
        if ( isSolution ( 3, s ) ) {
            cout << " 4x3" ;
            possibleSolutions ++ ;
        }
        if ( isSolution ( 2, s ) ) {
            cout << " 6x2" ;
            possibleSolutions ++ ;
        }
        if ( isSolution ( 1, s ) ) {
            cout << " 12x1" ;
            possibleSolutions ++ ;
        }
        cout << possibleSolutions ++ << endl ;
    }
    return 0 ;
}

