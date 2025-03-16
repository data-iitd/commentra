#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <errno.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <signal.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <errno.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <signal.h>
#include <stdbool.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    int x[n], y[n], h[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
        scanf("%d", &y[i]);
        scanf("%d", &h[i]);
    }
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            int ch = check(n, x, y, h, i, j);
            if (ch > 0) {
                printf("%d %d %d\n", i, j, ch);
            }
        }
    }
    return 0;
}

int check(int n, int x[], int y[], int h[], int cx, int cy) {
    int ch = -1;
    for (int i = 0; i < n; i++) {
        if (h[i] > 0) {
            ch = abs(x[i] - cx) + abs(y[i] - cy) + h[i];
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (h[i]!= max(ch - abs(x[i] - cx) - abs(y[i] - cy), 0)) {
            return -1;
        }
    }
    return ch;
}

