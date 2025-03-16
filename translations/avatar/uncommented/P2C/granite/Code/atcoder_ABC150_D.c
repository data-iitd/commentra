
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <stdarg.h>
#include <time.h>
#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <inttypes.h>
#include <setjmp.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pwd.h>
#include <grp.h>
#include <signal.h>
#include <locale.h>
#include <dlfcn.h>
#include < poll.h>
#include < iconv.h>
#include < langinfo.h>
#include < nl_types.h>

int main ( int argc, char * argv [ ] ) {
    int n, num ;
    scanf ( "%d %d", & n, & num ) ;
    int a [ 30 ] ;
    memset ( a, 0, sizeof ( a ) ) ;
    for ( int i = 0 ; i < n ; i ++ ) {
        int x ;
        scanf ( "%d", & x ) ;
        for ( int j = 0 ; j < 30 ; j ++ ) {
            if ( x % 2 == 1 ) {
                a [ j ] = 1 ;
                break ;
            }
            x /= 2 ;
        }
    }
    int cnt = 0 ;
    for ( int i = 0 ; i < 30 ; i ++ ) {
        cnt += a [ i ] ;
    }
    if ( cnt!= 1 ) {
        printf ( "0\n" ) ;
    }
    else {
        int b [ 30 ] ;
        memset ( b, 0, sizeof ( b ) ) ;
        for ( int i = 0 ; i < n ; i ++ ) {
            int x ;
            scanf ( "%d", & x ) ;
            for ( int j = 0 ; j < 30 ; j ++ ) {
                if ( x % 2 == 1 ) {
                    b [ j ] = 1 ;
                    break ;
                }
                x /= 2 ;
            }
        }
        int ans = 1 ;
        for ( int i = 0 ; i < 30 ; i ++ ) {
            ans *= pow ( 2, i ) ;
            if ( b [ i ] == 1 ) {
                ans /= 2 ;
            }
        }
        printf ( "%d\n", ( num - ans / 2 ) / ans + 1 ) ;
    }
    return 0 ;
}
