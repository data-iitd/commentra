#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>

int main ( ) {
    int n;
    scanf ( "%d", &n );
    char s[n + 1];
    scanf ( "%s", s );
    int count = 0;
    for ( int i = 0 ; i < n ; i++ ) {
        if ( s[i] == '0' ) {
            count++;
        }
    }
    if ( count == 0 ) {
        printf ( "%d", n - 1 );
    } else if ( count == 1 ) {
        printf ( "%d", n );
    } else {
        int maximum = 0;
        for ( int i = 0 ; i < n - 1 ; i++ ) {
            for ( int j = i + 1 ; j < n ; j++ ) {
                if ( s[i] == '0' && s[j] == '0' ) {
                    maximum = max ( maximum, 2 + 2 * ( abs ( i - j ) - 1 ) - ( abs ( j - i ) - 1 ) );
                }
            }
        }
        printf ( "%d", n - 1 + maximum );
    }
    return 0;
}

