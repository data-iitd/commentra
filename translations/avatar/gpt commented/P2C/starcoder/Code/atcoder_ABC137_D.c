#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <setjmp.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <setjmp.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>

#define MAX_JOBS 100000
#define MAX_DAYS 100000

int main(int argc, char *argv[]) {
    int n, m;
    int x[MAX_JOBS];
    int y[MAX_JOBS];
    int i, j, k, l;
    int d, s, r;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &d, &s);
        x[i] = -d;
        y[i] = -s;
    }
    while (n > 0) {
        d = x[0];
        s = y[0];
        r = m - n;
        if (r >= -d) {
            y[n] = s;
            n--;
        } else {
            y[0] = s;
            n--;
            for (i = 0; i < n; i++) {
                if (y[i] < y[i + 1]) {
                    k = y[i];
                    y[i] = y[i + 1];
                    y[i + 1] = k;
                }
            }
        }
    }
    printf("%d\n", -y[0]);
    return 0;
}

