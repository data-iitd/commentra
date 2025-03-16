#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <array>
#include <cmath>
#include <time.h>

#define BIG 2000000007
#define VERYBIG 20000000000000007LL
#define MOD 1000000007
#define FOD 998244353
#define N_MAX 1048576

#define M_PI 3.14159265358979323846264338327950

using namespace std;

typedef uint64_t ull;
typedef int64_t sll;

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

sll n, m;
sll h, w;
sll k;
sll q;
sll va, vb, vc, vd, ve, vf;
ull ua, ub, uc, ud, ue, uf;
long double vra, vrb, vrc;
double vda, vdb, vdc;
char ch, dh;

ull umin(ull x, ull y) { return x < y ? x : y; }
ull umax(ull x, ull y) { return x > y ? x : y; }
sll smin(sll x, sll y) { return x < y ? x : y; }
sll smax(sll x, sll y) { return x > y ? x : y; }
ull gcd(ull x, ull y) { return y == 0 ? x : gcd(y, x % y); }
ull bitpow(ull a, ull x, ull modulo) { ull result = 1; while (x > 0) { if (x % 2 != 0) result = (result * a) % modulo; a = (a * a) % modulo; x /= 2; } return result; }
ull divide(ull a, ull b, ull modulo) { return (a * bitpow(b, modulo - 2, modulo)) % modulo; }
ull udiff(ull a, ull b) { return a > b ? a - b : b - a; }
int bitcount(ull n) { int result = 0; while (n > 0) { result += n & 1; n >>= 1; } return result; }

int32_t pullcomp(const void *left, const void *right) { return (*(sll*)left - *(sll*)right); }
int32_t prevcomp(const void *left, const void *right) { return (*(sll*)right - *(sll*)left); }
int32_t psllcomp(const void *left, const void *right) { return (*(sll*)left - *(sll*)right); }
int32_t pcharcomp(const void *left, const void *right) { return (*(char*)left - *(char*)right); }
int32_t pdoublecomp(const void *left, const void *right) { return (*(double*)left > *(double*)right) - (*(double*)left < *(double*)right); }
int32_t pstrcomp(const void *left, const void *right) { return strcmp(*(const char**)left, *(const char**)right); }
int32_t phwllABcomp(const void *left, const void *right) { return (*(hwll*)left).a - (*(hwll*)right).a; }
int32_t phwllREVcomp(const void *left, const void *right) { return (*(hwll*)right).a - (*(hwll*)left).a; }
int32_t ptriplecomp(const void *left, const void *right) { return (*(tuple<sll, sll, sll>*)left).get<0>() - (*(tuple<sll, sll, sll>*)right).get<0>(); }
int32_t ptripleREVcomp(const void *left, const void *right) { return (*(tuple<sll, sll, sll>*)right).get<0>() - (*(tuple<sll, sll, sll>*)left).get<0>(); }
int32_t ptripleCABcomp(const void *left, const void *right) { return (*(tuple<sll, sll, sll>*)left).get<1>() - (*(tuple<sll, sll, sll>*)right).get<1>(); }
int32_t pquadcomp(const void *left, const void *right) { return (*(tuple<sll, sll, sll, sll>*)left).get<0>() - (*(tuple<sll, sll, sll, sll>*)right).get<0>(); }
int32_t pfracomp(const void *left, const void *right) { return (*(pair<sll, sll>*)left).first - (*(pair<sll, sll>*)right).first; }
bool isinrange(sll left, sll x, sll right) { return left <= x && x <= right; }
bool isinrange_soft(sll left, sll x, sll right) { return left <= x && x <= right; }
void sw(sll *l, sll *r) { sll t = *l; *l = *r; *r = t; }
ull ncr(sll n, sll r, ull m) { ull result = 1; for (sll i = 1; i <= r; i++) result = result * (n - i + 1) / i; return result % m; }

int32_t main(int argc, char *argv[]) {
	int32_t i, j;

	n = 4;
	m = 0;

	scanf("%s", s);

	for (i = 0; i < n; i++) {
		scanf("%lld", &b[i]);
	}

	for (i = 0; i < m; i++) {
		scanf("%lld", &c[i]);
	}

	scanf("%llu", &q);

	solve();

	return 0;
}

int32_t solve() {
	sll i, j, ki, li;
	sll result = 1;
	sll cnt[3] = {0};
	sll pcnt = 0;
	string s;

	for (i = 0; i < n * 3; i++) {
		char v;
		cin >> v;
		switch (v) {
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
			result *= (cnt[(v + 1) % 3] * cnt[(v + 2) % 3] % FOD);
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
	}

	for (i = 1; i <= n; i++) {
		result = (result * i) % FOD;
	}

	cout << result << endl;

	return 0;
}

