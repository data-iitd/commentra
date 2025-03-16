#include <stdio.h>

int main ( void ) {
    double VP, VD, T, F, C ;
    int answer = 0 ;
    double start = T ;

    scanf ( "%lf %lf %lf %lf %lf", &VP, &VD, &T, &F, &C ) ;

    if ( VD <= VP ) {
        printf ( "0\n" ) ;
        return 0 ;
    }

    while ( true ) {
        double x = start * VP / ( VD - VP ) ;

        if ( ( start + x ) * VP >= C ) {
            break ;
        }

        start += 2 * x + F ;
        answer ++ ;
    }

    printf ( "%d\n", answer ) ;

    return 0 ;
}

