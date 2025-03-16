
#include <iostream>
#include <string>
using namespace std;
int main ( ) {
    int H, W, N ;
    cin >> H >> W >> N ;
    int s_r, s_c ;
    cin >> s_r >> s_c ;
    string S, T ;
    cin >> S >> T ;
    bool Judge = false ;
    int S_L, S_R, S_U, S_D ;
    int T_L, T_R, T_U, T_D ;
    S_L = S_R = S_U = S_D = 0 ;
    T_L = T_R = T_U = T_D = 0 ;
    for ( int x = 0 ; x < N ; x ++ ) {
        if ( S [ x ] == 'L' ) {
            S_L ++ ;
            if ( S_L - T_R - s_c == 0 ) {
                Judge = true ;
            }
        }
        else if ( S [ x ] == 'R' ) {
            S_R ++ ;
            if ( s_c + ( S_R - T_L ) == W + 1 ) {
                Judge = true ;
            }
        }
        else if ( S [ x ] == 'U' ) {
            S_U ++ ;
            if ( S_U - T_D - s_r == 0 ) {
                Judge = true ;
            }
        }
        else if ( S [ x ] == 'D' ) {
            S_D ++ ;
            if ( s_r + ( S_D - T_U ) == H + 1 ) {
                Judge = true ;
            }
        }
        if ( T [ x ] == 'L' ) {
            if ( S_R - T_L + s_c!= 1 ) {
                T_L ++ ;
            }
        }
        if ( T [ x ] == 'R' ) {
            if ( s_c + ( T_R - S_L )!= W ) {
                T_R ++ ;
            }
        }
        if ( T [ x ] == 'U' ) {
            if ( S_D - T_U + s_r!= 1 ) {
                T_U ++ ;
            }
        }
        if ( T [ x ] == 'D' ) {
            if ( s_r + ( T_D - S_U )!= H ) {
                T_D ++ ;
            }
        }
    }
    if ( Judge ) {
        cout << "NO" << endl ;
    }
    else {
        cout << "YES" << endl ;
    }
    return 0 ;
}
