#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <array>
#include <cmath>
#include <time.h>

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

#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950
#endif

typedef struct {
	long long a;
	long long b;
} hwll;

typedef struct {
	long long a;
	long long b;
	long long c;
} hwllc;

typedef struct {
	hwll a;
	hwll b;
} linell;

typedef struct {
	double a;
	double b;
} hwreal;

long long n, m;
long long h, w;
long long k;
long long q;
long long va, vb, vc, vd, ve, vf;
unsigned long long ua, ub, uc, ud, ue, uf;
long double vra, vrb, vrc;
double vda, vdb, vdc;
char ch, dh;

unsigned long long umin (unsigned long long x, unsigned long long y) {
	return (x < y) ? x : y;
}

unsigned long long umax (unsigned long long x, unsigned long long y) {
	return (x > y) ? x : y;
}

long long smin (long long x, long long y) {
	return (x < y) ? x : y;
}

long long smax (long long x, long long y) {
	return (x > y) ? x : y;
}

unsigned long long gcd (unsigned long long x, unsigned long long y) {
	if (y == 0) {
		return x;
	} else {
		return gcd(y, x % y);
	}
}

unsigned long long bitpow (unsigned long long a, unsigned long long x, unsigned long long modulo) {
	unsigned long long result = 1;
	while (x) {
		if (x & 1) {
			result *= a;
			result %= modulo;
		}
		x /= 2;
		a = (a * a) % modulo;
	}
	return result;
}

unsigned long long divide (unsigned long long a, unsigned long long b, unsigned long long modulo) {
	return (a * bitpow(b, modulo - 2, modulo)) % modulo;
}

unsigned long long udiff (unsigned long long a, unsigned long long b) {
	if (a >= b) {
		return a - b;
	} else {
		return b - a;
	}
}

long long sdiff (long long a, long long b) {
	if (a >= b) {
		return a - b;
	} else {
		return b - a;
	}
}

int bitcount (unsigned long long n) {
	int result = 0;
	while (n) {
		if (n & 1) result++;
		n /= 2;
	}
	return result;
}

#define BEGCMP(NAME) int32_t NAME (const void *left, const void *right)
#define DEFLR(TYPE) TYPE l=*(TYPE*)left,r=*(TYPE*)right
#define CMPRET(L, R) if((L)<(R))return-1;if((L)>(R))return+1

BEGCMP(pullcomp){
	DEFLR(unsigned long long);
	CMPRET(l, r);
	return 0;
}
BEGCMP(prevcomp){
	DEFLR(long long);
	CMPRET(r, l);
	return 0;
}
BEGCMP(psllcomp){
	DEFLR(long long);
	CMPRET(l, r);
	return 0;
}
BEGCMP(pcharcomp){
	DEFLR(char);
	CMPRET(l, r);
	return 0;
}
BEGCMP(pdoublecomp){
	DEFLR(double);
	CMPRET(l, r);
	return 0;
}

int32_t pstrcomp (const void *left, const void *right) {
	char* l = *(char**)left;
	char* r = *(char**)right;

	return strcmp(l, r);
}

BEGCMP(phwllABcomp){
	DEFLR(hwll);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	return 0;
}
BEGCMP(phwllREVcomp){
	DEFLR(hwll);
	CMPRET(l.b, r.b);
	CMPRET(l.a, r.a);
	return 0;
}
BEGCMP(ptriplecomp){
	DEFLR(hwllc);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	CMPRET(l.c, r.c);
	return 0;
}
BEGCMP(ptripleREVcomp){
	DEFLR(hwllc);
	CMPRET(l.b, r.b);
	CMPRET(l.a, r.a);
	CMPRET(l.c, r.c);
	return 0;
}
BEGCMP(ptripleCABcomp){
	DEFLR(hwllc);
	CMPRET(l.c, r.c);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	return 0;
}
BEGCMP(phwrealcomp){
	DEFLR(hwreal);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	return 0;
}

int32_t pquadcomp (const void *left, const void *right) {
	linell l = *(linell*)left;
	linell r = *(linell*)right;

	long long ac = phwllABcomp(&(l.a), &(r.a));
	if (ac) return ac;
	long long bc = phwllABcomp(&(l.b), &(r.b));
	if (bc) return bc;

	return 0;
}
int32_t pfracomp (const void *left, const void *right) {
	hwllc l = *(hwllc*)left;
	hwllc r = *(hwllc*)right;

	CMPRET(l.a * r.b, l.b * r.a);
	return 0;
}
bool isinrange (long long left, long long x, long long right) {
	return (left <= x && x <= right);
}

bool isinrange_soft (long long left, long long x, long long right) {
	return (left <= x && x <= right) || (left >= x && x >= right);
}

void sw (long long *l, long long *r) {
	if (*l == *r) return;
	long long t = *l;
	*l = *r;
	*r = t;
}

unsigned long long frac[1048576 * 3], invf[1048576 * 3];
unsigned long long ncr (long long n, long long r, unsigned long long m) {
	if (n < 0 || r < 0 || n < r) return 0;
	return frac[n] * (invf[r] * invf[n - r] % m) % m;
}

long long a[1048576 + 5];
long long b[1048576 + 5];
long long c[1048576 + 5];
long long d[1048576 + 5];
long long e[1048576 * 4];
char s[1048576 + 1];
char t[1048576 + 1];
char u[1048576 + 1];
hwll xy[1048576 + 5];
hwllc tup[1048576 + 5];
long long table[3005][3005];
unsigned long long gin[1048576];

long long cnt[3], pcnt;
unsigned long long x[3005][3005];

unsigned long long solve () {
	long long i, j, ki, li;
	unsigned long long result = 0;
	long long maybe = 0;
	long long sum = 0;
	long long item;
	long long *dpcell;

	result = 1;
	for (i = 0; i < n * 3; i++) {
		unsigned long long v;
		switch (s[i]) {
		case 'R':
			v = 0;
			break;
		case 'G':
			v = 1;
			break;
		case 'B':
			v = 2;
			break;
		}
		if (cnt[(v + 1) % 3] && cnt[(v + 2) % 3]) {
			result *= (cnt[(v + 1) % 3] * cnt[(v + 2) % 3] % 998244353);
			result %= 998244353;
			cnt[(v + 1) % 3]--;
			cnt[(v + 2) % 3]--;
		} else {
			if ((cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) > cnt[v]) {
				result *= (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) - cnt[v];
				result %= 998244353;
				pcnt++;
			}
			cnt[v]++;
		}
	}

	for (i = 1; i <= n; i++) {
		result = (result * i) % 998244353;
	}

	std::cout << result << std::endl;

	return 0;
}

int32_t main (int argc, char *argv[]) {
	long long i, j;

	n = 4;
	m = 0;

	scanf("%lld", &m);
	scanf("%lld%lld", &h, &w);
	scanf("%lld", &n);
	scanf("%s", s);

	solve();

	return 0;
}
