#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ( ) {
    long Q , H , S , D , N ;

    scanf ( "%ld %ld %ld %ld %ld" , &Q , &H , &S , &D , &N ) ;

    long onePrice = min ( min ( Q * 4 , H * 2 ) , S ) ;

    if ( ( double ) onePrice <= ( double ) D / 2 ) {
        printf ( "%ld\n" , N * onePrice ) ;
    } else {
        printf ( "%ld\n" , ( N / 2 ) * D + ( N % 2 ) * onePrice ) ;
    }

    return 0 ;
}

