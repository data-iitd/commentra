

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <stdint.h>

int main ( int argc, char ** argv ) {
    char sa [ 1000001 ] ;
    char sb [ 1000001 ] ;
    scanf ( "%s %s", sa, sb ) ;
    int a = atoi ( sa ) ;
    int b = ( int ) ( ( double ) atoi ( sb ) * 100 + 0.1 ) ;
    printf ( "%d\n", a * b / 100 ) ;
    return 0 ;
}

