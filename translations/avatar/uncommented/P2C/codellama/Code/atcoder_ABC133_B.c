#include <stdio.h>
#include <math.h>
int main ( ) {
    int n , d , i , j , count = 0;
    scanf ( "%d %d" , &n , &d );
    int points [ n ] [ d ];
    for ( i = 0 ; i < n ; i++ ) {
        for ( j = 0 ; j < d ; j++ ) {
            scanf ( "%d" , &points [ i ] [ j ] );
        }
    }
    double dist ( int x [ ] , int y [ ] ) {
        double tmp = 0.0;
        for ( i = 0 ; i < d ; i++ ) {
            tmp += ( x [ i ] - y [ i ] ) * ( x [ i ] - y [ i ] );
        }
        return sqrt ( tmp );
    }
    for ( i = 0 ; i < n ; i++ ) {
        for ( j = i + 1 ; j < n ; j++ ) {
            if ( dist ( points [ i ] , points [ j ] ) == ( int ) dist ( points [ i ] , points [ j ] ) ) {
                count++;
            }
        }
    }
    printf ( "%d\n" , count );
    return 0;
}
