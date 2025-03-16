
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main ( ) {
    char s [ 1000 ] , t [ 1000 ] ;
    int freqs [ 26 ] , freqt [ 26 ] , yay , whoops , i , j , k , l , m , n , o , p , q , r , s , t , u , v , w , x , y , z ;
    scanf ( "%s %s" , s , t ) ;
    for ( i = 0 ; i < 26 ; i ++ ) {
        freqs [ i ] = 0 ;
        freqt [ i ] = 0 ;
    }
    for ( i = 0 ; i < strlen ( s ) ; i ++ ) {
        if ( islower ( s [ i ] ) ) {
            freqs [ s [ i ] - 'a' ] ++ ;
        }
        else {
            freqs [ s [ i ] - 'A' ] ++ ;
        }
    }
    for ( i = 0 ; i < strlen ( t ) ; i ++ ) {
        if ( islower ( t [ i ] ) ) {
            freqt [ t [ i ] - 'a' ] ++ ;
        }
        else {
            freqt [ t [ i ] - 'A' ] ++ ;
        }
    }
    yay = 0 ;
    whoops = 0 ;
    for ( i = 0 ; i < 26 ; i ++ ) {
        while ( freqs [ i ] > 0 && freqt [ i ] > 0 ) {
            yay ++ ;
            freqs [ i ] -- ;
            freqt [ i ] -- ;
        }
    }
    for ( i = 0 ; i < 26 ; i ++ ) {
        while ( freqs [ i ] > 0 ) {
            if ( islower ( i + 'a' ) && freqt [ i + 'A' - 'a' ] > 0 ) {
                whoops ++ ;
                freqs [ i ] -- ;
                freqt [ i + 'A' - 'a' ] -- ;
            }
            else if ( isupper ( i + 'A' ) && freqt [ i + 'a' - 'A' ] > 0 ) {
                whoops ++ ;
                freqs [ i ] -- ;
                freqt [ i + 'a' - 'A' ] -- ;
            }
            else {
                break ;
            }
        }
    }
    printf ( "%d %d" , yay , whoops ) ;
    return 0 ;
}



