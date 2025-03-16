
#include <stdio.h>

int main ( ) {
    int H, W, N ;
    scanf ( "%d %d %d", & H, & W, & N ) ;
    int s_r, s_c ;
    scanf ( "%d %d", & s_r, & s_c ) ;
    char S [ 100001 ] ;
    scanf ( "%s", S ) ;
    char T [ 100001 ] ;
    scanf ( "%s", T ) ;
    int S_L, S_R, S_U, S_D ;
    int T_L, T_R, T_U, T_D ;
    S_L = S_R = S_U = S_D = 0 ;
    T_L = T_R = T_U = T_D = 0 ;
    int i ;
    for ( i = 0 ; i < N ; i ++ ) {
        if ( S [ i ] == 'L' ) {
            S_L ++ ;
            if ( S_L - T_R - s_c == 0 ) {
                printf ( "NO\n" ) ;
                return 0 ;
            }
        }
        else if ( S [ i ] == 'R' ) {
            S_R ++ ;
            if ( s_c + ( S_R - T_L ) == W + 1 ) {
                printf ( "NO\n" ) ;
                return 0 ;
            }
        }
        else if ( S [ i ] == 'U' ) {
            S_U ++ ;
            if ( S_U - T_D - s_r == 0 ) {
                printf ( "NO\n" ) ;
                return 0 ;
            }
        }
        else if ( S [ i ] == 'D' ) {
            S_D ++ ;
            if ( s_r + ( S_D - T_U ) == H + 1 ) {
                printf ( "NO\n" ) ;
                return 0 ;
            }
        }
        if ( T [ i ] == 'L' ) {
            if ( S_R - T_L + s_c!= 1 ) {
                T_L ++ ;
            }
        }
        if ( T [ i ] == 'R' ) {
            if ( s_c + ( T_R - S_L )!= W ) {
                T_R ++ ;
            }
        }
        if ( T [ i ] == 'U' ) {
            if ( S_D - T_U + s_r!= 1 ) {
                T_U ++ ;
            }
        }
        if ( T [ i ] == 'D' ) {
            if ( s_r + ( T_D - S_U )!= H ) {
                T_D ++ ;
            }
        }
    }
    printf ( "YES\n" ) ;
    return 0 ;
}
