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
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <assert.h>
#include <complex.h>
#include <stdalign.h>
#include <stdarg.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>
#include <threads.h>
#include <time.h>
#include <uchar.h>
#include <wchar.h>
#include <wctype.h>

#define MAX_N 100000

int colors[MAX_N];

typedef struct Point {
    int name;
    struct Point *friends[MAX_N];
    int nFriends;
} Point;

void dfs(Point *p, int length) {
    if (colors[p->name]!= -1) return;
    if (length % 2 == 0) {
        colors[p->name] = 0;
    } else {
        colors[p->name] = 1;
    }
    for (int i = 0; i < p->nFriends; i++) {
        dfs(p->friends[i], length + p->friends[i]->friends[p->name]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Point points[MAX_N];
    for (int i = 0; i < n; i++) {
        points[i].name = i;
        points[i].nFriends = 0;
    }
    for (int i = 0; i < m; i++) {
        int me, you, length;
        scanf("%d %d %d", &me, &you, &length);
        me--;
        you--;
        points[me].friends[points[you].name] = &points[you];
        points[you].friends[points[me].name] = &points[me];
        points[me].nFriends++;
        points[you].nFriends++;
    }
    dfs(&points[0], 0);
    for (int i = 0; i < n; i++) {
        printf("%d\n", colors[i]);
    }
    return 0;
}

