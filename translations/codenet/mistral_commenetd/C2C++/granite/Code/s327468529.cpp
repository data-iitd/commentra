

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

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

typedef uint64_t ull;
typedef  int64_t sll;
#define N_MAX 1048576

#ifdef __cplusplus
typedef std::array<ull, 3> arr3;
typedef std::array<ull, 4> arr4;
#else
typedef struct {
	ull a, b, c, d;
} arr4;
typedef struct {
	ull a, b, c;
} arr3;
#endif

int main (int argc, char *argv[]) {
	int32_t i, j;

	// Initialize variables
	ull n, m;

	// Read input values
	scanf("%llu", &m);
	scanf("%llu%llu", &h, &w);
	scanf("%llu", &k, &n, &m);
	scanf("%llu%llu", &h, &w);
	scanf("%llu", &q);
	scanf("%lld%lld", &va, &vb, &vc, &vd);
	va--;
	vb--;
	scanf("%s", s);
	scanf("%s", t);
	scanf("%s", u);
	scanf("%llu", &k);
	scanf("%lld", &m);
	// Initialize arrays
	for (i = 0; i < n; i++) {
		scanf("%lld", &b[i]);
	}
	for (i = 0; i < m; i++) {
		scanf("%lld%lld", &xy[i].a, &xy[i].b);
		xy[i].a--;
		xy[i].b--;
	}
	for (i = 0; i < h; i++) {
		scanf("%lld", &table[i][j]);
		table[i][j]--;
	}
	for (i = 0; i < h; i++) {
		scanf("%s", s[i]);
	}
	// Read input value
	scanf("%llu", &q);

	// Call the solve function
	solve();

	// Terminate the program
	return 0;
}

int32_t solve () {
	sll i, j, ki, li;
	// Initialize variables
	ull result = 0;
	double dresult = 0;
	ull maybe = 0;
	sll sum = 0;
	sll item;
	sll *dpcell;

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
		printf("%llu\n", result);
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