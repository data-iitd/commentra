
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int * sequence = input ( );
    int n = nPairsWithCommonFX ( sequence );
    printf ( "%d\n", n );
    return 0;
}

int * input ( ) {
    int n;
    scanf ( "%d", & n );
    int * sequence = ( int * ) malloc ( n * sizeof ( int ) ) ;
    for ( int i = 0; i < n; i ++ ) {
        scanf ( "%d", sequence + i ) ;
    }
    return sequence;
}

int nPairsWithCommonFX ( int * sequence, int n ) {
    int * storage = ( int * ) malloc ( n * sizeof ( int ) ) ;
    int * FXs = ( int * ) malloc ( n * sizeof ( int ) ) ;
    for ( int i = 0; i < n; i ++ ) {
        int y = f ( sequence [ i ] ) ;
        if ( y >= n ) {
            storage [ y ] = 1 ;
            FXs [ y ] = sequence [ i ] ;
        } else {
            storage [ y ] ++ ;
        }
    }
    int result = 0 ;
    for ( int i = 0; i < n; i ++ ) {
        result += storage [ i ] * storage [ i ] ;
    }
    for ( int i = 0; i < n; i ++ ) {
        result -= storage [ i ] ;
    }
    return result / 2 ;
}

int f ( int n ) {
    int y = 1 ;
    while ( n!= 1 ) {
        if ( n % 2 ) {
            y ++ ;
        }
        n /= 2 ;
    }
    return y ;
}

// END-OF-CODE