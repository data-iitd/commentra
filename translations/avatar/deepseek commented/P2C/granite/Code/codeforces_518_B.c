
#include <stdio.h>
#include <string.h>

int main ( ) {
    char s [ 100001 ], t [ 100001 ] ;
    int freqs [ 128 ] = { 0 }, freqt [ 128 ] = { 0 } ;
    int yay = 0, whoops = 0 ;
    int i, j ;

    scanf ( "%s %s", s, t ) ;  // Taking two input strings

    // Populating the frequency arrays
    for ( i = 0 ; s [ i ]!= '\0' ; i ++ ) {
        freqs [ s [ i ] ] ++ ;  // Incrementing the count if character is already in array
    }

    for ( i = 0 ; t [ i ]!= '\0' ; i ++ ) {
        freqt [ t [ i ] ] ++ ;  // Incrementing the count if character is already in array
    }

    // Counting yay by matching characters in freqs and freqt
    for ( i = 0 ; i < 128 ; i ++ ) {
        while ( freqs [ i ] > 0 && freqt [ i ] > 0 ) {
            yay ++ ;  // Incrementing yay if characters match
            freqs [ i ] -- ;  // Decrementing the count in freqs
            freqt [ i ] -- ;  // Decrementing the count in freqt
        }
    }

    // Counting whoops by transforming characters to match
    for ( i = 0 ; i < 128 ; i ++ ) {
        while ( freqs [ i ] > 0 ) {
            if ( i >= 65 && i <= 90 && freqt [ i + 32 ] > 0 ) {
                whoops ++ ;  // Incrementing whoops if transformation is possible
                freqs [ i ] -- ;  // Decrementing the count in freqs
                freqt [ i + 32 ] -- ;  // Decrementing the count in freqt
            } else if ( i >= 97 && i <= 122 && freqt [ i - 32 ] > 0 ) {
                whoops ++ ;  // Incrementing whoops if transformation is possible
                freqs [ i ] -- ;  // Decrementing the count in freqs
                freqt [ i - 32 ] -- ;  // Decrementing the count in freqt
            } else {
                break ;  // Breaking the loop if no more transformations are possible
            }
        }
    }

    printf ( "%d %d\n", yay, whoops ) ;  // Printing the final counts of yay and whoops

    return 0 ;
}
