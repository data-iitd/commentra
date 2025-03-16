
#include <stdio.h>
#include <stdlib.h>

#define D 10
#define INF 100000

int main ( void ) {

    int p [ D ] ;
    int c [ D ] ;
    int bit ;
    int score ;
    int solve_num ;
    int min ;
    int i ;
    int j ;
    int G ;
    int D ;

    scanf ( "%d %d", &D, &G ) ;

    for ( i = 0 ; i < D ; i ++ ) {
        scanf ( "%d %d", &p [ i ], &c [ i ] ) ;
    }

    min = INF ;

    for ( bit = 0 ; bit < ( 1 << D ) ; bit ++ ) {

        score = 0 ;
        solve_num = 0 ;

        for ( i = 0 ; i < D ; i ++ ) {

            if ( ( bit & ( 1 << i ) )!= 0 ) {

                score += 100 * ( i + 1 ) * p [ i ] + c [ i ] ;
                solve_num += p [ i ] ;
            }
        }

        if ( score < G ) {

            for ( i = D - 1 ; i >= 0 ; i -- ) {

                if ( ( bit & ( 1 << i ) ) == 0 ) {

                    for ( j = 0 ; j < p [ i ] - 1 ; j ++ ) {

                        score += 100 * ( i + 1 ) ;
                        solve_num ++ ;

                        if ( score >= G ) {
                            break ;
                        }
                    }
                }

                if ( score >= G ) {
                    break ;
                }
            }
        }

        if ( score >= G ) {
            min = ( min < solve_num )? min : solve_num ;
        }
    }

    printf ( "%d\n", min ) ;

    return 0 ;
}
