
// Preprocessor directives and header file inclusions
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <set>
#include <map>
#include <string>
#include <functional>
#include <array>

// Constant and macro definitions
#define BIG 2000000007
#define VERYBIG 20000000000000007LL
#define MOD 1000000007
#define FOD  998244353
typedef uint64_t ull;
typedef  int64_t sll;
#define N_MAX 1048576

// Data type and structure definitions
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

// Variable declarations
sll n, m;
sll h, w;
sll k;
sll q;
sll va, vb, vc, vd, ve, vf;
ull ua, ub, uc, ud, ue, uf;
long double vra, vrb, vrc;
double vda, vdb, vdc;
char ch, dh;

// Helper function declarations
ull umin (ull x, ull y);
ull umax (ull x, ull y);
sll smin (sll x, sll y);
sll smax (sll x, sll y);
ull gcd (ull x, ull y);
ull bitpow (ull a, ull x, ull modulo);
ull divide (ull a, ull b, ull modulo);
ull udiff (ull a, ull b);
int bitcount (ull n);

// Function declarations
int32_t pullcomp (const void *left, const void *right);
int32_t prevcomp(const void *left, const void *right);
int32_t psllcomp(const void *left, const void *right);
int32_t pcharcomp(const void *left, const void *right);
int32_t pdoublecomp(const void *left, const void *right);
int32_t pstrcomp (const void *left, const void *right);
int32_t phwllABcomp(const void *left, const void *right);
int32_t phwllREVcomp(const void *left, const void *right);
int32_t ptriplecomp(const void *left, const void *right);
int32_t ptripleREVcomp(const void *left, const void *right);
int32_t ptripleCABcomp(const void *left, const void *right);
int32_t pquadcomp (const void *left, const void *right);
int32_t pfracomp (const void *left, const void *right);
bool isinrange (sll left, sll x, sll right);
bool isinrange_soft (sll left, sll x, sll right);
void sw (sll *l, sll *r);
ull ncr (sll n, sll r, ull m);

// Main function implementation
int32_t main (int argc, char *argv[]) {
	int32_t i, j;

	// Initialize variables
	n = 4;
	m = 0;

	// Read input values
	// scanf("%llu", &m);
	// scanf("%llu%llu", &h, &w);
	// scanf("%llu", &k, &n, &m);
	// scanf("%llu%llu", &h, &w);
	// scanf("%llu", &q);
	// scanf("%lld%lld", &va, &vb, &vc, &vd);
	// va--;
	// vb--;
	scanf("%s", s);
	// scanf("%s", t);
	// scanf("%s", u);
	// scanf("%llu", &k);
	// scanf("%lld", &m);
	// Initialize arrays
	// for (i = 0; i < n; i++) {
	// 	// scanf("%lld", &a[i]);
	// 	scanf("%lld", &d[i]);
	// }
	// scanf("%llu", &q);
	for (i = 0; i < N_MAX; i++) {
		a[i] = 0;
		b[i] = 0;
		c[i] = 0;
	}

	// Read input values
	for (i = 0; i < n; i++) {
		// scanf("%lld", &b[i]);
		// b[i]--;
		// scanf("%lld", &c[i]);
		// scanf("%lld", &d[i]);
		// c[i]--;
		// d[i]--;
		scanf("%lld", &b[i]);
	}

	// Read input values
	for (i = 0; i < m; i++) {
		// scanf("%lld%lld", &xy[i].a, &xy[i].b);
		scanf("%lld", &c[i]);
		// xy[i].a--;
		// xy[i].b--;
	}

	// Read input values
	for (i = 0; i < h; i++) {
		// scanf("%lld", &table[i][j]);
		// table[i][j]--;
	}

	// for (i = 0; i < h; i++) {
	// 	scanf("%s", s[i]);
	// }
	// Read input value
	scanf("%llu", &q);

	// Call the solve function
	solve();

	// Terminate the program
	return 0;
}

// Main function implementation
int32_t solve () {
	sll i, j, ki, li;
	// Initialize variables
	// ull result = 0;
	sll result = 0;
	double dresult = 0;
	// ull maybe = 0;
	sll maybe = 0;
	// ull sum = 0;
	sll sum = 0;
	sll item;
	sll *dpcell;

	// for (i = 0; i < h; i++) {
	// 	for (j = 0; j < w; j++) {
	// 		x[i][j] = (table[i][j] - 1) / w;
	// 	}
	// }


	result = 1;
	for (i = 0; i < n * 3; i++) {
		ull v;
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
		// if (cnt[(v + 1) % 3] && cnt[(v + 2) % 3]) {
		// 	result *= (cnt[(v + 1) % 3] * cnt[(v + 2) % 3] % FOD);
		// 	pcnt--;
		// 	result %= FOD;
		// 	cnt[(v + 1) % 3]--;
		// 	cnt[(v + 2) % 3]--;
		// } else {

		// 	if ((cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) > cnt[v]) {
		// 		result *= (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) - cnt[v];
		// 		result %= FOD;
		// 		pcnt++;
		// 	}

		// 	cnt[v]++;
		// }
		if (cnt[(v + 1) % 3] && cnt[(v + 2) % 3]) {
			result *= pcnt;
			pcnt--;
			result %= FOD;
			cnt[(v + 1) % 3]--;
			cnt[(v + 2) % 3]--;
		} else {

			if ((cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) > cnt[v]) {
				result *= (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) - cnt[v];
				result %= FOD;
				pcnt++;
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

