#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SIG_THRESHOLD 1e-8
#define MAX_POINTS 110
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
const double PI = acos(-1.0);

int sig(double d) {
    return fabs(d) < SIG_THRESHOLD ? 0 : d < 0 ? -1 : 1;
}

typedef struct {
    double x, y;
<<<<<<< HEAD
    double k;
=======
>>>>>>> 98c87cb78a (data updated)
} Point;

Point P[MAX_POINTS];
int ch[MAX_POINTS];
double ang[MAX_POINTS], ans[MAX_POINTS];

double dot(Point *o, Point *a, Point *b) {
    return (a->x - o->x) * (b->x - o->x) + (a->y - o->y) * (b->y - o->y);
}

double dot_simple(Point *a, Point *b) {
    return a->x * b->x + a->y * b->y;
}

double cross(Point *o, Point *a, Point *b) {
    return (a->x - o->x) * (b->y - o->y) - (b->x - o->x) * (a->y - o->y);
}

int btw(Point *x, Point *a, Point *b) {
    return sig(dot(x, a, b));
}

double dis(Point *a, Point *b) {
    return sqrt((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y));
}

double cos_angle(Point *o, Point *a, Point *b) {
    return dot(o, a, b) / dis(o, a) / dis(o, b);
}

int jarvis(Point *p, int n, int *ch) {
    int d, i, o, s, l, t;
    d = 0;
    for (i = 0; i < n; i++) {
        if (p[i].x < p[d].x || (p[i].x == p[d].x && p[i].y < p[d].y)) {
            d = i;
        }
    }
    l = s = ch[0] = d;
    d = 1;
    do {
        o = l;
        for (i = 0; i < n; i++) {
            t = sig(cross(&p[o], &p[l], &p[i]));
            if (t > 0 || (t == 0 && btw(&p[l], &p[o], &p[i]) <= 0)) {
                l = i;
            }
        }
        ch[d++] = l;
    } while (l != s);
    return d - 1;
}

int main() {
    memset(ang, 0, sizeof(ang));
    memset(ans, 0, sizeof(ans));
    int n, xx, yy;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &xx, &yy);
        P[i].x = xx;
        P[i].y = yy;
    }
    if (n == 2) {
        puts("0.5");
        puts("0.5");
    } else {
        int m = jarvis(P, n, ch);
        double sum = 0;
        if (m == 2) {
            ans[ch[0]] = 0.5;
            ans[ch[1]] = 0.5;
        } else {
            for (int i = 0; i < m; i++) {
                ang[ch[i]] = PI - acos(cos_angle(&P[ch[i]], &P[ch[(i - 1 + m) % m]], &P[ch[(i + 1) % m]]));
            }
            for (int i = 0; i < n; i++) {
                ans[i] = ang[i] / 2.0 / PI;
            }
        }
        for (int i = 0; i < n; i++) {
            printf("%.20f\n", ans[i]);
        }
    }
    return 0;
}

// <END-OF-CODE>
