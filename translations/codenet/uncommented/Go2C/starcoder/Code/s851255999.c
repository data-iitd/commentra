#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <stdarg.h>
#include <inttypes.h>
#include <setjmp.h>
#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <stdarg.h>
#include <inttypes.h>
#include <setjmp.h>
#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);
    work *ws = malloc(sizeof(work) * n);
    for (int i = 0; i < n; i++) {
        int a, n;
        scanf("%d %d", &a, &n);
        ws[i] = (work){a, n};
    }
    qsort(ws, n, sizeof(work), (int (*)(const void *, const void *))work_cmp);
    int64_t sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ws[i].time;
        if (sum > ws[i].limit) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}

typedef struct {
    int time, limit;
} work;

int work_cmp(const void *a, const void *b) {
    return ((work *)a)->limit - ((work *)b)->limit;
}

