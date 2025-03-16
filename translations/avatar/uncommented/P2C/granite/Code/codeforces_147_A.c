
#include <stdio.h>
#include <string.h>

int main ( ) {
    char s [ 1000 ];
    scanf ( "%s", s );
    char res [ 1000 ];
    int len = strlen ( s );
    int index = 0;
    char punctuation [ ] = { ',', '.', '!', '?' };
    for ( int i = 0 ; i < len ; i ++ ) {
        if ( i >= 1 ) {
            if ( s [ i ] =='' ) {
                if ( res [ index - 1 ]!='' ) {
                    res [ index ++ ] = s [ i ];
                } else {
                    continue;
                }
            } else {
                if ( strchr ( punctuation, s [ i ] )!= NULL ) {
                    if ( res [ index - 1 ] =='' ) {
                        res [ -- index ];
                    }
                    res [ index ++ ] = s [ i ];
                    res [ index ++ ] ='';
                } else {
                    res [ index ++ ] = s [ i ];
                }
            }
        } else {
            if ( s [ i ] =='' ) {
                continue;
            }
            if ( strchr ( punctuation, s [ i ] )!= NULL ) {
                continue;
            } else {
                res [ index ++ ] = s [ i ];
            }
        }
    }
    printf ( "%s\n", res );
    return 0;
}
