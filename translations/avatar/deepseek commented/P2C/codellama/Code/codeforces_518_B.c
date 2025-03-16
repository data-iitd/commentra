#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main ( ) {
    char s [ 100 ] , t [ 100 ] ;  // Declaring two character arrays
    int i , j , yay , whoops ;  // Declaring counters for yay and whoops
    int freqs [ 26 ] , freqt [ 26 ] ;  // Declaring two frequency arrays

    // Taking two input strings
    printf ( "Enter the first string: " ) ;
    scanf ( "%s" , s ) ;
    printf ( "Enter the second string: " ) ;
    scanf ( "%s" , t ) ;

    // Initializing the frequency arrays
    for ( i = 0 ; i < 26 ; i++ ) {
        freqs [ i ] = 0 ;
        freqt [ i ] = 0 ;
    }

    // Populating the frequency arrays
    for ( i = 0 ; s [ i ] != '\0' ; i++ ) {
        if ( s [ i ] >= 'a' && s [ i ] <= 'z' ) {
            freqs [ s [ i ] - 'a' ] += 1 ;
        } else if ( s [ i ] >= 'A' && s [ i ] <= 'Z' ) {
            freqs [ s [ i ] - 'A' ] += 1 ;
        }
    }

    for ( i = 0 ; t [ i ] != '\0' ; i++ ) {
        if ( t [ i ] >= 'a' && t [ i ] <= 'z' ) {
            freqt [ t [ i ] - 'a' ] += 1 ;
        } else if ( t [ i ] >= 'A' && t [ i ] <= 'Z' ) {
            freqt [ t [ i ] - 'A' ] += 1 ;
        }
    }

    // Counting yay by matching characters in freqs and freqt
    for ( i = 0 ; i < 26 ; i++ ) {
        while ( freqs [ i ] > 0 && freqt [ i ] > 0 ) {
            yay += 1 ;
            freqs [ i ] -= 1 ;
            freqt [ i ] -= 1 ;
        }
    }

    // Counting whoops by transforming characters to match
    for ( i = 0 ; i < 26 ; i++ ) {
        while ( freqs [ i ] > 0 ) {
            if ( i >= 0 && i <= 25 && freqt [ i ] > 0 ) {
                whoops += 1 ;
                freqs [ i ] -= 1 ;
                freqt [ i ] -= 1 ;
            } else if ( i >= 0 && i <= 25 && freqt [ i + 32 ] > 0 ) {
                whoops += 1 ;
                freqs [ i ] -= 1 ;
                freqt [ i + 32 ] -= 1 ;
            } else {
                break ;
            }
        }
    }

    printf ( "Yay: %d\nWhoops: %d\n" , yay , whoops ) ;

    return 0 ;
}

