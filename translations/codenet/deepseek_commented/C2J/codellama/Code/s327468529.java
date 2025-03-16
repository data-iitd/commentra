#if 0
cat <<EOF >mistaken-paste
#endif
// thx Ebi-chan!

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.Stack;
import java.util.Vector;

public class Main {
	// #define BIG 2000000007
	// #define VERYBIG 20000000000000007LL

	// #define MOD 1000000007
	// #define FOD  998244353
	// typedef uint64_t ull;
	// typedef  int64_t sll;

	// #define N_MAX 1048576

	// #ifndef M_PI
	// #define M_PI 3.14159265358979323846264338327950
	// #endif

	// typedef struct {
	// 	sll a;
	// 	sll b;
	// } hwll;

	// typedef struct {
	// 	sll a;
	// 	sll b;
	// 	sll c;
	// } hwllc;

	// typedef struct {
	// 	hwll a;
	// 	hwll b;
	// } linell;

	// typedef struct {
	// 	double a;
	// 	double b;
	// } hwreal;

	static long n, m;
	static long h, w;
	static long k;
	static long q;
	static long va, vb, vc, vd, ve, vf;
	static long ua, ub, uc, ud, ue, uf;
	static double vra, vrb, vrc;
	static double vda, vdb, vdc;
	static char ch, dh;

	// static ull umin (ull x, ull y) {
	// 	return (x < y) ? x : y;
	// }

	// static ull umax (ull x, ull y) {
	// 	return (x > y) ? x : y;
	// }

	// static sll smin (sll x, sll y) {
	// 	return (x < y) ? x : y;
	// }

	// static sll smax (sll x, sll y) {
	// 	return (x > y) ? x : y;
	// }

	// static ull gcd (ull x, ull y) {
	// 	if (y == 0) {
	// 		return x;
	// 	} else {
	// 		return gcd(y, x % y);
	// 	}
	// }

	// static ull bitpow (ull a, ull x, ull modulo) {
	// 	ull result = 1;
	// 	while (x) {
	// 		if (x & 1) {
	// 			result *= a;
	// 			result %= modulo;
	// 		}
	// 		x /= 2;
	// 		a = (a * a) % modulo;
	// 	}
	// 	return result;
	// }

	// static ull divide (ull a, ull b, ull modulo) {
	// 	return (a * bitpow(b, modulo - 2, modulo)) % modulo;
	// }

	// static ull udiff (ull a, ull b) {
	// 	if (a >= b) {
	// 		return a - b;
	// 	} else {
	// 		return b - a;
	// 	}
	// }

	// static sll sdiff (sll a, sll b) {
	// 	if (a >= b) {
	// 		return a - b;
	// 	} else {
	// 		return b - a;
	// 	}
	// }

	// static int bitcount (ull n) {
	// 	int result = 0;
	// 	while (n) {
	// 		if (n & 1) result++;
	// 		n /= 2;
	// 	}
	// 	return result;
	// }

	// #define BEGCMP(NAME) int32_t NAME (const void *left, const void *right)
	// #define DEFLR(TYPE) TYPE l=*(TYPE*)left,r=*(TYPE*)right
	// #define CMPRET(L, R) if((L)<(R))return-1;if((L)>(R))return+1

	// // int32_t pullcomp (const void *left, const void *right) {
	// // 	ull l = *(ull*)left;
	// // 	ull r = *(ull*)right;
	// // 	if (l < r) {
	// // 		return -1;
	// // 	}
	// // 	if (l > r) {
	// // 		return +1;
	// // 	}
	// // 	return 0;
	// // }
	// BEGCMP(pullcomp){
	// 	DEFLR(ull);
	// 	CMPRET(l, r);
	// 	return 0;
	// }
	// BEGCMP(prevcomp){
	// 	DEFLR(sll);
	// 	CMPRET(r, l);
	// 	return 0;
	// }
	// BEGCMP(psllcomp){
	// 	DEFLR(sll);
	// 	CMPRET(l, r);
	// 	return 0;
	// }
	// BEGCMP(pcharcomp){
	// 	DEFLR(char);
	// 	CMPRET(l, r);
	// 	return 0;
	// }
	// BEGCMP(pdoublecomp){
	// 	DEFLR(double);
	// 	CMPRET(l, r);
	// 	return 0;
	// }

	// int32_t pstrcomp (const void *left, const void *right) {
	// 	char* l = *(char**)left;
	// 	char* r = *(char**)right;

	// 	return strcmp(l, r);
	// }

	// BEGCMP(phwllABcomp){
	// 	DEFLR(hwll);
	// 	CMPRET(l.a, r.a);
	// 	CMPRET(l.b, r.b);
	// 	return 0;
	// }
	// BEGCMP(phwllREVcomp){
	// 	DEFLR(hwll);
	// 	CMPRET(l.b, r.b);
	// 	CMPRET(l.a, r.a);
	// 	return 0;
	// }
	// BEGCMP(ptriplecomp){
	// 	DEFLR(hwllc);
	// 	CMPRET(l.a, r.a);
	// 	CMPRET(l.b, r.b);
	// 	CMPRET(l.c, r.c);
	// 	return 0;
	// }
	// BEGCMP(ptripleREVcomp){
	// 	DEFLR(hwllc);
	// 	CMPRET(l.b, r.b);
	// 	CMPRET(l.a, r.a);
	// 	CMPRET(l.c, r.c);
	// 	return 0;
	// }
	// BEGCMP(ptripleCABcomp){
	// 	DEFLR(hwllc);
	// 	CMPRET(l.c, r.c);
	// 	CMPRET(l.a, r.a);
	// 	CMPRET(l.b, r.b);
	// 	return 0;
	// }
	// BEGCMP(phwrealcomp){
	// 	DEFLR(hwreal);
	// 	CMPRET(l.a, r.a);
	// 	CMPRET(l.b, r.b);
	// 	return 0;
	// }

	// int32_t pquadcomp (const void *left, const void *right) {
	// 	linell l = *(linell*)left;
	// 	linell r = *(linell*)right;

	// 	sll ac = phwllABcomp(&(l.a), &(r.a));
	// 	if (ac) return ac;
	// 	sll bc = phwllABcomp(&(l.b), &(r.b));
	// 	if (bc) return bc;

	// 	return 0;
	// }
	// int32_t pfracomp (const void *left, const void *right) {
	// 	hwllc l = *(hwllc*)left;
	// 	hwllc r = *(hwllc*)right;

	// 	CMPRET(l.a * r.b, l.b * r.a);
	// 	return 0;
	// }
	// bool isinrange (sll left, sll x, sll right) {
	// 	return (left <= x && x <= right);
	// }

	// bool isinrange_soft (sll left, sll x, sll right) {
	// 	return (left <= x && x <= right) || (left >= x && x >= right);
	// }

	// void sw (sll *l, sll *r) {
	// 	if (*l == *r) return;
	// 	sll t = *l;
	// 	*l = *r;
	// 	*r = t;
	// }

	// ull frac[N_MAX * 3], invf[N_MAX * 3];
	// ull ncr (sll n, sll r, ull m) {
	// 	if (n < 0 || r < 0 || n < r) return 0;
	// 	return frac[n] * (invf[r] * invf[n - r] % m) % m;
	// }

	// sll a[N_MAX + 5];
	// // ull a[N_MAX + 5];
	// // sll a[3001][3001];
	// sll b[N_MAX + 5];
	// // ull b[N_MAX + 5];
	// // sll b[3001][3001];
	// sll c[N_MAX + 5];
	// sll d[N_MAX + 5];
	// sll e[N_MAX * 4];
	// char s[N_MAX + 1];
	// // char s[3010][3010];
	// char t[N_MAX + 1];
	// // char t[3010][3010];
	// char u[N_MAX + 1];
	// hwll xy[N_MAX + 5];
	// hwllc tup[N_MAX + 5];
	// sll table[3005][3005];
	// ull gin[N_MAX];
	// // here we go


	// sll cnt[3], pcnt;
	// ull x[3005][3005];


	// ull solve () {
	// 	sll i, j, ki, li;
	// 	// ull result = 0;
	// 	sll result = 0;
	// 	double dresult = 0;
	// 	// ull maybe = 0;
	// 	sll maybe = 0;
	// 	// ull sum = 0;
	// 	sll sum = 0;
	// 	sll item;
	// 	sll *dpcell;

	// 	// for (i = 0; i < h; i++) {
	// 	// 	for (j = 0; j < w; j++) {
	// 	// 		x[i][j] = (table[i][j] - 1) / w;
	// 	// 	}
	// 	// }


	// 	result = 1;
	// 	for (i = 0; i < n * 3; i++) {
	// 		ull v;
	// 		switch (s[i]) {
	// 		case 'R':
	// 			v = 0;
	// 			break;
	// 		case 'G':
	// 			v = 1;
	// 			break;
	// 		case 'B':
	// 			v = 2;
	