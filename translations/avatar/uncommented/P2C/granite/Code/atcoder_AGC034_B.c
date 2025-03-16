
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    int x, y;
} point;

typedef struct {
    int x, y, z;
} point3d;

typedef struct {
    ll x, y;
} point64;

typedef struct {
    ll x, y, z;
} point3d64;

typedef struct {
    double x, y;
} pointf;

typedef struct {
    double x, y, z;
} point3df;

typedef struct {
    double x, y, z, w;
} point4df;

typedef struct {
    char x[100000];
} str;

typedef struct {
    int x[100000];
} arr;

typedef struct {
    int x, y;
} pair;

typedef struct {
    int x, y, z;
} triple;

typedef struct {
    int x, y, z, w;
} quadruple;

typedef struct {
    int x, y, z, w, v;
} quintuple;

typedef struct {
    int x, y, z, w, v, u;
} sextuple;

typedef struct {
    int x, y, z, w, v, u, t;
} septuple;

typedef struct {
    int x, y, z, w, v, u, t, s;
} octuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q;
} nonuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r;
} decuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p;
} undecuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o;
} duodecuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n;
} tredecuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m;
} quattuordecuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l;
} quindecuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k;
} sexdecuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j;
} septendecuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i;
} octodecuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h;
} novemdecuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g;
} vigintuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f;
} centiquinquaginttuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e;
} centiquinquagint quadruple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d;
} centiquinquagint quintuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c;
} centiquinquagint sextuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b;
} centiquinquagint septuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a;
} centiquinquagint octuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z;
} centiquinquagint nonuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y;
} centiquinquagint decuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x;
} centiquinquagint undecuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w;
} centiquinquagint duodecuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v;
} centiquinquagint tredecuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u;
} centiquinquagint quattuordecuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t;
} centiquinquagint quindecuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s;
} centiquinquagint sexdecuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q;
} centiquinquagint septendecuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r;
} centiquinquagint octodecuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p;
} centiquinquagint novemdecuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o;
} centiquinquagint vigintuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n;
} centiquinquagint centiquinquagint quadruple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m;
} centiquinquagint centiquinquagint quintuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l;
} centiquinquagint centiquinquagint sextuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k;
} centiquinquagint centiquinquagint septuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j;
} centiquinquagint centiquinquagint octuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i;
} centiquinquagint centiquinquagint nonuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h;
} centiquinquagint centiquinquagint decuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g;
} centiquinquagint centiquinquagint septuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f;
} centiquinquagint centiquinquagint octuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e;
} centiquinquagint centiquinquagint nonuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d;
} centiquinquagint centiquinquagint decuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c;
} centiquinquagint centiquinquagint septuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b;
} centiquinquagint centiquinquagint octuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a;
} centiquinquagint centiquinquagint nonuple;

typedef struct {
    int x, y, z, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, z, y, x, w, v, u, t, s, q, r, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a