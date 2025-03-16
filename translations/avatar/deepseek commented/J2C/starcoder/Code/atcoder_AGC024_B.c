#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>
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
    int nglist_size = 0;
    for (int i = 0; i < N - 1; ++i) {
        if (map[i] > map[i + 1]) {
            nglist[nglist_size++] = i;
        }
    }

    if (nglist_size == 0) {
        printf("0\n");
        return 0;
    }

    int ans = INT_MAX;
    ans = min(N - nglist[0] - 1, nglist[nglist_size - 1] + 1);
    for (int i = 0; i < nglist_size - 1; ++i) {
        ans = min(nglist[i] + 1 + N - nglist[i + 1] - 1, ans);
    }

    printf("%d\n", ans);
    return 0;
}

