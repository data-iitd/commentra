
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

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    int m = n - 1;
    int *colors = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        colors[i] = -1;
    }
    Point *points = malloc(n * sizeof(Point));
    for (int i = 0; i < n; i++) {
        points[i] = Point_new(i);
    }
    while (m-- > 0) {
        int me;
        int you;
        int length;
        scanf("%d", &me);
        scanf("%d", &you);
        scanf("%d", &length);
        Point_becomeFriend(points[me - 1], points[you - 1], length);
        Point_becomeFriend(points[you - 1], points[me - 1], length);
    }
    dfs(points[0], 0);
    for (int i = 0; i < n; i++) {
        printf("%d\n", colors[i]);
    }
    return 0;
}

typedef struct Point Point;

struct Point {
    int name;
    Map friends;
};

Point Point_new(int name) {
    Point this = malloc(sizeof(struct Point));
    this->name = name;
    this->friends = Map_new();
    return this;
}

void Point_becomeFriend(Point this, Point p, int length) {
    Map_put(this->friends, p, length);
    Map_put(p->friends, this, length);
}

void dfs(Point p, int length) {
    bool alreadyKnown = colors[p->name]!= -1;
    if (alreadyKnown) return;
    if (length % 2 == 0) {
        colors[p->name] = 0;
    } else {
        colors[p->name] = 1;
    }
    Map_Entry *entry;
    for (entry = Map_entrySet(p->friends); entry!= NULL; entry = entry->next) {
        Point friend = entry->key;
        int length2 = entry->value;
        dfs(friend, length + length2);
    }
}

