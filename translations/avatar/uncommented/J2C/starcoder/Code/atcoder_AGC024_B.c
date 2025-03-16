#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
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
#include <math.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    int N;
    scanf("%d", &N);
    int P[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &P[i]);
    }
    int map[N];
    for (int i = 0; i < N; ++i) {
        map[P[i]] = i;
    }
    int nglist[N];
    for (int i = 0; i < N - 1; ++i) {
        if (map[i] > map[i + 1]) {
            nglist[i] = i;
        }
    }
    if (nglist[0] == 0) {
        printf("0\n");
        return 0;
    }
    int ans = N - nglist[0] - 1;
    for (int i = 0; i < nglist[0]; ++i) {
        ans = min(ans, nglist[i] + 1 + N - nglist[i + 1] - 1);
    }
    printf("%d\n", ans);
    return 0;
}

