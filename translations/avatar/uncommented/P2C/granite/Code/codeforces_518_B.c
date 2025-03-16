
#include <stdio.h>
#include <string.h>

int main ( ) {
    char s [ 100001 ], t [ 100001 ] ;
    scanf ( "%s", s ) ;
    scanf ( "%s", t ) ;
    int freqs [ 256 ] = { 0 } ;
    int freqt [ 256 ] = { 0 } ;
    int yay = 0, whoops = 0 ;
    for ( int i = 0 ; s [ i ]!= '\0' ; i ++ ) {
        freqs [ s [ i ] ] ++ ;
    }
    for ( int i = 0 ; t [ i ]!= '\0' ; i ++ ) {
        freqt [ t [ i ] ] ++ ;
    }
    for ( int i = 0 ; i < 256 ; i ++ ) {
        while ( freqs [ i ] > 0 && freqt [ i ] > 0 ) {
            yay ++ ;
            freqs [ i ] -- ;
            freqt [ i ] -- ;
        }
    }
    for ( int i = 0 ; i < 256 ; i ++ ) {
        while ( freqs [ i ] > 0 ) {
            if ( i >= 'a' && i <= 'z' && freqt [ i - 'a' + 'A' ] > 0 ) {
                whoops ++ ;
                freqs [ i ] -- ;
                freqt [ i - 'a' + 'A' ] -- ;
            }
            else if ( i >= 'A' && i <= 'Z' && freqt [ i - 'A' + 'a' ] > 0 ) {
                whoops ++ ;
                freqs [ i ] -- ;
                freqt [ i - 'A' + 'a' ] -- ;
            }
            else {
                break ;
            }
        }
    }
    printf ( "%d %d\n", yay, whoops ) ;
    return 0 ;
}
