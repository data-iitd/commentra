
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <stdarg.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <stdarg.h>
#include <inttypes.h>
#include <stdint.h>

int main() {
    int n;
    scanf("%d", &n);
    int orig[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &orig[i]);
    }
    int p[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    int q[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }
    int pn = -1;
    for (int i = 0; i < n; i++) {
        if (orig[i] == p[0] && orig[i + 1] == p[1] && orig[i + 2] == p[2] && orig[i + 3] == p[3] && orig[i + 4] == p[4]) {
            pn = i;
            break;
        }
    }
    int qn = -1;
    for (int i = 0; i < n; i++) {
        if (orig[i] == q[0] && orig[i + 1] == q[1] && orig[i + 2] == q[2] && orig[i + 3] == q[3] && orig[i + 4] == q[4]) {
            qn = i;
            break;
        }
    }
    printf("%d", abs(pn - qn));
    return 0;
}

