#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <limits.h>
#include <ctype.h>
#include <float.h>
#include <time.h>
#include <stdarg.h>
#include <errno.h>
#include <assert.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sched.h>
#include <signal.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>
#include <poll.h>
#include <semaphore.h>
#include <err.h>
#include <aio.h>
#include <mqueue.h>
#include <ftw.h>
#include <getopt.h>
#include <glob.h>
#include <pwd.h>
#include <grp.h>
#include <langinfo.h>
#include <monetary.h>
#include <nl_types.h>
#include <regex.h>
#include <spawn.h>
#include <tar.h>
#include <wchar.h>
#include <wctype.h>
#include <langinfo.h>
#include <iconv.h>
#include <inttypes.h>
#include <stdnoreturn.h>
#include <uchar.h>
#include <stdatomic.h>
#include <stdalign.h>
#include <tgmath.h>
#include <threads.h>
#include <stdatomic.h>
#include <stdalign.h>
#include <tgmath.h>
#include <threads.h>
#include <uchar.h>
#include <stdnoreturn.h>
#include <inttypes.h>
#include <iconv.h>
#include <langinfo.h>
#include <monetary.h>
#include <nl_types.h>
#include <wctype.h>
#include <wchar.h>
#include <tar.h>
#include <spawn.h>
#include <regex.h>
#include <nl_types.h>
#include <langinfo.h>
#include <monetary.h>
#include <ftw.h>
#include <mqueue.h>
#include <aio.h>
#include <err.h>
#include <pthread.h>
#include <sched.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>
#include <poll.h>
#include <semaphore.h>
#include <errno.h>
#include <assert.h>
#include <time.h>
#include <stdarg.h>
#include <stdint.h>
#include <limits.h>
#include <ctype.h>
#include <float.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main ( int argc, char *argv [ ] ) {
    int n, b;
    long *ans;
    struct LinkedList *q;
    scanf ( "%d %d", &n, &b );
    ans = ( long * ) malloc ( sizeof ( long ) * n );
    q = ( struct LinkedList * ) malloc ( sizeof ( struct LinkedList ) );
    for ( int i = 0; i < n; i ++ ) {
        int t, d;
        scanf ( "%d %d", &t, &d );
        while ( ! q->isEmpty ( ) && q->getFirst ( ) <= t ) {
            q->pollFirst ( );
        }
        if ( q->size ( ) <= b ) {
            ans [ i ] = ( q->isEmpty ( ) ? t : q->getLast ( ) ) + d;
            q->add ( ans [ i ] );
        } else {
            ans [ i ] = - 1;
        }
    }
    for ( int i = 0; i < n; ++ i ) {
        printf ( "%ld ", ans [ i ] );
    }
    return 0;
}

