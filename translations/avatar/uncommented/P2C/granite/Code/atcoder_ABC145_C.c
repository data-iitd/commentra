
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void solve ( int N, int * x, int * y ) {
    int * indices = ( int * ) malloc ( N * sizeof ( int ) ) ;
    for ( int i = 0 ; i < N ; i ++ ) {
        indices [ i ] = i ;
    }
    int * permutation = ( int * ) malloc ( N * sizeof ( int ) ) ;
    double * distances = ( double * ) malloc ( N! * sizeof ( double ) ) ;
    int k = 0 ;
    for ( int i = 0 ; i < N ; i ++ ) {
        for ( int j = i + 1 ; j < N ; j ++ ) {
            permutation [ k ++ ] = i ;
            permutation [ k ++ ] = j ;
        }
    }
    for ( int i = 0 ; i < N! ; i ++ ) {
        double total_distance = 0 ;
        for ( int j = 0 ; j < N - 1 ; j ++ ) {
            int f = permutation [ i * ( N - 1 ) + j ] ;
            int t = permutation [ i * ( N - 1 ) + j + 1 ] ;
            double distance = sqrt ( pow ( x [ t ] - x [ f ], 2 ) + pow ( y [ t ] - y [ f ], 2 ) ) ;
            total_distance += distance ;
        }
        distances [ i ] = total_distance ;
    }
    double result = 0 ;
    for ( int i = 0 ; i < N! ; i ++ ) {
        result += distances [ i ] ;
    }
    result /= N! ;
    printf ( "%lf\n", result ) ;
    free ( indices ) ;
    free ( permutation ) ;
    free ( distances ) ;
    return ;
}

int main ( ) {
    int N ;
    scanf ( "%d", & N ) ;
    int * x = ( int * ) malloc ( N * sizeof ( int ) ) ;
    int * y = ( int * ) malloc ( N * sizeof ( int ) ) ;
    for ( int i = 0 ; i < N ; i ++ ) {
        scanf ( "%d", & x [ i ] ) ;
        scanf ( "%d", & y [ i ] ) ;
    }
    solve ( N, x, y ) ;
    free ( x ) ;
    free ( y ) ;
    return 0 ;
}

