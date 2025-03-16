
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <assert.h>

#define MAX_STR_LEN 100000

int main ( int argc, char * argv [ ] ) {
    char s1 [ MAX_STR_LEN ], s2 [ MAX_STR_LEN ] ;
    scanf ( "%s", s1 ) ;
    scanf ( "%s", s2 ) ;

    if ( isValid ( s1, s2 ) == false ) {
        printf ( "-1\n" ) ;
        return 0 ;
    }

    int ans = 0 ;
    char s [ MAX_STR_LEN ] ;
    strcpy ( s, s2 ) ;
    int n = strlen ( s ) ;
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( s [ i ] =='' ) {
            s [ i ] = '\0' ;
        }
    }
    char * p = strtok ( s, " " ) ;
    while ( p!= NULL ) {
        int x1 = 0, x2 = 0 ;
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( s1 [ i ] == p [ 0 ] ) {
                x1 ++ ;
            }
            if ( s2 [ i ] == p [ 0 ] ) {
                x2 ++ ;
            }
        }
        x1 = ( x1 < x2 )? x1 : x2 ;
        ans += x1 ;
        p = strtok ( NULL, " " ) ;
    }
    printf ( "%d\n", ans ) ;
    return 0 ;
}

bool isValid ( char s1 [ ], char s2 [ ] ) {
    int n1 = strlen ( s1 ), n2 = strlen ( s2 ) ;
    char s [ MAX_STR_LEN ] ;
    strcpy ( s, s2 ) ;
    int n = strlen ( s ) ;
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( s [ i ] =='' ) {
            s [ i ] = '\0' ;
        }
    }
    char * p = strtok ( s, " " ) ;
    while ( p!= NULL ) {
        bool found = false ;
        for ( int i = 0 ; i < n1 ; i ++ ) {
            if ( s1 [ i ] == p [ 0 ] ) {
                found = true ;
                break ;
            }
        }
        if ( found == false ) {
            return false ;
        }
        p = strtok ( NULL, " " ) ;
    }
    return true ;
}

