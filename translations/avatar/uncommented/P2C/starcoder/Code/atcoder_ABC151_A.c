#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <stdarg.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <stdarg.h>
#include <inttypes.h>
#include <stdint.h>

int main ( ) {
    char c [ 100 ];
    scanf ( "%s", c );
    char a [ 26 ] = "abcdefghijklmnopqrstuvwxyz";
    int i = 0;
    while ( a [ i ]!= c [ 0 ] ) {
        i = i + 1;
    }
    printf ( "%c", a [ i + 1 ] );
    return 0;
}

