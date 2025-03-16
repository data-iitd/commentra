

#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int N = 368;
    int m [ N ] = { 0 };
    int f [ N ] = { 0 };
    int a, b, c = 0;
    char x;
    
    for ( int i = 0; i < int ( scanf ( "%*d" ) ); i ++ ) {
        scanf ( " %c %d %d", & x, & a, & b );
        a --;
        b --;
        
        if ( x == 'M' ) {
            m [ a ] += 2;
            m [ b ] -= 2;
        } else {
            f [ a ] += 2;
            f [ b ] -= 2;
        }
    }
    
    for ( int i = 0; i < N; i ++ ) {
        if ( i > 0 ) {
            m [ i ] += m [ i - 1 ];
            f [ i ] += f [ i - 1 ];
        }
        
        if ( min ( m [ i ], f [ i ] ) > c ) {
            c = min ( m [ i ], f [ i ] );
        }
    }
    
    printf ( "%d\n", c );
    
    return 0;
}

