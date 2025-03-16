#include <stdio.h>
#include <string.h>
int main ( ) {
    char t [ 4 ] [ 4 ];
    int black = 0, white = 0, correct = 0;
    for ( int i = 0 ; i < 4 ; i++ ) {
        scanf ( "%s", t [ i ] );
    }
    for ( int i = 0 ; i < 3 ; i++ ) {
        for ( int j = 0 ; j < 3 ; j++ ) {
            if ( t [ i ] [ j ] == '#' ) {
                black++;
            }
            else {
                white++;
            }
            if ( t [ i ] [ j + 1 ] == '#' ) {
                black++;
            }
            else {
                white++;
            }
            if ( t [ i + 1 ] [ j ] == '#' ) {
                black++;
            }
            else {
                white++;
            }
            if ( t [ i + 1 ] [ j + 1 ] == '#' ) {
                black++;
            }
            else {
                white++;
            }
            if ( black == 0 || black == 3 || white == 0 || white == 3 || white == 4 || black == 4 ) {
                correct = 1;
                break;
            }
            black = 0;
            white = 0;
        }
        if ( correct == 1 ) {
            break;
        }
    }
    if ( correct == 1 ) {
        printf ( "YES" );
    }
    else {
        printf ( "NO" );
    }
    return 0;
}
