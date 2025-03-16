
#if 0
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define BIG 2000000007
#define VERYBIG 20000000000000007LL
#define MOD 1000000007
#define FOD  998244353
#define N_MAX 1048576

#ifdef __cplusplus
#include <queue>
#include <stack>
#include <tuple>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <array>

using std::queue;
using std::priority_queue;
using std::stack;
using std::tuple;
using std::set;
using std::map;
using std::vector;
using std::greater;
using std::pair;
using std::string;
using std::get;

template <typename T, typename U>
pair<T, U> operator+(pair<T, U> l, pair<T, U> r) {
	return pair<T, U>(l.first + r.first, l.second + r.second);
}

#endif

#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950
#endif

typedef struct {
	sll a;
	sll b;
} hwll;

typedef struct {
	sll a;
	sll b;
	sll c;
} hwllc;

typedef struct {
	double a;
	double b;
} hwreal;

typedef struct {
	sll a;
	sll b;
	sll c;
} triple;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
} quad;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
} frac;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
} penta;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
} hexa;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
} hepta;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
} octa;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
} nona;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
} deca;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
	sll l;
} undeca;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
	sll l;
	sll m;
} duodeca;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
	sll l;
	sll m;
	sll n;
} tredeca;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
	sll l;
	sll m;
	sll n;
	sll o;
} quattuordeca;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
	sll l;
	sll m;
	sll n;
	sll o;
	sll p;
} quinquadeca;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
	sll l;
	sll m;
	sll n;
	sll o;
	sll p;
	sll q;
} sexadeca;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
	sll l;
	sll m;
	sll n;
	sll o;
	sll p;
	sll q;
	sll r;
} septemdeca;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
	sll l;
	sll m;
	sll n;
	sll o;
	sll p;
	sll q;
	sll r;
	sll s;
} octodeca;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
	sll l;
	sll m;
	sll n;
	sll o;
	sll p;
	sll q;
	sll r;
	sll s;
	sll t;
} novemdeca;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
	sll l;
	sll m;
	sll n;
	sll o;
	sll p;
	sll q;
	sll r;
	sll s;
	sll t;
	sll u;
} viginti;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
	sll l;
	sll m;
	sll n;
	sll o;
	sll p;
	sll q;
	sll r;
	sll s;
	sll t;
	sll u;
	sll v;
} unviginti;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
	sll l;
	sll m;
	sll n;
	sll o;
	sll p;
	sll q;
	sll r;
	sll s;
	sll t;
	sll u;
	sll v;
	sll w;
} duoviginti;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
	sll l;
	sll m;
	sll n;
	sll o;
	sll p;
	sll q;
	sll r;
	sll s;
	sll t;
	sll u;
	sll v;
	sll w;
	sll x;
} tresviginti;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
	sll l;
	sll m;
	sll n;
	sll o;
	sll p;
	sll q;
	sll r;
	sll s;
	sll t;
	sll u;
	sll v;
	sll w;
	sll x;
	sll y;
} quattuorviginti;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
	sll l;
	sll m;
	sll n;
	sll o;
	sll p;
	sll q;
	sll r;
	sll s;
	sll t;
	sll u;
	sll v;
	sll w;
	sll x;
	sll y;
	sll z;
} quinquaviginti;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
	sll l;
	sll m;
	sll n;
	sll o;
	sll p;
	sll q;
	sll r;
	sll s;
	sll t;
	sll u;
	sll v;
	sll w;
	sll x;
	sll y;
	sll z;
	sll aa;
} sexaviginti;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
	sll l;
	sll m;
	sll n;
	sll o;
	sll p;
	sll q;
	sll r;
	sll s;
	sll t;
	sll u;
	sll v;
	sll w;
	sll x;
	sll y;
	sll z;
	sll aa;
	sll ab;
} septemviginti;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
	sll l;
	sll m;
	sll n;
	sll o;
	sll p;
	sll q;
	sll r;
	sll s;
	sll t;
	sll u;
	sll v;
	sll w;
	sll x;
	sll y;
	sll z;
	sll aa;
	sll ab;
	sll ac;
} octoviginti;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
	sll l;
	sll m;
	sll n;
	sll o;
	sll p;
	sll q;
	sll r;
	sll s;
	sll t;
	sll u;
	sll v;
	sll w;
	sll x;
	sll y;
	sll z;
	sll aa;
	sll ab;
	sll ac;
	sll ad;
} novemviginti;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
	sll l;
	sll m;
	sll n;
	sll o;
	sll p;
	sll q;
	sll r;
	sll s;
	sll t;
	sll u;
	sll v;
	sll w;
	sll x;
	sll y;
	sll z;
	sll aa;
	sll ab;
	sll ac;
	sll ad;
	sll ae;
} triginta;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
	sll l;
	sll m;
	sll n;
	sll o;
	sll p;
	sll q;
	sll r;
	sll s;
	sll t;
	sll u;
	sll v;
	sll w;
	sll x;
	sll y;
	sll z;
	sll aa;
	sll ab;
	sll ac;
	sll ad;
	sll ae;
	sll af;
} quadraginta;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
	sll l;
	sll m;
	sll n;
	sll o;
	sll p;
	sll q;
	sll r;
	sll s;
	sll t;
	sll u;
	sll v;
	sll w;
	sll x;
	sll y;
	sll z;
	sll aa;
	sll ab;
	sll ac;
	sll ad;
	sll ae;
	sll af;
	sll ag;
} quinquaginta;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
	sll l;
	sll m;
	sll n;
	sll o;
	sll p;
	sll q;
	sll r;
	sll s;
	sll t;
	sll u;
	sll v;
	sll w;
	sll x;
	sll y;
	sll z;
	sll aa;
	sll ab;
	sll ac;
	sll ad;
	sll ae;
	sll af;
	sll ag;
	sll ah;
} sexaginta;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
	sll l;
	sll m;
	sll n;
	sll o;
	sll p;
	sll q;
	sll r;
	sll s;
	sll t;
	sll u;
	sll v;
	sll w;
	sll x;
	sll y;
	sll z;
	sll aa;
	sll ab;
	sll ac;
	sll ad;
	sll ae;
	sll af;
	sll ag;
	sll ah;
	sll ai;
} septuaginta;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
	sll l;
	sll m;
	sll n;
	sll o;
	sll p;
	sll q;
	sll r;
	sll s;
	sll t;
	sll u;
	sll v;
	sll w;
	sll x;
	sll y;
	sll z;
	sll aa;
	sll ab;
	sll ac;
	sll ad;
	sll ae;
	sll af;
	sll ag;
	sll ah;
	sll ai;
	sll aj;
} octoginta;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
	sll l;
	sll m;
	sll n;
	sll o;
	sll p;
	sll q;
	sll r;
	sll s;
	sll t;
	sll u;
	sll v;
	sll w;
	sll x;
	sll y;
	sll z;
	sll aa;
	sll ab;
	sll ac;
	sll ad;
	sll ae;
	sll af;
	sll ag;
	sll ah;
	sll ai;
	sll aj;
	sll ak;
} nonaginta;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
	sll l;
	sll m;
	sll n;
	sll o;
	sll p;
	sll q;
	sll r;
	sll s;
	sll t;
	sll u;
	sll v;
	sll w;
	sll x;
	sll y;
	sll z;
	sll aa;
	sll ab;
	sll ac;
	sll ad;
	sll ae;
	sll af;
	sll ag;
	sll ah;
	sll ai;
	sll aj;
	sll ak;
	sll al;
} decaginta;

typedef struct {
	sll a;
	sll b;
	sll c;
	sll d;
	sll e;
	sll f;
	sll g;
	sll h;
	sll i;
	sll j;
	sll k;
	sll l;
	sll m;
	sll n;
	s