
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int twos_in_factorial ( int n ) {
    return n - __builtin_popcount ( n ) ;
}

int parity_of_nCr ( int n, int i ) {
    int f = twos_in_factorial ;
    return f ( n ) - f ( n - i ) - f ( i ) > 0 ;
}

int main ( ) {
    int n ;
    scanf ( "%d", & n ) ;
    int * nums = malloc ( n * sizeof ( int ) ) ;
    for ( int i = 0 ; i < n ; i ++ ) {
        scanf ( "%d", nums + i ) ;
        nums [ i ] -- ;
    }
    int no_one = 0 ;
    if (! strchr ( nums, 1 ) ) {
        for ( int i = 0 ; i < n ; i ++ ) {
            nums [ i ] /= 2 ;
        }
        no_one = 1 ;
    }
    int is_odd = 0 ;
    for ( int i = 0 ; i < n ; i ++ ) {
        if (! parity_of_nCr ( n - 1, i ) && nums [ i ] & 1 ) {
            is_odd ^= 1 ;
        }
    }
    if (! is_odd ) {
        printf ( "0\n" ) ;
    } else {
        printf ( "%d\n", 1 << no_one ) ;
    }
    free ( nums ) ;
    return 0 ;
}

END-OF-CODE