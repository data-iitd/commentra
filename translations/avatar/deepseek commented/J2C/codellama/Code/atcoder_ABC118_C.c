
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000000

int main ( ) {
    int n ;
    scanf ( "%d" , &n ) ;
    int a [ MAX_SIZE ] ;
    int i = 0 ;
    int j = 0 ;
    int k = 0 ;
    int min = 0 ;
    bool flag = false ;
    
    if ( n == 1 ) {
        scanf ( "%d" , &a [ 0 ] ) ;
        printf ( "%d\n" , a [ 0 ] ) ;
        return 0 ;
    }
    
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &a [ i ] ) ;
    }
    
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a [ i ] == 0 ) {
            for ( j = i ; j < n - 1 ; j ++ ) {
                a [ j ] = a [ j + 1 ] ;
            }
            n -- ;
            i -- ;
        }
    }
    
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a [ i ] != 0 ) {
            if ( min != 0 ) {
                a [ i ] = a [ i ] % min ;
                if ( a [ i ] == 1 ) {
                    printf ( "1\n" ) ;
                    return 0 ;
                }
            } else {
                min = a [ i ] ;
            }
        }
    }
    
    for ( i = 0 ; i < n ; i ++ ) {
        for ( j = i + 1 ; j < n ; j ++ ) {
            if ( a [ i ] > a [ j ] ) {
                k = a [ i ] ;
                a [ i ] = a [ j ] ;
                a [ j ] = k ;
            }
        }
    }
    
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a [ i ] != 0 ) {
            flag = true ;
            break ;
        }
    }
    
    if ( flag == false ) {
        printf ( "0\n" ) ;
        return 0 ;
    }
    
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a [ i ] != 0 ) {
            for ( j = i + 1 ; j < n ; j ++ ) {
                if ( a [ i ] == a [ j ] ) {
                    a [ j ] = 0 ;
                }
            }
        }
    }
    
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a [ i ] != 0 ) {
            for ( j = i + 1 ; j < n ; j ++ ) {
                if ( a [ i ] > a [ j ] ) {
                    k = a [ i ] ;
                    a [ i ] = a [ j ] ;
                    a [ j ] = k ;
                }
            }
        }
    }
    
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a [ i ] != 0 ) {
            printf ( "%d " , a [ i ] ) ;
        }
    }
    
    printf ( "\n" ) ;
    
    return 0 ;
}

