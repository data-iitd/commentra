#include <stdio.h>
#include <string.h>

int main ( ) {
    char s [ 100000 ], t [ 100000 ] ;
    int freqs [ 26 ], freqt [ 26 ], yay, whoops, i, j ;

    scanf ( "%s", s ) ;
    scanf ( "%s", t ) ;

    for ( i = 0 ; i < 26 ; i ++ ) {
        freqs [ i ] = 0 ;
        freqt [ i ] = 0 ;
    }

    for ( i = 0 ; i < strlen ( s ) ; i ++ ) {
        freqs [ s [ i ] - 'a' ] ++ ;
    }

    for ( i = 0 ; i < strlen ( t ) ; i ++ ) {
        freqt [ t [ i ] - 'a' ] ++ ;
    }

    yay = 0 ;
    whoops = 0 ;

    for ( i = 0 ; i < 26 ; i ++ ) {
        while ( freqs [ i ] > 0 && i < 26 && freqt [ i ] > 0 ) {
            yay ++ ;
            freqs [ i ] -- ;
            freqt [ i ] -- ;
        }
    }

    for ( i = 0 ; i < 26 ; i ++ ) {
        while ( freqs [ i ] > 0 ) {
            if ( i >= 97 && i <= 122 && freqt [ i - 32 ] > 0 ) {
                whoops ++ ;
                freqs [ i ] -- ;
                freqt [ i - 32 ] -- ;
            }
            else if ( i >= 65 && i <= 90 && freqt [ i + 32 ] > 0 ) {
                whoops ++ ;
                freqs [ i ] -- ;
                freqt [ i + 32 ] -- ;
            }
            else {
                break ;
            }
        }
    }

    printf ( "%d %d", yay, whoops ) ;

    return 0 ;
}

