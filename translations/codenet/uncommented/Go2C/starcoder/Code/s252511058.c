#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>

#define N 100000

typedef struct {
	int x, l, r;
} point;

int cmp(const void *a, const void *b) {
	point *p1 = (point *)a;
	point *p2 = (point *)b;
	return p1->r - p2->r;
}

int main() {
	point points[N];
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &points[i].x);
		int L;
		scanf("%d", &L);
		points[i].l = points[i].x - L;
		points[i].r = points[i].x + L;
	}
	qsort(points, N, sizeof(point), cmp);
	int start = points[0].r;
	int ans = 1;
	for (int i = 0; i < N; i++) {
		if (points[i].l < start) continue;
		start = points[i].r;
		ans++;
	}
	printf("%d\n", ans);
}

