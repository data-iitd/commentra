#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define PI acos(-1.0)

int sig(double d) {
    return fabs(d) < 1e-8 ? 0 : d < 0 ? -1 : 1;
}

typedef struct {
    double x, y;
    double k;
} Point;

void setPoint(Point *p, double x, double y) {
    p->x = x;
    p->y = y;
}

double mod(Point p) {
    return sqrt(p.x * p.x + p.y * p.y);
}

double mod_pow(Point p) {
    return p.x * p.x + p.y * p.y;
}

void outputPoint(Point p) {
    printf("x = %f, y = %f\n", p.x, p.y);
}

int comparePoint(Point a, Point b) {
    return sig(a.x - b.x) != 0 ? a.x < b.x : sig(a.y - b.y) < 0;
}

double dot(Point o, Point a, Point b) {
    return (a.x - o.x) * (b.x - o.x) + (a.y - o.y) * (b.y - o.y);
}

double dotProduct(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

double cross(Point o, Point a, Point b) {
    return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}

int between(Point x, Point a, Point b) {
    return sig(dot(x, a, b));
}

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double cosine(Point o, Point a, Point b) {
    return dot(o, a, b) / distance(o, a) / distance(o, b);
}

int jarvis(Point *p, int n, int *ch) {
    int d, i, o, s, l, t;
    for (d = i = 0; i < n; i++)
        if (comparePoint(p[i], p[d]))
            d = i;
    l = s = *ch = d;
    d = 1;
    do {
        o = l;
        for (i = 0; i < n; i++)
            if ((t = sig(cross(p[o], p[l], p[i]))) > 0 || (t == 0 && between(p[l], p[o], p[i]) <= 0))
                l = i;
        ch[d++] = l;
    } while (l != s);
    return d - 1;
}

int main() {
    Point P[110];
    double ang[110], ans[110];
    int ch[110];
    memset(ang, 0, sizeof(ang));
    memset(ans, 0, sizeof(ans));
    int n, xx, yy;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &xx, &yy);
        setPoint(&P[i], xx, yy);
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
                ang[ch[i]] = PI - acos(cosine(P[ch[i]], P[ch[(i - 1 + m) % m]], P[ch[(i + 1) % m]]));
            }
            for (int i = 0; i < n; i++) {
                ans[i] = ang[i] / 2. / PI;
            }
        }
        for (int i = 0; i < n; i++) {
            printf("%.20f\n", ans[i]);
        }
    }
    return 0;
}
