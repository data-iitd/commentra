#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ( ) {
    int x , y , a , b , j = 2 , i , x1 = 0 , y1 = 0 , c = 0 ;
    int ans = 1 ;

    scanf ( "%d %d %d %d" , &x , &y , &a , &b ) ;

    c = x > y ? x : y ;

    if ( c > b ) {
        printf ( "0\n" ) ;
        ans = 0 ;
    }

    while ( c % ( x < y ? x : y ) != 0 && ans ) {
        if ( x > y ) {
            c = x * j ;
            j ++ ;
        } else {
            c = y * j ;
            j ++ ;
        }

        if ( c > b ) {
            printf ( "0\n" ) ;
            ans = 0 ;
            break ;
        }
    }

    if ( ans ) {
        int count = 0 ;
        i = a ;

        for ( i = a ; i <= b ; i ++ ) {
            if ( i % c == 0 ) break ;
        }

        if ( i != b + 1 ) {
            printf ( "%d\n" , ( b - i ) / c + 1 ) ;
        } else {
            printf ( "0\n" ) ;
        }
    }

    return 0 ;
}

