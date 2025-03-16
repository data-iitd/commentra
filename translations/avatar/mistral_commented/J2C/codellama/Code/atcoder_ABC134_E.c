#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000000

int main ( ) {
    int n ;
    scanf ( "%d" , &n ) ;

    int arr[MAX_SIZE] = {0} ;
    int i = 0 ;

    while ( n -- > 0 ) {
        int num ;
        scanf ( "%d" , &num ) ;

        if ( arr[num] == 0 ) {
            arr[num] = 1 ;
        } else {
            arr[num] ++ ;
        }
    }

    int ans = 0 ;

    for ( i = 0 ; i < MAX_SIZE ; i ++ ) {
        if ( arr[i] != 0 ) {
            ans += arr[i] ;
        }
    }

    printf ( "%d\n" , ans ) ;

    return 0 ;
}

