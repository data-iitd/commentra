
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000000

int compare ( char * aa , int i , char * bb , int j , int m ) {
    while ( m -- > 0 ) {
        char a = toupper ( aa [ i ] ) ;
        char b = toupper ( bb [ j ] ) ;

        if ( a != b )
            return a - b ;

        i ++ ;
        j ++ ;
    }

    return 0 ;
}

int main ( ) {
    int n ;
    scanf ( "%d" , &n ) ;

    char * ss [ n ] ;

    for ( int i = 0 ; i < n ; i ++ ) {
        ss [ i ] = malloc ( MAX_LENGTH * sizeof ( char ) ) ;
        scanf ( "%s" , ss [ i ] ) ;
    }

    char * cc = malloc ( MAX_LENGTH * sizeof ( char ) ) ;
    scanf ( "%s" , cc ) ;

    int m = strlen ( cc ) ;

    char c ;
    scanf ( "%c" , &c ) ;

    char a = c == 'a' ? 'b' : 'a' ;
    char a_ = toupper ( a ) ;

    int * lucky = malloc ( m * sizeof ( int ) ) ;

    for ( int j = 0 ; j < m ; j ++ ) {
        lucky [ j ] = 0 ;
    }

    for ( int j = 0 ; j < m ; j ++ ) {
        for ( int i = 0 ; i < n ; i ++ ) {
            int l = strlen ( ss [ i ] ) ;

            if ( m - j >= l && compare ( cc , j , ss [ i ] , 0 , l ) == 0 ) {
                for ( int h = 0 ; h < l ; h ++ ) {
                    lucky [ j + h ] = 1 ;
                }
            }
        }
    }

    for ( int j = 0 ; j < m ; j ++ ) {
        if ( lucky [ j ] ) {
            if ( tolower ( cc [ j ] ) == c ) {
                cc [ j ] = isupper ( cc [ j ] ) ? a_ : a ;
            } else {
                cc [ j ] = isupper ( cc [ j ] ) ? c : c ;
            }
        }
    }

    printf ( "%s\n" , cc ) ;

    return 0 ;
}

