#if 0
cat <<EOF >mistaken-paste
#endif
// thx Ebi-chan!

#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"
#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define BIG 2000000007
#define VERYBIG 20000000000000007LL

#define MOD 1000000007
#define FOD  998244353
typedef long long int64_t;
typedef unsigned long long uint64_t;

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
	int64_t a;
	int64_t b;
} hwll;

typedef struct {
	int64_t a;
	int64_t b;
	int64_t c;
} hwllc;

typedef struct {
	hwll a;
	hwll b;
} linell;

typedef struct {
	double a;
	double b;
} hwreal;

int64_t n, m;
int64_t h, w;
int64_t k;
int64_t q;
int64_t va, vb, vc, vd, ve, vf;
uint64_t ua, ub, uc, ud, ue, uf;
long double vra, vrb, vrc;
double vda, vdb, vdc;
char ch, dh;

uint64_t umin (uint64_t x, uint64_t y) {
	return (x < y)? x : y;
}

uint64_t umax (uint64_t x, uint64_t y) {
	return (x > y)? x : y;
}

int64_t smin (int64_t x, int64_t y) {
	return (x < y)? x : y;
}

int64_t smax (int64_t x, int64_t y) {
	return (x > y)? x : y;
}

uint64_t gcd (uint64_t x, uint64_t y) {
	if (y == 0) {
		return x;
	} else {
		return gcd(y, x % y);
	}
}

uint64_t bitpow (uint64_t a, uint64_t x, uint64_t modulo) {
	uint64_t result = 1;
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

uint64_t divide (uint64_t a, uint64_t b, uint64_t modulo) {
	return (a * bitpow(b, modulo - 2, modulo)) % modulo;
}

uint64_t udiff (uint64_t a, uint64_t b) {
	if (a >= b) {
		return a - b;
	} else {
		return b - a;
	}
}

int64_t sdiff (int64_t a, int64_t b) {
	if (a >= b) {
		return a - b;
	} else {
		return b - a;
	}
}

int bitcount (uint64_t n) {
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

// int32_t pullcomp (const void *left, const void *right) {
// 	ull l = *(ull*)left;
// 	ull r = *(ull*)right;
// 	if (l < r) {
// 		return -1;
// 	}
// 	if (l > r) {
// 		return +1;
// 	}
// 	return 0;
// }
BEGCMP(pullcomp){
	DEFLR(uint64_t);
	CMPRET(l, r);
	return 0;
}
BEGCMP(prevcomp){
	DEFLR(int64_t);
	CMPRET(r, l);
	return 0;
}
BEGCMP(psllcomp){
	DEFLR(int64_t);
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

	int64_t ac = phwllABcomp(&(l.a), &(r.a));
	if (ac) return ac;
	int64_t bc = phwllABcomp(&(l.b), &(r.b));
	if (bc) return bc;

	return 0;
}
int32_t pfracomp (const void *left, const void *right) {
	hwllc l = *(hwllc*)left;
	hwllc r = *(hwllc*)right;

	CMPRET(l.a * r.b, l.b * r.a);
	return 0;
}
bool isinrange (int64_t left, int64_t x, int64_t right) {
	return (left <= x && x <= right);
}

bool isinrange_soft (int64_t left, int64_t x, int64_t right) {
	return (left <= x && x <= right) || (left >= x && x >= right);
}

void sw (int64_t *l, int64_t *r) {
	if (*l == *r) return;
	int64_t t = *l;
	*l = *r;
	*r = t;
}

uint64_t frac[N_MAX * 3], invf[N_MAX * 3];
uint64_t ncr (int64_t n, int64_t r, uint64_t m) {
	if (n < 0 || r < 0 || n < r) return 0;
	return frac[n] * (invf[r] * invf[n - r] % m) % m;
}

int64_t a[N_MAX + 5];
// ull a[N_MAX + 5];
// sll a[3001][3001];
int64_t b[N_MAX + 5];
// ull b[N_MAX + 5];
// sll b[3001][3001];
int64_t c[N_MAX + 5];
int64_t d[N_MAX + 5];
int64_t e[N_MAX * 4];
char s[N_MAX + 1];
// char s[3010][3010];
char t[N_MAX + 1];
// char t[3010][3010];
char u[N_MAX + 1];
hwll xy[N_MAX + 5];
hwllc tup[N_MAX + 5];
int64_t table[3005][3005];
uint64_t gin[N_MAX];
// here we go


int64_t cnt[3], pcnt;
uint64_t x[3005][3005];


uint64_t solve () {
	int64_t i, j, ki, li;
	// ull result = 0;
	int64_t result = 0;
	double dresult = 0;
	// ull maybe = 0;
	int64_t maybe = 0;
	// ull sum = 0;
	int64_t sum = 0;
	int64_t item;
	int64_t *dpcell;

	// for (i = 0; i < h; i++) {
	// 	for (j = 0; j < w; j++) {
	// 		x[i][j] = (table[i][j] - 1) / w;
	// 	}
	// }


	result = 1;
	for (i = 0; i < n * 3; i++) {
		uint64_t v;
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
		// printf("%llu %llu %llu\n", cnt[0], cnt[1], cnt[2]);

		if (cnt[(v + 1) % 3] && cnt[(v + 2) % 3]) {
			// result *= (cnt[(v + 1) % 3] * cnt[(v + 2) % 3] % FOD);
			result *= pcnt;
			pcnt--;
			result %= FOD;
			cnt[(v + 1) % 3]--;
			cnt[(v + 2) % 3]--;
		} else {

			if ((cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) > cnt[v]) {
				// printf("*%llu\n", (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) - cnt[v]);
				result *= (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) - cnt[v];
				result %= FOD;
				pcnt++;
				// printf("pcnt: %llu\n", pcnt);
			}

			cnt[v]++;
		}
		// printf("%llu\n", result);
	}

	for (i = 1; i <= n; i++) {
		result = (result * i) % FOD;
	}

	printf("%lld\n", result);
	// printf("%.15f\n", dresult);
	// puts(s);

	return 0;

	success:
	// puts("YES");
	puts("Yes");
	// printf("%llu\n", result);
	// puts("0");
	// puts("First");
	return 0;

	fail:
	// puts("NO");
	// puts("No");
	// puts("0");
	puts("-1");
	// puts("-1 -1 -1");
	// puts("Second");
	return 1;
}

int32_t main (int argc, char *argv[]) {
	int32_t i, j;

	n = 4;
	m = 0;

	// scanf("%llu", &m);
	// scanf("%llu%llu", &h, &w);
	scanf("%lld", &n, &m);
	// scanf("%llu", &k, &n, &m);
	// scanf("%llu%llu", &h, &w);
	// scanf("%llu", &q);
	// scanf("%lld%lld", &va, &vb, &vc, &vd);
	// va--;
	// vb--;
	// scanf("%llu%llu%llu%llu", &ua, &ub, &uc, &ud, &ue);
	scanf("%s", s);
	// scanf("%s", t);
	// scanf("%s", u);
	// scanf("%llu", &k);
	// scanf("%lld", &m);
	// for (i = 0; i < n; i++) {
	// 	// scanf("%lld", &a[i]);
	// 	scanf("%lld", &d[i]);
	// }
	// scanf("%llu", &q);
	for (i = 0; i < 0; i++) {
		// scanf("%lld