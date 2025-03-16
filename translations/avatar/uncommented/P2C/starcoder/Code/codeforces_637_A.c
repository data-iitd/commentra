#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <complex.h>
#include <stdbool.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <complex.h>
#include <stdbool.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>

int main ( ) {
    int n;
    scanf ( "%d", &n );
    char s [ 1000000 ];
    scanf ( "%s", s );
    int w [ 26 ] = { 0 };
    for ( int i = 0; i < n; i++ ) {
        w [ s [ i ] - 'a' ]++;
    }
    int c = -1, a = 0;
    for ( int i = 0; i < 26; i++ ) {
        if ( w [ i ] == max ( w, 26 ) ) {
            if ( s.index ( i ) > c ) {
                a = i;
                c = s.index ( i );
            }
        }
    }
    printf ( "%c\n", a + 'a' );
    return 0;
}

