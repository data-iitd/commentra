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
#include <fenv.h>
#include <inttypes.h>
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

int colors[100000];

typedef struct Point {
    int name;
    struct Point *friends[100000];
    int friends_count;
} Point;

void dfs(Point *p, int length) {
    bool alreadyKnown = colors[p->name]!= -1;
    if (alreadyKnown) return;
    if (length % 2 == 0) {
        colors[p->name] = 0;
    } else {
        colors[p->name] = 1;
    }
    for (int i = 0; i < p->friends_count; i++) {
        Point *friend = p->friends[i];
        int length2 = p->friends[i]->friends[i];
        dfs(friend, length + length2);
    }
}

int main(int argc, char **argv) {
    Point points[100000];
    for (int i = 0; i < 100000; i++) {
        points[i].name = i;
        points[i].friends_count = 0;
    }
    int n, m;
    scanf("%d", &n);
    m = n - 1;
    while (m-- > 0) {
        int me, you, length;
        scanf("%d", &me);
        scanf("%d", &you);
        scanf("%d", &length);
        points[me].friends[points[me].friends_count++] = &points[you];
        points[you].friends[points[you].friends_count++] = &points[me];
    }
    dfs(&points[0], 0);
    for (int c : colors) {
        printf("%d\n", c);
    }
    return 0;
}

