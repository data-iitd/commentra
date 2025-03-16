#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>

#define MAX(a, b) ((a) > (b)? (a) : (b))
#define MIN(a, b) ((a) < (b)? (a) : (b))
#define ABS(a) ((a) < 0? -(a) : (a))
#define SQR(a) ((a) * (a))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FORE(i, a, b) for (int i = (a); i <= (b); i++)
#define FOREACH(i, a) for (typeof((a).begin()) i = (a).begin(); i!= (a).end(); i++)
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define REVERSE(a) reverse(ALL(a))
#define UNIQUE(a) (a).resize(unique(ALL(a)) - (a).begin())
#define SZ(a) ((int)(a).size())
#define CONTAINS(a, x) ((a).find(x)!= (a).end())
#define SQR(x) ((x) * (x))
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
#define MOD 1000000007

int main() {
	int n, x;
	scanf("%d %d", &n, &x);

	int A[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	qsort(A, n, sizeof(int), cmpfunc);

	int ans = 0;
	int i = 0, j = 0;
	while (j < n) {
		if (x >= A[i]) {
			ans++;
			x -= A[i];
			i++;
		} else {
			j++;
		}
	}

	if (x > 0 && n == ans) {
		ans--;
	}

	printf("%d\n", ans);
}

